//Headers
#include <windows.h>
#include <stdio.h>
#include "NRL.h"
#include <gl/gl.h>
#include <gl/glu.h>

#pragma comment(lib, "glu32")

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
bool gbFullscreen = false;
bool gbActiveWindow = false;
HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;
FILE* gpFile = NULL;

GLfloat x_I = -5.0f;
GLdouble fCount_XI = 0.05;

GLfloat y = 5.0f;
GLdouble fCount_N = 0.05;

GLfloat Y_I = -5.0f;
GLdouble fCount_YI = 0.05;

GLfloat X_A = 5.0f;
GLdouble fCount_XA = 0.05;

GLfloat fCount_D11 = 0.015;


//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdlie, int iCmdShow)
{
	//Function Declaration
	void Display(void);
	void Initialize(void);
	//void Display(void);

	//Varable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("FullScreen Window");
	bool bDone = false;

	if (fopen_s(&gpFile, "NRLLog.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Cannot Open Desired File"), ERROR, MB_OK);
		exit(0);
	}

	// code
	// Initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// Register Abouve Code
	RegisterClassEx(&wndclass);

	// Create Window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("Static India : Nandlal Lambole"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, 100, 100, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
	ghwnd = hwnd;

	Initialize(); //Call           

	ShowWindow(hwnd, SW_MAXIMIZE);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

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
			if (gbActiveWindow == true)
			{
				//Here You Should Call Update Function For OpenGL Rendering

				//Here You Should Call Display Function For OpenGL Rendering
				Display(); //Call Display
			}

		}
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Function Prototype
	void ToggleFullScreen(void);
	void Resize(int, int);
	void UnInitialize(void);


	// Code
	switch (iMsg)
	{

	case WM_CREATE:
		fprintf(gpFile, "India Is My Country\n\n");
		break;

	case WM_SETFOCUS:
		gbActiveWindow = true;
		break;

	case WM_KILLFOCUS:
		gbActiveWindow = false;
		break;

	case WM_ERASEBKGND:
		return(0);

	case WM_SIZE:
		Resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd); //Win32 API
			break;

		case 0x46:
		case 0x66:
			ToggleFullScreen(); //Call
			break;

		default:
			break;
		}
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd); //Win32 API
		break;

	case WM_DESTROY:
		UnInitialize(); //Call
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullScreen(void)
{
	//Local Variable Declarations
	MONITORINFO mi = { sizeof(MONITORINFO) };

	//Code
	if (gbFullscreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, (dwStyle & ~WS_OVERLAPPEDWINDOW));
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, (mi.rcMonitor.right - mi.rcMonitor.left), (mi.rcMonitor.bottom - mi.rcMonitor.top), SWP_NOZORDER | SWP_FRAMECHANGED);

			}
		}
		ShowCursor(FALSE);
		gbFullscreen = true;
	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, (dwStyle | WS_OVERLAPPEDWINDOW));
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
		gbFullscreen = false;

	}
}

void Initialize(void)
{
	//Function Declaration
	void Resize(int, int);

	// Variable Declaration
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex;

	//Code
	Resize(WIN_WIDTH, WIN_HEIGHT); //WarmUp Call To Resize

	ghdc = GetDC(ghwnd);
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

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixel Format Function Failed..!");
		DestroyWindow(ghwnd);
	}

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixel Format Function Failed..!");
		DestroyWindow(ghwnd);
	}

	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext Function Failed..!");
		DestroyWindow(ghwnd);
	}

	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent Function Failed..!");
		DestroyWindow(ghwnd);
	}



	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//WarmUp Resize Call
	Resize(WIN_WIDTH, WIN_HEIGHT);

}

void Resize(int Width, int Height)
{
	//Code
	if (Height == 0)
	{
		Height = 1;
	}
	glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);
}

void Display(void)
{
	//Function Prototype
	void I(void);
	void N(void);
	void D(void);
	void A(void);

	//Code
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	glTranslatef(-2.30, 0.0f, -6.0f);
	I();

	glLoadIdentity();
	N();
	
	glLoadIdentity();
	D();
	
	glLoadIdentity();
	glTranslatef(1.3f, 0.0f, -6.0f);
	I();
	
	glLoadIdentity();
	A();
	
	

	SwapBuffers(ghdc); //Native API for Windowing
}

void I(void)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(0.5f, 0.7f, 0.0f);
	glVertex3f(-0.5f, 0.7f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	
	glEnd();

	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(0.1f, 0.5f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(-0.1f, 0.5f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-0.1f, -0.5f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(0.1f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(-0.5f, -0.7f, 0.0f);
	glVertex3f(0.5f, -0.7f, 0.0f);
	glEnd();

}

void N(void)
{
	glTranslatef(-1.55f, 0.0f, -6.0f);
	glScalef(0.9f, 1.0f, 0.0f);

	//**************************** |Left
	glBegin(GL_QUADS); //Upper Box
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(0.1f, 0.7f, 0.0f);
	glVertex3f(-0.1f, 0.7f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(-0.1f, 0.5f, 0.0f);
	glVertex3f(0.1f, 0.5f, 0.0f);
	glEnd();
	// ******************************

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(0.1f, 0.5f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(-0.1f, 0.5f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-0.1f, -0.5f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(0.1f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //Lower Box
	
	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(0.1f, -0.7f, 0.0f);
	glVertex3f(-0.1f, -0.7f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-0.1f, -0.5f, 0.0f);
	glVertex3f(0.1f, -0.5f, 0.0f);
	glEnd();


	//------------------------------------------
	//**************************** |Right
	glBegin(GL_QUADS); //Upper Box
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(0.8f, 0.7f, 0.0f);
	glVertex3f(1.0f, 0.7f, 0.0f);
	

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.8f, 0.5f, 0.0f);
	glEnd();
	// ******************************

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(0.8f, 0.5f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(1.0f, 0.5f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(1.0f, -0.5f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(0.8f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //Lower Box

	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(0.8f, -0.7f, 0.0f);
	glVertex3f(1.0f, -0.7f, 0.0f);
	
	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(1.0f, -0.5f, 0.0f);
	glVertex3f(0.8f, -0.5f, 0.0f);
	glEnd();

	//----------------------------------------//Middle
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(0.1f, 0.7f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(0.1f, 0.4f, 0.0f);

	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(0.8f, -0.7f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(0.8f, -0.4f, 0.0f);
	glEnd();

}

void D(void)
{
	
	glTranslatef(0.0f, 0.0f, -6.0f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.6f, 0.2f); //1
	glVertex3f(0.4f, 0.7f, 0.0f);
	glVertex3f(-0.5f, 0.7f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f); //2
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.3f, 0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.6f, 0.2f); //1#Orange Curve
	glVertex3f(0.4f, 0.7f, 0.0f);
	
	glColor3f(1.0f, 0.72f, 0.45f); //2#OrangeCurve
	glVertex3f(0.3f, 0.5f, 0.0f);
	glVertex3f(0.45f, 0.4f, 0.0f);
	glVertex3f(0.65f, 0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.59f, 0.92f, 0.054f);  //3
	glVertex3f(0.3f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glColor3f(0.074f, 0.533f, 0.0313f); //4
	glVertex3f(-0.5f, -0.7f, 0.0f);
	glVertex3f(0.4f, -0.7f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.074f, 0.533f, 0.0313f); //1#Green Curve
	glVertex3f(0.4f, -0.7f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);//2#Green
	glVertex3f(0.3f, -0.5f, 0.0f);
	glVertex3f(0.45f,-0.4f, 0.0f);
	glVertex3f(0.65f, -0.5f, 0.0f);
	glEnd();

	//-----------------------------Left |

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.72f, 0.45f); //2
	glVertex3f(0.45f, 0.4f, 0.0f);
	glVertex3f(0.65f, 0.5f, 0.0f);
	
	glColor3f(0.59f, 0.92f, 0.054f);  //3
	glVertex3f(0.65f, -0.5f, 0.0f);
	glVertex3f(0.45f, -0.4f, 0.0f);
	glEnd();

	//--------------------------------Right |

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.72f, 0.45f); //2
	glVertex3f(-0.3f, 0.5f, 0.0f);
	glVertex3f(-0.1f, 0.5f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f); //3
	glVertex3f(-0.1f, -0.5f, 0.0f);
	glVertex3f(-0.3f, -0.5f, 0.0f);
	glEnd();

}

void A(void)
{

	glTranslatef(2.45f, 0.0f, -6.0f);
	glScalef(0.95f, 1.0f, 0.0f);

	
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(-0.1f, 0.7f, 0.0f);
	glVertex3f(0.1f, 0.7f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(0.0f, 0.4f, 0.0f);
	glEnd();

	//---------------------------
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(-0.1f, 0.7f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(0.0f, 0.4f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-0.3f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //Lower Box /

	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(-0.57f, -0.7f, 0.0f);
	glVertex3f(-0.37f, -0.7f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-0.3f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glEnd();

	//------------------------------------

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(0.1f, 0.7f, 0.0f);

	glColor3f(1.0f, 0.72f, 0.45f);
	glVertex3f(0.0f, 0.4f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(0.3f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //Lower Box \

	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(0.57f, -0.7f, 0.0f);
	glVertex3f(0.37f, -0.7f, 0.0f);

	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(0.3f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glEnd();

	//-------------------------------Flag

	glBegin(GL_QUADS);		//Orange
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(0.135f, 0.0f, 0.0f);
	glVertex3f(-0.135f, 0.0f, 0.0f);
	glVertex3f(-0.15f, -0.05f, 0.0f);
	glVertex3f(0.15f, -0.05f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);		//White
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.15f, -0.05f, 0.0f);
	glVertex3f(0.15f, -0.05f, 0.0f);
	glVertex3f(0.1675f, -0.10f, 0.0f);
	glVertex3f(-0.1675f, -0.10f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);		//Green
	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(-0.185f, -0.15f, 0.0f);
	glVertex3f(0.185f, -0.15f, 0.0f);
	glVertex3f(0.1675f, -0.10f, 0.0f);
	glVertex3f(-0.1675f, -0.10f, 0.0f);
	glEnd();

	// ------------------------------------

	
}

void UnInitialize(void)
{
	//Code
	if (gbFullscreen == true)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		SetWindowLong(ghwnd, GWL_STYLE, (dwStyle | WS_OVERLAPPEDWINDOW));
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}

	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	if (gpFile)
	{
		fclose(gpFile);
		gpFile = NULL;

	}
}
