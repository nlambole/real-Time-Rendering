#include <windows.h>
#include <stdio.h> // for FILE I/O

#include <gl\glew.h> // for GLSL extensions IMPORTANT : This Line Should be Before #include<gl\gl.h> and #include<gl\glu.h>

#include <gl/GL.h>

#include "vmath.h"
#include "NRL.h" // Icon

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")

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

GLuint VertexShaderObject;
GLuint FragmentShaderObject;
GLuint ShaderProgramObject;

//GLuint vao; // Vartex Array Object
//GLuint vbo; // Vertex Buffer object
GLuint mvpMatrixUniform;

GLuint vbo_Color; // MultiColour

// Rotation
GLfloat Angle_Pyramid = 0.0f;
GLfloat Angle_Cube = 0.0f;

//Pyramid
GLuint vao_Pyramid;
GLuint vbo_Pyramid;
GLuint vbo_Position_Pyramid;
GLuint vbo_Color_Pyramid;

//Cube
GLuint vao_Cube;
GLuint vbo_Cube;
GLuint vbo_Position_Cube;
GLuint vbo_Color_Cube;

mat4 PerspectiveProjectionMatrix;

//main()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Function Protoytpes
	void Initialize(void);
	void UnInitialize(void);
	void Display(void);
	void Update(void);

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
	wndclass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, MAKEINTRESOURCE(MYICON));
	wndclass.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(MYICON));
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
	hwnd = CreateWindow(szClassName, TEXT("3D Rotation of Pyramid & Cube : Nandlal Lambole"), WS_OVERLAPPEDWINDOW, Width, Height, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);

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
			Update();
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
			if (gbEscapeKeyIsPressed == false)
				gbEscapeKeyIsPressed = true; // Parallel to glutLeaveMainLoop
			break;

		case 0x46: // for 'f' or "F'
		case 0x66:
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

	//Initialization of structure 'PIXELFORMATDESCRIPTOR'
	//Parallel to glutInitDisplayMode()
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

	// *** VERTEX SHADER ***
		// Create Shader
	VertexShaderObject = glCreateShader(GL_VERTEX_SHADER);

	// Provide source code to shader 
	const GLchar* vertexShaderSourceCode =
		"#version 460 core" \
		"\n" \
		"in vec4 vPosition;" \
		"in vec4 vColor;" \
		"uniform mat4 u_mvp_matrix;" \
		"out vec4 out_Color;" \
		"void main(void)" \
		"{" \
		"gl_Position = u_mvp_matrix * vPosition;" \
		"out_Color = vColor;" \
		"}";

	glShaderSource(VertexShaderObject, 1, (const GLchar**)&vertexShaderSourceCode, NULL);

	//Compile Shader
	glCompileShader(VertexShaderObject);
	GLint iInfoLogLength = 0;
	GLint iShaderCompiledStatus = 0;
	char* szInfoLog = NULL;

	glGetShaderiv(VertexShaderObject, GL_COMPILE_STATUS, &iShaderCompiledStatus);
	if (iShaderCompiledStatus == GL_FALSE)
	{
		glGetShaderiv(VertexShaderObject, GL_INFO_LOG_LENGTH, &iInfoLogLength);
		if (iInfoLogLength > 0)
		{
			szInfoLog = (char*)malloc(iInfoLogLength);
			if (szInfoLog != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(VertexShaderObject, iInfoLogLength, &written, szInfoLog);
				fprintf(gpFile, "Vertex Shader Compilation Log : %s\n", szInfoLog);
				free(szInfoLog);
				UnInitialize();
				exit(0);
			}
		}
	}

	// *** FRAGMENT SHADER ****
	// Create Shader
	FragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);

	// provide source code to shader
	const GLchar* fragmentShaderSourceCode =
		"#version 460 core" \
		"\n" \
		"in vec4 out_Color;" \
		"out vec4 FragColor;" \
		"void main(void)" \
		"{" \
		"FragColor = out_Color;" \
		"}";

	glShaderSource(FragmentShaderObject, 1, (const GLchar**)&fragmentShaderSourceCode, NULL);

	//Compile Shader
	glCompileShader(FragmentShaderObject);
	glGetShaderiv(FragmentShaderObject, GL_COMPILE_STATUS, &iShaderCompiledStatus);
	if (iShaderCompiledStatus == GL_FALSE)
	{
		glGetShaderiv(FragmentShaderObject, GL_INFO_LOG_LENGTH, &iInfoLogLength);
		if (iInfoLogLength > 0)
		{
			szInfoLog = (char*)malloc(iInfoLogLength);
			if (szInfoLog != NULL)
			{
				GLsizei written;
				glGetShaderInfoLog(FragmentShaderObject, iInfoLogLength, &written, szInfoLog);
				fprintf(gpFile, "Fragment Shader Compilation Log : %s\n", szInfoLog);
				free(szInfoLog);
				UnInitialize();
				exit(0);
			}
		}
	}

	// **** SHADER PROGRAM ***
	//Create
	ShaderProgramObject = glCreateProgram();

	// Attach Vertex Shader To Shader Program
	glAttachShader(ShaderProgramObject, VertexShaderObject);

	// Attach Fragment Shader to shader program
	glAttachShader(ShaderProgramObject, FragmentShaderObject);

	// pre-linking biniding of shader program object with vertex shader position attribute
	glBindAttribLocation(ShaderProgramObject, NRL_ATTRIBUTE_COLOR, "vColor"); // Colored Traingle Change
	glBindAttribLocation(ShaderProgramObject, NRL_ATTRIBUTE_POSITION, "vPosition");

	// link shader
	glLinkProgram(ShaderProgramObject);
	GLint iShaderProgramLinkStatus = 0;
	glGetProgramiv(ShaderProgramObject, GL_LINK_STATUS, &iShaderProgramLinkStatus);
	if (iShaderCompiledStatus == GL_FALSE)
	{
		glGetProgramiv(ShaderProgramObject, GL_INFO_LOG_LENGTH, &iInfoLogLength);
		if (iInfoLogLength > 0)
		{
			szInfoLog = (char*)malloc(iInfoLogLength);
			if (szInfoLog != NULL)
			{
				GLsizei written;
				glGetProgramInfoLog(ShaderProgramObject, iInfoLogLength, &written, szInfoLog);
				fprintf(gpFile, "Shader Program Link Log : %s\n", szInfoLog);
				free(szInfoLog);
				UnInitialize();
				exit(0);
			}
		}
	}

	// get MVP uniform location
	mvpMatrixUniform = glGetUniformLocation(ShaderProgramObject, "u_mvp_matrix");

	// *** vertices, colors, shader attribs, vbo, vao initializations ***

	// _________________________________Pyramid winding order
	const GLfloat pyramidVertices[] = 
	{
		0.0f, 1.0f, 0.0f, //Front
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,

		0.0f, 1.0f, 0.0f, // right
		1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, -1.0f,

		0.0f, 1.0f, 0.0f, // Back
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,

		0.0f, 1.0f, 0.0f, // left
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f

	}; 

	const GLfloat pyramidColors[] = 
	{ 
		1.0f, 0.0f, 0.0f, 
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,

		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,

		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,

		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,

	};

	// __________________________________Cube
	const GLfloat cubeVertices[] =
	{
		1.0f, 1.0f, 1.0f, //Front
		-1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,

		1.0f, 1.0f, -1.0f, //Right
		1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, -1.0f,

		1.0f,  1.0f, -1.0f, //back
		1.0f, -1.0f, -1.0f,
	   -1.0f, -1.0f, -1.0f,
	    -1.0f, 1.0f, -1.0f,

		-1.0f, 1.0f, 1.0f,//Left
		-1.0f, 1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f,

		1.0f, 1.0f, -1.0f,//Top
		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 1.0f,//Bottom
		-1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		

	};

	// Color of Cube
	const GLfloat cubeColor[] =
	{
		1.0f, 0.0f, 0.0f, // Red
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, // Green
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		0.0f, 0.0f, 1.0f, // Blue
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		0.0f, 1.0f, 1.0f, // Cyan
		0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f,

		1.0f, 0.0f, 1.0f, // Magenta
		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,

		1.0f, 1.0f, 0.0f, // Yellow
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,

	};

	// ------------------------------------Pyramid
	glGenVertexArrays(1, &vao_Pyramid);
	glBindVertexArray(vao_Pyramid);

	// vPosition
	glGenBuffers(1, &vbo_Pyramid);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Pyramid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidVertices), pyramidVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(NRL_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(NRL_ATTRIBUTE_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vColor
	glGenBuffers(1, &vbo_Color_Pyramid);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Color_Pyramid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidColors), pyramidColors, GL_STATIC_DRAW);
	glVertexAttribPointer(NRL_ATTRIBUTE_COLOR, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(NRL_ATTRIBUTE_COLOR);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	// ----------------------------------Cube
	glGenVertexArrays(1, &vao_Cube);
	glBindVertexArray(vao_Cube);

	// vPosition
	glGenBuffers(1, &vbo_Cube);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Cube);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(NRL_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(NRL_ATTRIBUTE_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vColor
	glGenBuffers(1, &vbo_Color_Cube);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_Color_Cube);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeColor), cubeColor, GL_STATIC_DRAW);
	glVertexAttribPointer(NRL_ATTRIBUTE_COLOR, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(NRL_ATTRIBUTE_COLOR);
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

	// set backround color to which it will display even if it will empty.
	// THIS LINE CAN BE IN drawRect();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Black

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
	// code 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// start using OpenGL program object
	glUseProgram(ShaderProgramObject);

	// *********************************Pyramid Transformation
	mat4 translateMatrix = mat4::identity(); // Translations Matrix Declarrations
	mat4 rotationMatrix = mat4::identity(); // Rotation mar
	mat4 scaleMatrix = mat4::identity(); // Scale matrix
	mat4 modelViewMatrix = mat4::identity();
	mat4 modelViewProjectionMatrix = mat4::identity();

	//glTranslatef();
	translateMatrix = vmath::translate(-1.5f, 0.0f, -6.0f);
	rotationMatrix = vmath::rotate(Angle_Pyramid, 0.0f, 1.0f, 0.0f);

	modelViewMatrix = translateMatrix * rotationMatrix;

	//Multiply the modelview and orthographics matrix to get modelviewprojections matrix
	modelViewProjectionMatrix = PerspectiveProjectionMatrix * modelViewMatrix; // Order IS IMPORTANT

	// pass abouve modelviewprojections matrix to the vertex shader in 'u_mvp_matrix' shader variable 
	// whose position value  we already calculated in initWithFrame() by using glGetUniformLocations()
	glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, modelViewProjectionMatrix);

	// *** bind vao ***
	glBindVertexArray(vao_Pyramid);

	// *** draw, either by glDrawTriangles() or glDrawArrays() or glDrawElements array
	glDrawArrays(GL_TRIANGLES, 0, 12); // 12 Vertex of Pyramid

	// *** unbind vao ***
	glBindVertexArray(0);


	// Start ********************************************* Cube Trasnformation
	translateMatrix = mat4::identity(); // Translations Matrix Declarrations
	rotationMatrix = mat4::identity();
	scaleMatrix = mat4::identity();
	modelViewMatrix = mat4::identity();
	modelViewProjectionMatrix = mat4::identity();

	// Rotation Matrix
	mat4 xRotationMatrix = mat4::identity();
	mat4 yRotationMatrix = mat4::identity();
	mat4 zRotationMatrix = mat4::identity();


	//glTranslatef();
	translateMatrix = vmath::translate(1.5f, 0.0f, -6.0f);
	
	// XYZ Rotations
	xRotationMatrix = vmath::rotate(Angle_Cube, 1.0f, 0.0f, 0.0f);
	yRotationMatrix = vmath::rotate(Angle_Cube, 0.0f, 1.0f, 0.0f);
	zRotationMatrix = vmath::rotate(Angle_Cube, 0.0f, 0.0f, 1.0f);

	// glScalef();
	scaleMatrix = vmath::scale(0.75f, 0.75f, 0.75f);

	// Resultant Matrix of All Axis Rotations
	rotationMatrix = xRotationMatrix * yRotationMatrix * zRotationMatrix;

	modelViewMatrix = translateMatrix * scaleMatrix * rotationMatrix ;

	//Multiply the modelview and orthographics matrix to get modelviewprojections matrix
	modelViewProjectionMatrix = PerspectiveProjectionMatrix * modelViewMatrix; // Order IS IMPORTANT

	// pass abouve modelviewprojections matrix to the vertex shader in 'u_mvp_matrix' shader variable 
	// whose position value  we already calculated in initWithFrame() by using glGetUniformLocations()
	glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, modelViewProjectionMatrix);

	// *** bind vao ***
	glBindVertexArray(vao_Cube);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4); // 0 to 4 vertex ofCube draw kelet
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4); // 4 to 4 vertex ofCube draw kelet
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);

	// *** unbind vao ***
	glBindVertexArray(0);
	// End ************************************************(Cube Transformation)

	// stop using OpenGL Program object 
	glUseProgram(0);

	SwapBuffers(ghdc);

}

void Update(void)
{
	Angle_Pyramid += 1.0f;
	if (Angle_Pyramid >= 360)
	{
		Angle_Pyramid = 0.0f;
	}

	Angle_Cube += 1.0f;
	if (Angle_Cube >= 360)
	{
		Angle_Cube = 0.0f;
	}
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
	if (vao_Pyramid)
	{
		glDeleteVertexArrays(1, &vao_Pyramid);
		vao_Pyramid = 0;
	}
	if (vao_Cube)
	{
		glDeleteVertexArrays(1, &vao_Cube);
		vao_Cube = 0;
	}

	// Destroy vbo
	if (vbo_Color_Cube)
	{
		glDeleteBuffers(1, &vbo_Color_Cube);
		vbo_Color_Cube = 0;
	}
	if (vbo_Color_Pyramid)
	{
		glDeleteBuffers(1, &vbo_Color_Pyramid);
		vbo_Color_Pyramid = 0;
	}
	if (vbo_Position_Pyramid)
	{
		glDeleteBuffers(1, &vbo_Position_Pyramid);
		vbo_Position_Pyramid = 0;
	}
	if (vbo_Position_Cube)
	{
		glDeleteBuffers(1, &vbo_Position_Cube);
		vbo_Position_Cube = 0;
	}

	if (vbo_Pyramid)
	{
		glDeleteVertexArrays(1, &vbo_Pyramid);
		vbo_Pyramid = 0;
	}
	if (vbo_Cube)
	{
		glDeleteVertexArrays(1, &vbo_Cube);
		vbo_Cube = 0;
	}


	// Destroy vbo_Color
	if (vbo_Color)
	{
		glDeleteBuffers(1, &vbo_Color);
		vbo_Color = 0;
	}

	//detach vertex shader from program object
	glDetachShader(ShaderProgramObject, VertexShaderObject);
	// detach fragment shader from program object 
	glDetachShader(ShaderProgramObject, FragmentShaderObject);

	// delete vertex shader object 
	glDeleteShader(VertexShaderObject);
	VertexShaderObject = 0;
	//delete Fragment shader object 
	glDeleteShader(FragmentShaderObject);
	FragmentShaderObject = 0;

	// delete shader program object 
	glDeleteProgram(ShaderProgramObject);
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
