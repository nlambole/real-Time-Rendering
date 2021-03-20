#include <windows.h>
#include <stdio.h> //for FILE I/O

#include <gl/glew.h> // for GLSL extentions IMPORTANT : This Line Should be Before #include <gl/gl.h> And #include <gl/glu.h>

#include <gl/GL.h>

#include "vmath.h"

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

using namespace vmath;

enum
{
	NRL_ATTRIBUTE_POSITION = 0,
	NRL_ATTRIBUTE_COLOR,
	NRL_ATTRIBUTE_NORMAL,
	NRL_ATTRIBUTE_TEXTURE,
};

//Prototypes of WndProc() declared GLobally
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//GLobal Variable Declarations
FILE* gpFile = NULL;

HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;

DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };

bool gbActiveWindow = false;
bool gbEscapeKeyIsPressed = false;
bool gbFullscreen = false;


GLuint gVertexShaderObject;
GLuint gFragmentShaderObject;
GLuint gShaderProgramObject;

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
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;

	// Register Abouve Code
	RegisterClassEx(&wndclass);

	// Create Window
	//Parallel to glutInitWindowSize(), glutInitWindowPosition() and glutCreateWindow() all Threee together
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, TEXT("OpenGL BlueScreen : Nandlal Lambole"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, 100, 100, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);

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
			else
				gbActiveWindow = false;
			break;

		case WM_ERASEBKGND:
			return(0);

		case WM_SIZE:
			Resize(LOWORD(lParam), HIWORD(wParam));
			break;

		case WM_KEYDOWN:
			switch (wParam)
			{
			case VK_ESCAPE:
				gbEscapeKeyIsPressed = true;
				break;

			case 0x46:
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
		void Resize(void);

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

		// *** VERTEX SHADER ***
		// Create Shader
		gVertexShaderObject = glCreateShader(GL_VERTEX_SHADER);

		// Provide source code to shader
		const GLchar* vertexShaderSourceCode =
		"#version 450" \
			"\n" \
			"void main(void)" \
			"{" \
			"}";
		glShaderSource(gVertexShaderObject, 1, (const GLchar**)&vertexShaderSourceCode, NULL);

		//Compile Shader
		glCompileShader(gVertexShaderObject);

		// *** FRAGMENT SHADER ***
		//Create Shader
		gFragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);

		//Provide source code shader
		const GLchar* fragmentShaderSourceCode =
			"#version 450" \
			"\n" \
			"void main(void)" \
			"{" \
			"}";

		glShaderSource(gFragmentShaderObject, 1, (const GLchar**)
			&fragmentShaderSourceCode, NULL);

		//Compile Shader
		glCompileShader(gFragmentShaderObject);

		// *** SHADER PROGRAM ***
		//Create
		gShaderProgramObject = glCreateProgram();

		//Attach Vertex Shader To Shader Program
		glAttachShader(gShaderProgramObject, gVertexShaderObject);

		//Attach Fragment Shader To Shader Program
		glAttachShader(gShaderProgramObject, gFragmentShaderObject);

		//Link Shader
		glLinkProgram(gShaderProgramObject);

		glShadeModel(GL_SMOOTH);

		// set-up depth Buffer
		glClearDepth(1.0f);

		// enable depth testing
		glEnable(GL_DEPTH_TEST);

		// depth test to do
		glDepthFunc(GL_LEQUAL);

		// set really nice perspective calculations?
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		//We Will always cull back faces for better performance
		glEnable(GL_CULL_FACE);


		//SetClearColour
		// Set Backround color to which it will display even if it will empty. THIS LINE CAN BE IN drawRect().
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

		//WarmUp Resize Call
		//Resize(WIN_WIDTH, WIN_HEIGHT);
	}

	void Resize(int width, int height)
	{
		//code
		if (height == 0)
		{
			height = 1;
			glViewport(0, 0, (GLsizei)width, (GLsizei)height);
		}
	}

	void Display(void)
	{
		//Code
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// start using OpenGL program object
		glUseProgram(gShaderProgramObject);

		// OpenGL Drawing

		// stop using OpenGL Program object
		glUseProgram(0);

		SwapBuffers(ghdc);
	}

	void UnInitialize(void)
	{
		//UNINITIALIZATION CODE
		if (gbFullscreen == true)
		{
			dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
			SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
			SetWindowPlacement(ghwnd, &wpPrev);
			SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0,
				SWP_NOMOVE |
				SWP_NOSIZE |
				SWP_NOOWNERZORDER |
				SWP_NOZORDER |
				SWP_FRAMECHANGED);

			ShowCursor(TRUE);
		}

		// Detach Vertex shader from shader program object
		glDetachShader(gShaderProgramObject, gVertexShaderObject);
		// Detach Fragment shader from shader program object
		glDetachShader(gShaderProgramObject, gFragmentShaderObject);

		// Delete Vertex Shader Object
		glDeleteShader(gVertexShaderObject);
		gVertexShaderObject = 0;

		// Delete Fragment Shader Object
		glDeleteShader(gFragmentShaderObject);
		gFragmentShaderObject = 0;

		// Delete Shader Program Object
		glDeleteProgram(gShaderProgramObject);
		gShaderProgramObject = 0;

		// unlink shader program
		glUseProgram(0);

		// Deselect the Rendering Context
		wglMakeCurrent(NULL, NULL);

		// Delete The Rendering Context
		wglDeleteContext(ghrc);
		ghrc = NULL;

		// delete the device context
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;

		if (gpFile)
		{
			fprintf(gpFile, "Log File Is Successfully Closed..\n");
			fclose(gpFile);
			gpFile = NULL;
		}
	}
