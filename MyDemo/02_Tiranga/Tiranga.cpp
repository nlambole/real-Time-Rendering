//Headers
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include "NRL.h"
#include <gl/gl.h>
#include <gl/GLU.h>

#pragma comment (lib , "winmm.lib")
#pragma comment (lib, "glu32")

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
static float iRadius = 0.05f;
static float iA = 0.0f;
static float nX = 0, nY = 0;

static float fWorld = 0.0f;
static double iUnit = 0.002;

static float fOrangeX = 0.0f, fWhiteX = 0.0f, fGreenX = 0.0f;
static float fY = 0.0f;
static double oUnit = 0.0002, wUnit = 0.0002, gUnit = 0.0002, pUnit = 0.0002;


//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdlie, int iCmdShow)
{
	//Function Declaration
	void Display(void);
	void Initialize(void);


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
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("Tiranga : Nandlal Lambole"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, 0, 0, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
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
	//void Display();
	void ToggleFullScreen(void);
	void Resize(int, int);
	void UnInitialize(void);
	

	// Code
	switch (iMsg)
	{
	
	case WM_CREATE:
		PlaySound(MAKEINTRESOURCE(MYMUSIC), NULL, SND_RESOURCE | SND_ASYNC);
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

	//SetClearColour

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//WarmUp Resize Call
	Resize(WIN_WIDTH, WIN_HEIGHT);

}

void Resize(int iWidth, int iHeight)
{
	
	//Code
	iRadius = 0.08f;
	 iA = 0.0f;
	 nX = 0;
	 nY = 0;
	 fOrangeX = 0.0f;
	 fWhiteX = 0.0f;
	fGreenX = 0.0f;
	 fY = 0.0f;
	 oUnit = 0.002;
	 wUnit = 0.002;
	 gUnit = 0.002;
	 pUnit = 0.002;

	 fWorld = 0.0f;
	 iUnit = 0.002;

	if (iHeight == 0)
	{
		iHeight = 1;
	}
	glViewport(0, 0, (GLsizei)iWidth, (GLsizei)iHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, GLfloat(iWidth) / GLfloat(iHeight), 0.1f, 100.0f);
}

void Display(void)
{

	//Code
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -4.0f);
	glPointSize(2);
	glLineWidth(1);

	//Background
	glBegin(GL_QUADS);
	glColor3f(0.70f, 0.98f, 1.0f);
	glVertex3f(16.0f, 16.0f, 0.0f);
	glVertex3f(-16.0f, 16.0f, 0.0f);
	glVertex3f(-16.0f, 0.08f, 0.0f);
	glVertex3f(16.0f, 0.08f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.44f, 0.89f, 0.0f);
	glVertex3f(-16.0f, 0.08f, 0.0f);
	glColor3f(0.44f, 0.92f, 0.0f);
	glVertex3f(16.0f, 0.08f, 0.0f);
	glColor3f(0.45f, 0.85f, 0.0f);
	glVertex3f(16.0f, -16.0f, 0.0f);
	glColor3f(0.40f, 0.88f, 0.0f);
	glVertex3f(-16.0f, -16.0f, 0.0f);
	glEnd();

	//FlagPole
	glBegin(GL_QUADS);
	glColor3f(0.407f, 0.407f, 0.407f);
	glVertex3f(-1.0f, -1.45f, 0.0f);
	glVertex3f(0.50f, -1.45f, 0.0f);
	glVertex3f(0.32f, -1.35f, 0.0f);
	glVertex3f(-0.82f, -1.35f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.407f, 0.407f, 0.407f);
	glVertex3f(-0.49f, -1.0f + fY, 0.0f);
	glVertex3f(-0.52f, -1.0f + fY, 0.0f);
	glVertex3f(-0.52f, -1.35f, 0.0f);
	glVertex3f(-0.49f, -1.35f, 0.0f);

	fY += pUnit;

	if (fY >= 1.35)
	{
		pUnit = 0.0;
	}
	glEnd();


	if (pUnit == 0.0 )
	{	

		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -0.1f - fWorld ); // Camera + World
		if (fWorld < 3.96)
		{
			fWorld += iUnit;
		}

		// OrangeFlag
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.6f, 0.2f);
		glVertex3f(-0.5f, 0.3f, 0.0f);
		glVertex3f(0.5f, 0.3f, 0.0f);
		glVertex3f(0.5f, 0.1f, 0.0f);
		glVertex3f(-0.5f, 0.1f, 0.0f);
		glEnd();

		//White Flag
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.5f, 0.1f, 0.0f);
		glVertex3f(0.5f, -0.1f, 0.0f);
		glVertex3f(-0.5f, -0.1f, 0.0f);
		glVertex3f(-0.5f, 0.1f, 0.0f);
		glEnd();

		//Green Flag
		glBegin(GL_QUADS);
		glColor3f(0.074f, 0.533f, 0.0313f);
		glVertex3f(0.5f, -0.1f, 0.0f);
		glVertex3f(-0.5f, -0.1f, 0.0f);
		glVertex3f(-0.5f, -0.3f, 0.0f);
		glVertex3f(0.5f, -0.3f, 0.0f);
		glEnd();


		for (iA = 0; iA < 360; iA++)
		{
			nX = iRadius * cosf(iA);
			nY = iRadius * sinf(iA);

			glBegin(GL_POINTS);
			glColor3f(0.0f, 0.0f, 0.501f);
			glVertex3f(nX, nY, 0.0f);
			glEnd();
		}

		for (float iB = 0; iB < 25; iB++)
		{
			float mX = iRadius * cosf(iB);
			float mY = iRadius * sinf(iB);

			glBegin(GL_LINES);
			glColor3f(0.0f, 0.0f, 0.501f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(mX, mY, 0.0f);
			glEnd();

		}
	}

	SwapBuffers(ghdc); //Native API for Windowing
	//glFlush();
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
