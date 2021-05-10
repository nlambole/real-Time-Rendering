#include <windows.h>
#include <stdio.h> // for FILE I/O

#include <gl\glew.h> // for GLSL extensions IMPORTANT : This Line Should be Before #include<gl\gl.h> and #include<gl\glu.h>

#include <gl/GL.h>

#include "vmath.h"
#include "NRL.h" // Icon
#include "Sphere.h"

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib,"Sphere.lib")


#define WIN_WIDTH 800
#define WIN_HEIGHT 600

int Width;
int Height;

using namespace vmath;

enum //PCNT
{
	NRL_ATTRIBUTE_POSITION = 0,
	NRL_ATTRIBUTE_COLOR,
	NRL_ATTRIBUTE_NORMAL,
	NRL_ATTRIBUTE_TEXTURE,
};

// Prototype of WndPRoc() declared GLobally
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Globall variable declarationns
FILE* gpFile = NULL;

HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;

DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };

bool gbActiveWindow = false;
bool gbEscapeKeyIsPressed = false;
bool gbFullscreen = false;

bool bLight = false;
int PressedDigit = 0;

GLuint modelMatrixUniform;
GLuint viewMatrixUniform;
GLuint projectionMatrixUniform;
GLuint mvpMatrixUniform;
GLuint LKeyPressedUniform;

//Light
GLuint LaUniform;
GLuint LdUniform;
GLuint LsUniform;
GLuint lightPositionUniform;

//Material
GLuint KaUniform; //Diffuse component of Material
GLuint KdUniform;
GLuint KsUniform;
GLfloat materialShininessUniform;

GLuint ShaderProgramObject;
//perVertex
GLuint VertexShaderObject_pV;
GLuint FragmentShaderObject_pV;
GLuint ShaderProgramObject_pV;

//perVertex
GLuint VertexShaderObject_pF;
GLuint FragmentShaderObject_pF;
GLuint ShaderProgramObject_pF;

GLuint vao_Sphere; // Vartex Array Object

GLuint vbo_Sphere;
GLuint vbo_Sphere_Position;
GLuint vbo_Sphere_Normals;
GLuint vbo_Sphere_Element;


mat4 PerspectiveProjectionMatrix;

//Shpere Vertex Position
float sphere_vertices[1146];
float sphere_normals[1146];
float sphere_textures[764];
unsigned short sphere_elements[2280];

GLfloat lightAmbient[] = { 0.0f, 0.0f, 0.1f, 1.0f };
GLfloat lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat lightPosition[] = { 100.0f, 100.0f, 100.0f, 1.0f };

GLfloat materialAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat materialDiffuse[] = { 0.5f, 0.2f, 0.7f, 1.0f };
GLfloat materialSpecular[] = { 0.7f, 0.7f , 0.7f, 1.0f };
GLfloat materialShininesss = 128.0f;
GLuint gNumVertices;
GLuint gNumElements;

//main()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Function Protoytpes
	void Initialize(void);
	void UnInitialize(void);
	void Display(void);
	

	//Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szClassName[] = TEXT("OpenGLPP");
	bool bDone = false;

	//Code
	//Create Log File
	if (fopen_s(&gpFile, "Log.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Log File Can Not Be Created\nExxiting..."),
			TEXT("Error"), MB_OK | MB_TOPMOST | MB_ICONSTOP);
	}
	else
	{
		fprintf(gpFile, "Log File Is Successfully Opened..\n");
	}

	//Initializing members og Struct WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;

	// Register Abouve Code
	RegisterClassEx(&wndclass);

	// Center of Window
	Width = (GetSystemMetrics(SM_CXSCREEN) / 2 - WIN_WIDTH / 2);
	Height = (GetSystemMetrics(SM_CYSCREEN) / 2 - WIN_HEIGHT / 2);

	// Create Window
	//Parallel to glutInitWindowSize(), glutInitWindowPosition() and glutCreateWindow() all Threee together
	hwnd = CreateWindow(szClassName, TEXT("perVertex_perFragment on Sphere : Nandlal Lambole"), WS_OVERLAPPEDWINDOW, Width, Height, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);

	ghwnd = hwnd;

	ShowWindow(hwnd, iCmdShow);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	Initialize(); //Call     

	//GAME Loop..
	while (bDone == false)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bDone = true;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			//Rendering FUnction
			Display(); //Call Display

			if (gbActiveWindow == true)
			{
				//Continuation to glutLeaveMainLoop();
				if (gbEscapeKeyIsPressed == true)

					bDone = true;
			}

		}
	}
	UnInitialize();
	return((int)msg.wParam);

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Function Prototype
	void ToggleFullScreen(void);
	void Resize(int, int);
	void UnInitialize(void);

	//Variable Declaration
	static WORD xMouse = NULL;
	static WORD yMouse = NULL;

	// Code
	switch (iMsg)
	{
	case WM_ACTIVATE:
		if (HIWORD(wParam) == 0)
			gbActiveWindow = true;
		else // if non-zero the window is not active
			gbActiveWindow = false;
		break;

	case WM_ERASEBKGND:
		return(0);

	case WM_SIZE: // Parallel to glutReshapeFunc()
		Resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_KEYDOWN: // Parallel to glutKeyboardFunc();
		switch (wParam)
		{
	
		case VK_ESCAPE: // case 27
			if (gbFullscreen == false)
			{
				ToggleFullScreen(); //Call
				gbFullscreen = true;
			}
			else
			{
				ToggleFullScreen();
				gbFullscreen = false;
			}
			break;

		default:
			break;
		}
		break;

	case WM_CHAR:
		switch (wParam)
		{
		case 'V':
		case 'v':
			bLight = true;
			PressedDigit = 0;
			break;

		case 'F':
		case 'f':
			
			bLight = true;
			PressedDigit = 1;
			break;

		case 'Q': // Quit
		case 'q': 
			if (gbEscapeKeyIsPressed == false)
				gbEscapeKeyIsPressed = true; 
			break;

		case 'L':
		case 'l':
			if (bLight == true)
			{
				//glEnable(GL_LIGHTING);
				bLight = false;
			}
			else
			{
				//glDisable(GL_LIGHTING);
				bLight = true;
			}
			break;
		default:
			break;
		}
		break;

	case WM_LBUTTONDOWN:
		break;

	case WM_CLOSE:
		UnInitialize();
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}

void ToggleFullScreen(void)
{
	//Local Variable Declarations
	MONITORINFO mi;

	//Code
	if (gbFullscreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			mi = { sizeof(MONITORINFO) };
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, (mi.rcMonitor.right - mi.rcMonitor.left), (mi.rcMonitor.bottom - mi.rcMonitor.top), SWP_NOZORDER | SWP_FRAMECHANGED);

			}
		}
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);

	}
}

//FUNCTION DEFINITIONS
void Initialize(void)
{
	//Function Prototypes
	void UnInitialize(void);
	void Resize(int, int);

	//Variable Declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex;

	//Code
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;

	ghdc = GetDC(ghwnd);

	//Choose a pixel format which best matches with that of 'pfd'
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	//set the pixel format chosen abouve
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == false)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	//create OpenGL rendering context
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}
	//make the rendering context created abouve as current n the current hdc.

	if (wglMakeCurrent(ghdc, ghrc) == false)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	//GLEW Initialization Code For GLSL (IMPORTANT : It Must Be Here. Means After Creating OprnGL Context But Before Using Any OpenGL Function)
	GLenum glew_error = glewInit();
	if (glew_error != GLEW_OK)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// **************************************
	//OpenGL related Log...System Information
	fprintf(gpFile, "1. OpenGL Vender : %s\n", glGetString(GL_VENDOR));
	fprintf(gpFile, "2. OpenGL Renderer : %s\n", glGetString(GL_RENDERER));
	fprintf(gpFile, "3. OpenGL Version : %s\n", glGetString(GL_VERSION));
	fprintf(gpFile, "4. GLSL (Graphics Lib. Shading Language) Version : %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	// OpenGL enable extensions
	GLint iNumExt;
	int i;
	glGetIntegerv(GL_NUM_EXTENSIONS, &iNumExt);
	for (i = 0; i < iNumExt; i++)
	{
		fprintf(gpFile, "OpenGL Extentions : %s\n", glGetStringi(GL_EXTENSIONS, i));

	}
	// End_Log *****************************

	//***********************************************_SHADERS_*********************************************************
	//_______________________________________________perVertex______________________________________________________

	// *** VERTEX SHADER per Vertex ***
		// Create Shader
	VertexShaderObject_pV = glCreateShader(GL_VERTEX_SHADER);

	// Provide source code to shader 
	const GLchar* vertexShaderSourceCode_pV =
		"#version 460 core" \
		"\n" \
		"in vec4 vPosition;" \
		"in vec3 vNormal;" \
		"uniform mat4 u_modelMatrix;" \
		"uniform mat4 u_viewMatrix;" \
		"uniform mat4 u_projection_matrix;" \
		"uniform int u_LKeyPressed;" \
		"uniform vec3 u_La;" \
		"uniform vec3 u_Ld;" \
		"uniform vec3 u_Ls;" \
		"uniform vec3 u_Ka;" \
		"uniform vec3 u_Kd;" \
		"uniform vec3 u_Ks;" \
		"uniform float u_materialShininess;" \
		"uniform vec4 u_light_Position;" \
		"out vec3 phong_ADS_Light;" \
		"void main(void)" \
		"{" \
		"if (u_LKeyPressed == 1)" \
		"{ " \
		"	vec4 eye_coordinates = u_viewMatrix * u_modelMatrix * vPosition;" \
		"	vec3 transformed_normal = normalize(mat3(u_viewMatrix * u_modelMatrix) * vNormal);" \
		"	vec3 light_direction = normalize(vec3(u_light_Position) - eye_coordinates.xyz);" \
		"   vec3 reflection_vector = reflect(-light_direction, transformed_normal);" \
		"   vec3 view_vector = normalize(-eye_coordinates.xyz);" \
		"   vec3 ambient = u_La * u_Ka;" \
		"   vec3 diffuse = u_Ld * u_Kd * max(dot(light_direction, transformed_normal), 0.0);" \
		"   vec3 specular = u_Ls * u_Ks * pow(max(dot(reflection_vector, view_vector), 0.0), u_materialShininess);" \
		"	phong_ADS_Light =  ambient + diffuse + specular;" \
		" } " \
		" else " \
		"{ " \
		"	phong_ADS_Light = vec3(1.0, 1.0, 1.0);" \
		"}" \
		"gl_Position = u_projection_matrix * u_viewMatrix * u_modelMatrix * vPosition;" \
		"}";

	glShaderSource(VertexShaderObject_pV, 1, (const GLchar**)&vertexShaderSourceCode_pV, NULL);

	//Compile Shader
	glCompileShader(VertexShaderObject_pV);
	GLint iInfoLogLength_pV = 0;
	GLint iShaderCompiledStatus_pV = 0;
	char* szInfoLog_pV = NULL;

	glGetShaderiv(VertexShaderObject_pV, GL_COMPILE_STATUS, &iShaderCompiledStatus_pV);
	if (iShaderCompiledStatus_pV == GL_FALSE)
	{
		glGetShaderiv(VertexShaderObject_pV, GL_INFO_LOG_LENGTH, &iInfoLogLength_pV);
		if (iInfoLogLength_pV > 0)
		{
			szInfoLog_pV = (char*)malloc(iInfoLogLength_pV);
			if (szInfoLog_pV != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(VertexShaderObject_pV, iInfoLogLength_pV, &written, szInfoLog_pV);
				fprintf(gpFile, "Vertex Shader Compilation Log : %s\n", szInfoLog_pV);
				free(szInfoLog_pV);
				UnInitialize();
				exit(0);
			}
		}
	}

	// *** FRAGMENT SHADER per Vertex****
	// Create Shader
	FragmentShaderObject_pV = glCreateShader(GL_FRAGMENT_SHADER);

	// provide source code to shader
	const GLchar* fragmentShaderSourceCode_pV =
		"#version 460 core" \
		"\n" \
		"in vec3 phong_ADS_Light;" \
		"out vec4 FragColor;" \
		"void main(void)" \
		"{"
		"FragColor = vec4(phong_ADS_Light, 1.0f);" \
		"}";

	glShaderSource(FragmentShaderObject_pV, 1, (const GLchar**)&fragmentShaderSourceCode_pV, NULL);
	glCompileShader(FragmentShaderObject_pV);

	glGetShaderiv(FragmentShaderObject_pV, GL_COMPILE_STATUS, &iShaderCompiledStatus_pV);
	if (iShaderCompiledStatus_pV == GL_FALSE)
	{
		glGetShaderiv(FragmentShaderObject_pV, GL_INFO_LOG_LENGTH, &iInfoLogLength_pV);
		if (iInfoLogLength_pV > 0)
		{
			szInfoLog_pV = (char*)malloc(iInfoLogLength_pV);
			if (szInfoLog_pV != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(FragmentShaderObject_pV, iInfoLogLength_pV, &written, szInfoLog_pV);
				fprintf(gpFile, "Fragment Shader Compilation Log : %s\n", szInfoLog_pV);
				free(szInfoLog_pV);
				UnInitialize();
				exit(0);
			}
		}
	}

	// **** SHADER PROGRAM ***
	//Create
	ShaderProgramObject_pV = glCreateProgram();

	// Attach Vertex Shader To Shader Program
	glAttachShader(ShaderProgramObject_pV, VertexShaderObject_pV);

	// Attach Fragment Shader to shader program
	glAttachShader(ShaderProgramObject_pV, FragmentShaderObject_pV);

	// pre-linking biniding of shader program object with vertex shader position attribute
	glBindAttribLocation(ShaderProgramObject_pV, NRL_ATTRIBUTE_POSITION, "vPosition");
	glBindAttribLocation(ShaderProgramObject_pV, NRL_ATTRIBUTE_NORMAL, "vNormal");

	// link shader
	glLinkProgram(ShaderProgramObject_pV);
	GLint iShaderProgramLinkStatus_pV = 0;
	glGetProgramiv(ShaderProgramObject_pV, GL_LINK_STATUS, &iShaderProgramLinkStatus_pV);
	if (iShaderCompiledStatus_pV == GL_FALSE)
	{
		glGetProgramiv(ShaderProgramObject_pV, GL_INFO_LOG_LENGTH, &iInfoLogLength_pV);
		if (iInfoLogLength_pV > 0)
		{
			szInfoLog_pV = (char*)malloc(iInfoLogLength_pV);
			if (szInfoLog_pV != NULL)
			{
				GLsizei written;
				glGetProgramInfoLog(ShaderProgramObject_pV, iInfoLogLength_pV, &written, szInfoLog_pV);
				fprintf(gpFile, "Shader Program Link Log : %s\n", szInfoLog_pV);
				free(szInfoLog_pV);
				UnInitialize();
				exit(0);
			}
		}
	}


	// get MVP uniform location
	modelMatrixUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_modelMatrix");
	viewMatrixUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_viewMatrix");
	projectionMatrixUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_projection_matrix");
	LKeyPressedUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_LKeyPressed");
	LaUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_La");
	LdUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_Ld");
	LsUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_Ls");
	KaUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_Ka");
	KdUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_Kd");
	KsUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_Ks");
	lightPositionUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_light_Position");
	materialShininessUniform = glGetUniformLocation(ShaderProgramObject_pV, "u_materialShininess");

	//_______________________________________________perVertex(End)______________________________________________________
	

	//_______________________________________________perFragment______________________________________________________
		// *** VERTEX SHADER ***
		// Create Shader
	VertexShaderObject_pF = glCreateShader(GL_VERTEX_SHADER);

	// Provide source code to shader 
	const GLchar* vertexShaderSourceCode_pF =
		"#version 460 core" \
		"\n" \
		"in vec4 vPosition;" \
		"in vec3 vNormal;" \
		"uniform mat4 u_modelMatrix;" \
		"uniform mat4 u_viewMatrix;" \
		"uniform mat4 u_projection_matrix;" \
		"uniform int u_LKeyPressed;" \
		"uniform vec4 u_light_Position;" \
		"out vec3 transformed_normal;" \
		"out vec3 light_direction;" \
		"out vec3 view_vector;" \
		"void main(void)" \
		"{" \
		"if (u_LKeyPressed == 1)" \
		"{ " \
		"	vec4 eye_coordinates = u_viewMatrix * u_modelMatrix * vPosition;" \
		"	 transformed_normal = mat3(u_viewMatrix * u_modelMatrix) * vNormal;" \
		"	 light_direction = vec3(u_light_Position - eye_coordinates);" \
		"    view_vector = -eye_coordinates.xyz;" \
		" } " \
		"gl_Position = u_projection_matrix * u_viewMatrix * u_modelMatrix * vPosition;" \
		"}";

	glShaderSource(VertexShaderObject_pF, 1, (const GLchar**)&vertexShaderSourceCode_pF, NULL);

	//Compile Shader
	glCompileShader(VertexShaderObject_pF);
	GLint iInfoLogLength_pF = 0;
	GLint iShaderCompiledStatus_pF = 0;
	char* szInfoLog_pF = NULL;

	glGetShaderiv(VertexShaderObject_pF, GL_COMPILE_STATUS, &iShaderCompiledStatus_pF);
	if (iShaderCompiledStatus_pF == GL_FALSE)
	{
		glGetShaderiv(VertexShaderObject_pF, GL_INFO_LOG_LENGTH, &iInfoLogLength_pF);
		if (iInfoLogLength_pF > 0)
		{
			szInfoLog_pF = (char*)malloc(iInfoLogLength_pF);
			if (szInfoLog_pF != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(VertexShaderObject_pF, iInfoLogLength_pF, &written, szInfoLog_pF);
				fprintf(gpFile, "Vertex Shader Compilation Log : %s\n", szInfoLog_pF);
				free(szInfoLog_pF);
				UnInitialize();
				exit(0);
			}
		}
	}

	// *** FRAGMENT SHADER ****
	// Create Shader
	FragmentShaderObject_pF = glCreateShader(GL_FRAGMENT_SHADER);

	// provide source code to shader
	const GLchar* fragmentShaderSourceCode_pF =
		"#version 460 core" \
		"\n" \
		"in vec3 transformed_normal;" \
		"in vec3 light_direction;" \
		"in vec3 view_vector;" \
		"uniform int u_LKeyPressed;" \
		"uniform vec3 u_La;" \
		"uniform vec3 u_Ld;" \
		"uniform vec3 u_Ls;" \
		"uniform vec3 u_Ka;" \
		"uniform vec3 u_Kd;" \
		"uniform vec3 u_Ks;" \
		"uniform float u_materialShininess;" \
		"out vec4 FragColor;" \
		"vec3 phong_ADS_Light;"\
		"void main(void)" \
		"{"
		"	if (u_LKeyPressed == 1)" \
		"	{ " \
		"	vec3 normalized_transformed_normal = normalize(transformed_normal);" \
		"	vec3 normalized_light_direction = normalize(light_direction); " \
		"	vec3 normalized_view_vector = normalize(view_vector); " \
		"	vec3 reflection_vector = reflect(-normalized_light_direction, normalized_transformed_normal);" \
		"	vec3 ambient = u_La * u_Ka;" \
		"	vec3 diffuse = u_Ld * u_Kd * max(dot(normalized_light_direction, normalized_transformed_normal), 0.0);" \
		"	vec3 specular = u_Ls * u_Ks * pow(max(dot(reflection_vector, normalized_view_vector), 0.0), u_materialShininess);" \
		"	phong_ADS_Light =  ambient + diffuse + specular;" \
		"	}" \
		"else" \
		"{" \
		"	phong_ADS_Light = vec3(1.0, 1.0, 1.0);" \
		"}" \
		"	FragColor = vec4(phong_ADS_Light, 1.0f);" \
		"}";

	glShaderSource(FragmentShaderObject_pF, 1, (const GLchar**)&fragmentShaderSourceCode_pF, NULL);
	glCompileShader(FragmentShaderObject_pF);

	glGetShaderiv(FragmentShaderObject_pF, GL_COMPILE_STATUS, &iShaderCompiledStatus_pF);
	if (iShaderCompiledStatus_pF == GL_FALSE)
	{
		glGetShaderiv(FragmentShaderObject_pF, GL_INFO_LOG_LENGTH, &iInfoLogLength_pF);
		if (iInfoLogLength_pF > 0)
		{
			szInfoLog_pF = (char*)malloc(iInfoLogLength_pF);
			if (szInfoLog_pF != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(FragmentShaderObject_pF, iInfoLogLength_pF, &written, szInfoLog_pF);
				fprintf(gpFile, "Fragment Shader Compilation Log : %s\n", szInfoLog_pF);
				free(szInfoLog_pF);
				UnInitialize();
				exit(0);
			}
		}
	}

	// **** SHADER PROGRAM ***
	//Create
	ShaderProgramObject_pF = glCreateProgram();

	// Attach Vertex Shader To Shader Program
	glAttachShader(ShaderProgramObject_pF, VertexShaderObject_pF);

	// Attach Fragment Shader to shader program
	glAttachShader(ShaderProgramObject_pF, FragmentShaderObject_pF);

	// pre-linking biniding of shader program object with vertex shader position attribute
	glBindAttribLocation(ShaderProgramObject_pF, NRL_ATTRIBUTE_POSITION, "vPosition");
	glBindAttribLocation(ShaderProgramObject_pF, NRL_ATTRIBUTE_NORMAL, "vNormal");

	// link shader
	glLinkProgram(ShaderProgramObject_pF);
	GLint iShaderProgramLinkStatus_pF = 0;
	glGetProgramiv(ShaderProgramObject_pF, GL_LINK_STATUS, &iShaderProgramLinkStatus_pF);
	if (iShaderCompiledStatus_pF == GL_FALSE)
	{
		glGetProgramiv(ShaderProgramObject_pF, GL_INFO_LOG_LENGTH, &iInfoLogLength_pF);
		if (iInfoLogLength_pF > 0)
		{
			szInfoLog_pF = (char*)malloc(iInfoLogLength_pF);
			if (szInfoLog_pF != NULL)
			{
				GLsizei written;
				glGetProgramInfoLog(ShaderProgramObject_pF, iInfoLogLength_pF, &written, szInfoLog_pF);
				fprintf(gpFile, "Shader Program Link Log : %s\n", szInfoLog_pF);
				free(szInfoLog_pF);
				UnInitialize();
				exit(0);
			}
		}
	}

	// get MVP uniform location
	modelMatrixUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_modelMatrix");
	viewMatrixUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_viewMatrix");
	projectionMatrixUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_projection_matrix");
	LKeyPressedUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_LKeyPressed");
	LaUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_La");
	LdUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_Ld");
	LsUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_Ls");
	KaUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_Ka");
	KdUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_Kd");
	KsUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_Ks");
	lightPositionUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_light_Position");
	materialShininessUniform = glGetUniformLocation(ShaderProgramObject_pF, "u_materialShininess");

	//_______________________________________________perFragment (End)______________________________________________________


	// *** vertices, colors, shader attribs, vbo, vao initializations ***
	getSphereVertexData(sphere_vertices, sphere_normals, sphere_textures, sphere_elements);
	gNumVertices = getNumberOfSphereVertices();
	gNumElements = getNumberOfSphereElements();

	glGenVertexArrays(1, &vao_Sphere);
	glBindVertexArray(vao_Sphere);

	//vPosition
	glGenBuffers(1, &vbo_Sphere_Position);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Sphere_Position);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sphere_vertices), sphere_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(NRL_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(NRL_ATTRIBUTE_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//vNormal
	glGenBuffers(1, &vbo_Sphere_Normals);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Sphere_Normals);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sphere_normals), sphere_normals, GL_STATIC_DRAW);
	glVertexAttribPointer(NRL_ATTRIBUTE_NORMAL, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(NRL_ATTRIBUTE_NORMAL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//vElement (Index Drawing)
	glGenBuffers(1, &vbo_Sphere_Element);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Sphere_Element);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sphere_elements), sphere_elements, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glShadeModel(GL_SMOOTH);

	// set-up depth buffer
	glClearDepth(1.0f);

	// enable depth testing
	glEnable(GL_DEPTH_TEST);

	//depth test to do
	glDepthFunc(GL_LEQUAL);

	// set really nice percpective calculations?
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// We will always cull back faces for better performance
	glEnable(GL_CULL_FACE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //black

	// set orthographics to identity matrix 
	PerspectiveProjectionMatrix = mat4::identity();


	// Resize
	Resize(WIN_WIDTH, WIN_HEIGHT);

}

void Resize(int width, int height)
{
	//code 
	if (height == 0)
	{
		height = 1;
	}
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	PerspectiveProjectionMatrix = perspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void Display(void)
{
	void Lighting(void);
	
	// code  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (PressedDigit == 0)
	{
		glUseProgram(ShaderProgramObject_pV);
	}
	else if (PressedDigit == 1)
	{
		glUseProgram(ShaderProgramObject_pF);
	}

	Lighting();

	SwapBuffers(ghdc);

}

void Lighting(void)
{
	// OpenGL Drawing
	// set ModelView & ModelviewProjection matrices to identity
	mat4 modelMatrix = mat4::identity();
	mat4 viewMatrix = mat4::identity();
	mat4 translateMatrix = mat4::identity(); // Translations Matrix Declarrations

	//glTranslatef();
	translateMatrix = translate(0.0f, 0.0f, -1.5f);

	modelMatrix = translateMatrix;

	glUniformMatrix4fv(modelMatrixUniform, 1, GL_FALSE, modelMatrix);
	glUniformMatrix4fv(viewMatrixUniform, 1, GL_FALSE, viewMatrix);
	glUniformMatrix4fv(projectionMatrixUniform, 1, GL_FALSE, PerspectiveProjectionMatrix);



	if (bLight == true)
	{
		glUniform1i(LKeyPressedUniform, 1); // Light Enable Zala with 1

		glUniform3fv(LaUniform, 1, lightAmbient);
		glUniform3fv(LdUniform, 1, lightDiffuse); 
		glUniform3fv(LsUniform, 1, lightSpecular);

		glUniform3fv(KaUniform, 1, materialAmbient); 
		glUniform3fv(KdUniform, 1, materialDiffuse);
		glUniform3fv(KsUniform, 1, materialSpecular);
		glUniform1f(materialShininessUniform, materialShininesss);
	}
	else
	{
		glUniform1i(LKeyPressedUniform, 0); // Andhaar....
	}

	//Light Position Array
	GLfloat lightPosition[] = { 100.0f, 100.0f, 100.0f, 1.0f };
	glUniform4fv(lightPositionUniform, 1, (GLfloat*)lightPosition);

	// *** bind vao ***
	glBindVertexArray(vao_Sphere);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_Sphere_Element);
	glDrawElements(GL_TRIANGLES, gNumElements, GL_UNSIGNED_SHORT, 0);

	// *** unbind vao ***
	glBindVertexArray(0);

	// stop using OpenGL Program object 
	glUseProgram(0);
}

void UnInitialize(void)
{
	//UNINITIALIZATION CODE
	if (gbFullscreen == true)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
	}

	// Destroy vao
	if (vao_Sphere)
	{
		glDeleteVertexArrays(1, &vao_Sphere);
		vao_Sphere = 0;
	}

	// Destroy vbo
	if (vbo_Sphere)
	{
		glDeleteBuffers(1, &vbo_Sphere);
		vbo_Sphere = 0;
	}

	// Destroy vbo
	if (vbo_Sphere_Position)
	{
		glDeleteBuffers(1, &vbo_Sphere_Position);
		vbo_Sphere_Position = 0;
	}


	if (vbo_Sphere_Normals)
	{
		glDeleteBuffers(1, &vbo_Sphere_Normals);
		vbo_Sphere_Normals = 0;
	}

	if (vbo_Sphere_Element)
	{
		glDeleteBuffers(1, &vbo_Sphere_Element);
		vbo_Sphere_Element = 0;
	}

	//detach vertex shader from program object
	glDetachShader(ShaderProgramObject, VertexShaderObject_pV);
	glDetachShader(ShaderProgramObject, VertexShaderObject_pF);
	// detach fragment shader from program object 
	glDetachShader(ShaderProgramObject, FragmentShaderObject_pV);
	glDetachShader(ShaderProgramObject, FragmentShaderObject_pF);
	
	// delete vertex shader object 
	glDeleteShader(VertexShaderObject_pF);
	VertexShaderObject_pF = 0;

	glDeleteShader(VertexShaderObject_pV);
	VertexShaderObject_pV = 0;

	//delete Fragment shader object 
	glDeleteShader(FragmentShaderObject_pV);
	FragmentShaderObject_pV = 0;

	glDeleteShader(FragmentShaderObject_pF);
	FragmentShaderObject_pF = 0;


	// delete shader program object 
	glDeleteProgram(ShaderProgramObject);
	ShaderProgramObject = 0;

	glDeleteProgram(ShaderProgramObject_pV);
	ShaderProgramObject = 0;

	glDeleteProgram(ShaderProgramObject_pF);
	ShaderProgramObject = 0;

	// unlink shader program
	glUseProgram(0);

	// Deselecting the rendering context
	wglMakeCurrent(NULL, NULL);

	// Delete the rendering context
	wglDeleteContext(ghrc);
	ghrc = NULL;

	// Delete the device context
	ReleaseDC(ghwnd, ghdc);
	ghdc = NULL;

	if (gpFile)
	{
		fprintf(gpFile, "Log File Is Successfully Clossed...\n");
		fclose(gpFile);
		gpFile = NULL;
	}

}
