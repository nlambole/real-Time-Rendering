//Headers
#include <windows.h>
#include <stdio.h>
#include "NRL.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h>

#pragma comment(lib, "glu32")

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define Pi 3.14159

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

int Width;
int Height;

GLdouble Angle = 45;
GLdouble fCounter = 0.5;

GLdouble X = 1.0f;
GLdouble Y = 1.0f;
GLdouble Z = 1.0f;

GLfloat Identity_Matrix[16];
GLfloat Translations_Matrix_CUBE[16];
GLfloat Translations_Matrix_PYRAMID[16];
GLfloat Scale_Matrix[16];
GLfloat Rotation_Matrix_X[16];
GLfloat Rotation_Matrix_Y[16];
GLfloat Rotation_Matrix_Z[16];


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

	Width = (GetSystemMetrics(SM_CXSCREEN) / 2 - WIN_WIDTH / 2);
	Height = (GetSystemMetrics(SM_CYSCREEN) / 2 - WIN_HEIGHT / 2);

	// Create Window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("3D CUBE: Nandlal Lambole"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, Width, Height, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
	ghwnd = hwnd;

	Initialize(); //Call           

	ShowWindow(hwnd, iCmdShow);
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
	void Resize(int Width, int Height);
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

	case WM_KEYDOWN:
		switch (wParam)
		{

		case VK_ESCAPE:
			DestroyWindow(hwnd); //Win32 API
			break;

		case 0x46:
			//case 0x66:
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
	pfd.cDepthBits = 32;

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

	//Identity Matrix
	Identity_Matrix[0] = 1.0f;
	Identity_Matrix[1] = 0.0f;
	Identity_Matrix[2] = 0.0f;
	Identity_Matrix[3] = 0.0f;
	Identity_Matrix[4] = 0.0f;
	Identity_Matrix[5] = 1.0f;
	Identity_Matrix[6] = 0.0f;
	Identity_Matrix[7] = 0.0f;
	Identity_Matrix[8] = 0.0f;
	Identity_Matrix[9] = 0.0f;
	Identity_Matrix[10] = 1.0f;
	Identity_Matrix[11] = 0.0f;
	Identity_Matrix[12] = 0.0f;
	Identity_Matrix[13] = 0.0f;
	Identity_Matrix[14] = 0.0f;
	Identity_Matrix[15] = 1.0f;

	//Translation Matrix For Cube
	Translations_Matrix_CUBE[0] = 1.0f;
	Translations_Matrix_CUBE[1] = 0.0f;
	Translations_Matrix_CUBE[2] = 0.0f;
	Translations_Matrix_CUBE[3] = 0.0f;
	Translations_Matrix_CUBE[4] = 0.0f;
	Translations_Matrix_CUBE[5] = 1.0f;
	Translations_Matrix_CUBE[6] = 0.0f;
	Translations_Matrix_CUBE[7] = 0.0f;
	Translations_Matrix_CUBE[8] = 0.0f;
	Translations_Matrix_CUBE[9] = 0.0f;
	Translations_Matrix_CUBE[10] = 1.0f;
	Translations_Matrix_CUBE[11] = 0.0f;
	Translations_Matrix_CUBE[12] = 2.0f;
	Translations_Matrix_CUBE[13] = 0.0f;
	Translations_Matrix_CUBE[14] = -6.0f;
	Translations_Matrix_CUBE[15] = 1.0f;

	//Translation Matrix For Pyramid
	Translations_Matrix_PYRAMID[0] = 1.0f;
	Translations_Matrix_PYRAMID[1] = 0.0f;
	Translations_Matrix_PYRAMID[2] = 0.0f;
	Translations_Matrix_PYRAMID[3] = 0.0f;
	Translations_Matrix_PYRAMID[4] = 0.0f;
	Translations_Matrix_PYRAMID[5] = 1.0f;
	Translations_Matrix_PYRAMID[6] = 0.0f;
	Translations_Matrix_PYRAMID[7] = 0.0f;
	Translations_Matrix_PYRAMID[8] = 0.0f;
	Translations_Matrix_PYRAMID[9] = 0.0f;
	Translations_Matrix_PYRAMID[10] = 1.0f;
	Translations_Matrix_PYRAMID[11] = 0.0f;
	Translations_Matrix_PYRAMID[12] = -2.0f;
	Translations_Matrix_PYRAMID[13] = 0.0f;
	Translations_Matrix_PYRAMID[14] = -6.0f;
	Translations_Matrix_PYRAMID[15] = 1.0f;

	//Scale Matrix
	Scale_Matrix[0] = 0.75f;
	Scale_Matrix[1] = 0.0f;
	Scale_Matrix[2] = 0.0f;
	Scale_Matrix[3] = 0.0f;
	Scale_Matrix[4] = 0.0f;
	Scale_Matrix[5] = 0.75f;
	Scale_Matrix[6] = 0.0f;
	Scale_Matrix[7] = 0.0f;
	Scale_Matrix[8] = 0.0f;
	Scale_Matrix[9] = 0.0f;
	Scale_Matrix[10] = 0.75f;
	Scale_Matrix[11] = 0.0f;
	Scale_Matrix[12] = 0.0f;
	Scale_Matrix[13] = 0.0f;
	Scale_Matrix[14] = 0.0f;
	Scale_Matrix[15] = 1.0f;

	//SetClearColour
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Depth Function
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//Accessory Function
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); //Distortion Correction

	//WarmUp Resize Call
	Resize(WIN_WIDTH, WIN_HEIGHT);
	 
}

void Resize(int width, int height)
{
	//Code
	if (height == 0)
	{
		height = 1;
	}
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void Display(void)
{
	static GLfloat Angle_Rad = 0.0f;

	//Function Prototype
	void Triangle(void);
	void Rectangle(void);
	
	//Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	//glLoadIdentity();
	glLoadMatrixf(Identity_Matrix);

	//glTranslatef(0.0f, 0.0f, -6.0f);
	glMultMatrixf(Translations_Matrix_CUBE);

	//glScalef(0.75f, 0.75f, 0.75f);
	glMultMatrixf(Scale_Matrix);

	//glRotatef(Angle, X, Y, Z);
	Angle_Rad = Angle * Pi / 180.0f;
	
	//X-Rotation Matrix
	Rotation_Matrix_X[0] = 1.0f;
	Rotation_Matrix_X[1] = 0.0f;
	Rotation_Matrix_X[2] = 0.0f;
	Rotation_Matrix_X[3] = 0.0f;
	Rotation_Matrix_X[4] = 0.0f;
	Rotation_Matrix_X[5] = cos(Angle_Rad);
	Rotation_Matrix_X[6] = sin(Angle_Rad);
	Rotation_Matrix_X[7] = 0.0f;
	Rotation_Matrix_X[8] = 0.0f;
	Rotation_Matrix_X[9] = -sin(Angle_Rad);
	Rotation_Matrix_X[10] = cos(Angle_Rad);
	Rotation_Matrix_X[11] = 0.0f;
	Rotation_Matrix_X[12] = 0.0f;
	Rotation_Matrix_X[13] = 0.0f;
	Rotation_Matrix_X[14] = 0.0f;
	Rotation_Matrix_X[15] = 1.0f;

	//Y-Rotation Matrix
	Rotation_Matrix_Y[0] = cos(Angle_Rad);
	Rotation_Matrix_Y[1] = 0.0f;
	Rotation_Matrix_Y[2] = -sin(Angle_Rad);
	Rotation_Matrix_Y[3] = 0.0f;
	Rotation_Matrix_Y[4] = 0.0f;
	Rotation_Matrix_Y[5] = 1.0;
	Rotation_Matrix_Y[6] = 0.0f;
	Rotation_Matrix_Y[7] = 0.0f;
	Rotation_Matrix_Y[8] = sin(Angle_Rad);
	Rotation_Matrix_Y[9] = 0.0f;
	Rotation_Matrix_Y[10] = cos(Angle_Rad);
	Rotation_Matrix_Y[11] = 0.0f;
	Rotation_Matrix_Y[12] = 0.0f;
	Rotation_Matrix_Y[13] = 0.0f;
	Rotation_Matrix_Y[14] = 0.0f;
	Rotation_Matrix_Y[15] = 1.0f;

	//Z-Rotation Matrix
	Rotation_Matrix_Z[0] = cos(Angle_Rad);
	Rotation_Matrix_Z[1] = sin(Angle_Rad);
	Rotation_Matrix_Z[2] = 0.0f;
	Rotation_Matrix_Z[3] = 0.0f;
	Rotation_Matrix_Z[4] = -sin(Angle_Rad);
	Rotation_Matrix_Z[5] = cos(Angle_Rad);
	Rotation_Matrix_Z[6] = 0.0f;
	Rotation_Matrix_Z[7] = 0.0f;
	Rotation_Matrix_Z[8] = 0.0f;
	Rotation_Matrix_Z[9] = 0.0f;
	Rotation_Matrix_Z[10] = 1.0f;
	Rotation_Matrix_Z[11] = 0.0f;
	Rotation_Matrix_Z[12] = 0.0f;
	Rotation_Matrix_Z[13] = 0.0f;
	Rotation_Matrix_Z[14] = 0.0f;
	Rotation_Matrix_Z[15] = 1.0f;

	glMultMatrixf(Rotation_Matrix_X);
	glMultMatrixf(Rotation_Matrix_Y);
	glMultMatrixf(Rotation_Matrix_Z);

	Rectangle();

	///glLoadIdentity();
	glLoadMatrixf(Identity_Matrix);

	//glTranslatef(0.0f, 0.0f, -6.0f);
	glMultMatrixf(Translations_Matrix_PYRAMID);

	//glRotatef(Angle, 0.0f, Y, 0.0f);
	glMultMatrixf(Rotation_Matrix_Y); // Rotation Arround Y Axis

	Triangle();

	Angle += fCounter; //Angle In Degree

	//X += fCounter;
	//Y += fCounter;
	//Z += fCounter;
	SwapBuffers(ghdc); //Native API for Windowing
}

void Triangle(void)
{

	glBegin(GL_TRIANGLES);		//Front
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);//Back
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
}

void Rectangle(void)
{
	glBegin(GL_QUADS);	
	//Front
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	//Right
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	//Back
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//Left
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	//Top
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//Bottom
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

}

/*void Triangle(void)
{
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
}*/

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
