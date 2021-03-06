//Headers
#include <windows.h>
#include <stdio.h>
#include "NRL.h"
#include <gl/gl.h>
#include <gl/glu.h>

#pragma comment (lib , "winmm.lib")
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

GLdouble x_I = -5.0f;
GLdouble fCount_XI = 0.02;

GLdouble y = 4.0f;
GLdouble fCount_N = 0.02;

GLdouble Y_I = -5.0f;
GLdouble fCount_YI = 0.02;

GLdouble X_A = 5.0f;
GLdouble fCount_XA = 0.02;

GLdouble fCount_D11 = 0.02;

GLdouble fX_Jet1 = -20;
GLdouble fX_Jet2 = -19.7;
GLdouble fX_Jet3 = -20;

GLdouble fY_Jet1 = 20.0;
GLdouble fY_Jet2 = -20.0;
GLdouble fY_Jet3 = -20.0;

GLdouble fCountX = 0.015;
GLdouble fCountY = 0.03;


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
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("Dynamic India : by Nandlal Lambole"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, 100, 100, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
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

	void O_Smoke(void);
	void W_Smoke(void);
	void G_Smoke(void);

	void Aircraft(void);

	//Code
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	glTranslatef(x_I, 0.0f, -6.0f);
	I();
	x_I += fCount_XI;
	if (x_I >= -2.30)
	{
		fCount_XI = 0;
	}
	if (fCount_XI == 0)
	{
		glLoadIdentity();
		N();
	}
	
	if (fCount_N == 0)
	{
		glLoadIdentity();
		D();
	}
	
	if (fCount_D11 == 0)
	{
		glLoadIdentity();
		glTranslatef(1.3f, Y_I, -6.0f);
		I();
		Y_I += fCount_YI;
		if (Y_I >= -0.005)
		{
			fCount_YI = 0;
		}
	}
	
	if (fCount_YI == 0)
	{
		glLoadIdentity();
		A();
		if (fX_Jet2 > 9)
		{
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
			glVertex3f(0.167f, -0.10f, 0.0f);
			glVertex3f(-0.167f, -0.10f, 0.0f);
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
	}
	
	if (fCount_XA == 0)
	{
		//--------------------------------------//Animation of Orange Jet
		glLoadIdentity();					
		glTranslatef(fX_Jet1, fY_Jet1, -20.0f);

		fX_Jet1 += fCountX;

		if (fY_Jet1 > 0 && fX_Jet1 < 5)
		{
			fY_Jet1 -= fCountY;
		}
		
		if (fY_Jet1 < 0 && fX_Jet1 < 5)
		{
			fY_Jet1 = 0;
		}
		
		if (fX_Jet1 > 20)
		{
			fX_Jet1 = 30;
		}
		
		if (fX_Jet1 > 11)
		{
			fY_Jet1 += fCountY;
		}


		O_Smoke();
		Aircraft();
	//----------------------------------------//Animation of White Jet
		glLoadIdentity();					
		glTranslatef(fX_Jet2, -0.15f, -20.0f);

		fX_Jet2 += fCountX;

		if (fX_Jet2 > 20)
		{
			fX_Jet2 = 30;
		}

		W_Smoke();
		Aircraft();

	//----------------------------------------//Animation of // Green Jet
		glLoadIdentity();					
		glTranslatef(fX_Jet3, fY_Jet3, -20.0f);

		fX_Jet3 += fCountX;
		
		if (fY_Jet3 < -0.325 && fX_Jet3 < 5)
		{
			fY_Jet3 += fCountY;
		}

		if (fY_Jet3 > -0.325 && fX_Jet3 < 5)
		{
			fY_Jet3 = -0.325;
		}

		if (fX_Jet3 > 20)
		{
			fX_Jet3 = 30;
		}

		if (fX_Jet3 > 11)
		{
			fY_Jet3 -= fCountY;
		}

		G_Smoke();
		Aircraft();

	//-----------------------------------------
	}

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
	glTranslatef(-1.55f, y, -6.0f);
	glScalef(0.9f, 1.0f, 0.0f);

	y -= fCount_N;
	if (y <= 0)
	{
		fCount_N = 0;
	}


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
	//Variable Decalrations
	static GLfloat x1 = 0.0f, y1 = 0.0f, z1 = 0.0f;
	static GLfloat x2 = 0.0f, y2 = 0.0f, z2 = 0.0f;
	static GLfloat x3 = 0.0f, y3 = 0.0f, z3 = 0.0f;
	static GLfloat x4 = 0.0f, y4 = 0.0f, z4 = 0.0f;

	static GLdouble fCount_D21 = 0.01;
	static GLdouble fCount_D31 = 0.01;

	static GLdouble fCount_D12 = 0.01;
	static GLdouble fCount_D22 = 0.01;
	static GLdouble fCount_D32 = 0.01;

	static GLdouble fCount_D13 = 0.01;
	static GLdouble fCount_D23 = 0.01;
	static GLdouble fCount_D33 = 0.01;

	static GLdouble fCount_D14 = 0.01;
	static GLdouble fCount_D24 = 0.01;
	static GLdouble fCount_D34 = 0.01;

	glTranslatef(0.0f, 0.0f, -6.0f);

	glBegin(GL_QUADS);
	glColor3f(x1, y1, z1); //1
	glVertex3f(0.4f, 0.7f, 0.0f);
	glVertex3f(-0.5f, 0.7f, 0.0f);

	glColor3f(x2, y2, z2); //2
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.3f, 0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(x1, y1, z1); //1#Orange Curve
	glVertex3f(0.4f, 0.7f, 0.0f);

	glColor3f(x2, y2, z2); //2#OrangeCurve
	glVertex3f(0.3f, 0.5f, 0.0f);
	glVertex3f(0.45f, 0.4f, 0.0f);
	glVertex3f(0.65f, 0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(x3, y3, z3);  //3
	glVertex3f(0.3f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glColor3f(x4, y4, z4); //4
	glVertex3f(-0.5f, -0.7f, 0.0f);
	glVertex3f(0.4f, -0.7f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(x4, y4, z4); //3#Green Curve
	glVertex3f(0.4f, -0.7f, 0.0f);

	glColor3f(x3, y3, z3);//4#Green
	glVertex3f(0.3f, -0.5f, 0.0f);
	glVertex3f(0.45f, -0.4f, 0.0f);
	glVertex3f(0.65f, -0.5f, 0.0f);
	glEnd();


	//-----------------------------Left |

	glBegin(GL_QUADS);
	glColor3f(x2, y2, z2); //2
	glVertex3f(0.45f, 0.4f, 0.0f);
	glVertex3f(0.65f, 0.5f, 0.0f);
	
	glColor3f(x3, y3, z3);  //3
	glVertex3f(0.65f, -0.5f, 0.0f);
	glVertex3f(0.45f, -0.4f, 0.0f);
	glEnd();

	//--------------------------------Right |

	glBegin(GL_QUADS);
	glColor3f(x2, y2, z2); //2
	glVertex3f(-0.3f, 0.5f, 0.0f);
	glVertex3f(-0.1f, 0.5f, 0.0f);

	glColor3f(x3, y3, z3); //3
	glVertex3f(-0.1f, -0.5f, 0.0f);
	glVertex3f(-0.3f, -0.5f, 0.0f);
	glEnd();


	// Fade In 
	//----------------------#1
	//glColor3f(1.0f, 0.6f, 0.2f); //1
	x1 += fCount_D11;
	y1 += fCount_D21;
	z1 += fCount_D31;

	if (x1 >= 1 )
	{
		fCount_D11 = 0;
	}

	if (y1 >= 0.6)
	{
		fCount_D21 = 0;
	}
	if (z1 >= 0.2)
	{
		fCount_D31 = 0;
	}

	// Fade In 
	//----------------------#2
	//glColor3f(1.0f, 0.72f, 0.45f);
	x2 += fCount_D12;
	y2 += fCount_D22;
	z2 += fCount_D32;

	if (x2 >= 1)
	{
		fCount_D12 = 0;
	}

	if (y2 >= 0.72)
	{
		fCount_D22 = 0;
	}
	if (z2 >= 0.45)
	{
		fCount_D32 = 0;
	}

	// Fade In 
	//----------------------#3
	//glColor3f(0.59f, 0.92f, 0.054f); //3
	x3 += fCount_D13;
	y3 += fCount_D23;
	z3 += fCount_D33;

	if (x3 >= 0.59)
	{
		fCount_D13 = 0;
	}

	if (y3 >= 0.92)
	{
		fCount_D23 = 0;
	}
	if (z3 >= 0.054)
	{
		fCount_D33 = 0;
	}

	// Fade In 
	//----------------------#4
	//glColor3f(0.074f, 0.533f, 0.0313f); //4
	x4 += fCount_D14;
	y4 += fCount_D24;
	z4 += fCount_D34;

	if (x4 >= 0.074)
	{
		fCount_D14 = 0;
	}

	if (y4 >= 0.533)
	{
		fCount_D24 = 0;
	}
	if (z4 >= 0.0313)
	{
		fCount_D34 = 0;
	}
}

void A(void)
{
	glTranslatef(X_A, 0.0f, -6.0f);

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
	//glColor3f(0.074f, 0.533f, 0.0313f);
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
	//glColor3f(0.074f, 0.533f, 0.0313f);
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

	X_A -= fCount_XA;
	if (X_A < 2.45)
	{
		fCount_XA = 0;
	}


}

void Aircraft(void)
{
	//Functions Declarations
	void Logo(void);

	glLineWidth(2);

	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_TRIANGLES);
	glVertex3f(2.25f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.25f, 0.0f);
	glVertex3f(0.85f, -0.1f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(2.5f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //Upper
	glVertex3f(1.0f, 0.25f, 0.0f);
	glVertex3f(-1.5f, 0.3f, 0.0f);
	glVertex3f(-1.95f, 0.0f, 0.0f);
	glVertex3f(2.25f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //Lower
	glVertex3f(2.25f, 0.0f, 0.0f);
	glVertex3f(-1.95f, 0.0f, 0.0f);
	glVertex3f(-1.95f, -0.2f, 0.0f);
	glVertex3f(0.85f, -0.1f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); //Missile Attached
	glVertex3f(0.1f, -0.02f, 0.0f);
	glVertex3f(-0.1f, -0.02f, 0.0f);
	glVertex3f(-0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glEnd();

	//-------------------------------//Missile
	glBegin(GL_QUADS);
	glVertex3f(0.5f, -0.2f, 0.0f);
	glVertex3f(-0.5f, -0.2f, 0.0f);
	glVertex3f(-0.5f, -0.32f, 0.0f);
	glVertex3f(0.5f, -0.32f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.8f, -0.26f, 0.0f);
	glVertex3f(0.5f, -0.2f, 0.0f);
	glVertex3f(0.5f, -0.32f, 0.0f);
	glEnd();

	//------------------------------------ //Wings

	glColor3f(0.403f, 0.403f, 0.403f);
	glBegin(GL_QUADS);
	glVertex3f(-0.5f, 0.28f, 0.0f);
	glVertex3f(-1.1f, 1.1f, 0.0f);
	glVertex3f(-1.5f, 1.1f, 0.0f);
	glVertex3f(-1.5f, 0.28f, 0.0f);
	glEnd();

	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-0.5f, 0.28f, 0.0f);
	glVertex3f(-1.1f, 1.25f, 0.0f);
	glVertex3f(-1.3f, 1.25f, 0.0f);
	glVertex3f(-1.4f, 0.28f, 0.0f);
	glEnd();


	//-------------------------------IAF

	glBegin(GL_LINES);				// I
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.15f, 0.6f, 0.0f);
	glVertex3f(-1.3f, 0.6f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.225f, 0.6f, 0.0f);
	glVertex3f(-1.225f, 0.4f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.15f, 0.4f, 0.0f);
	glVertex3f(-1.3f, 0.4f, 0.0f);
	glEnd();

	glBegin(GL_LINES);				//A
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.1f, 0.39f, 0.0f);
	glVertex3f(-1.05f, 0.6f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.39f, 0.0f);
	glVertex3f(-1.05f, 0.62f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.075f, 0.475f, 0.0f);
	glVertex3f(-1.01f, 0.475f, 0.0f);
	glEnd();

	glBegin(GL_LINES);					//F
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.925f, 0.61f, 0.0f);
	glVertex3f(-0.925f, 0.39f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.925f, 0.61f, 0.0f);
	glVertex3f(-0.8f, 0.61f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.925f, 0.525f, 0.0f);
	glVertex3f(-0.8f, 0.525f, 0.0f);
	glEnd();
}

void O_Smoke(void)
{
	//-----------------------------------------//Smoke

	glLineWidth(10);

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.9f, 0.7f);
	glVertex3f(-2.2f, -0.0f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(-1.9f, -0.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.9f, 0.7f);
	glVertex3f(-2.3f, -0.05f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(-1.9f, -0.05f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.9f, 0.7f);
	glVertex3f(-2.4f, -0.1f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(-1.9f, -0.1f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.9f, 0.7f);
	glVertex3f(-2.3f, -0.15f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(-1.9f, -0.15f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.9f, 0.7f);
	glVertex3f(-2.2f, -0.18f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(-1.9f, -0.18f, 0.0f);
	glEnd();

}

void W_Smoke(void)
{
	//-----------------------------------------//Smoke

	glLineWidth(10);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	
	glVertex3f(-2.2f, -0.0f, 0.0f);
	
	glVertex3f(-1.9f, -0.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	
	glVertex3f(-2.3f, -0.05f, 0.0f);
	
	glVertex3f(-1.9f, -0.05f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	
	glVertex3f(-2.4f, -0.1f, 0.0f);
	
	glVertex3f(-1.9f, -0.1f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	
	glVertex3f(-2.3f, -0.15f, 0.0f);
	
	glVertex3f(-1.9f, -0.15f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	
	glVertex3f(-2.2f, -0.18f, 0.0f);
	
	glVertex3f(-1.9f, -0.18f, 0.0f);
	glEnd();

}

void G_Smoke(void)
{
	glLineWidth(10);

	glBegin(GL_LINES);
	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-2.2f, -0.0f, 0.0f);
	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(-1.9f, -0.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-2.3f, -0.05f, 0.0f);
	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(-1.9f, -0.05f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-2.4f, -0.1f, 0.0f);
	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(-1.9f, -0.1f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-2.3f, -0.15f, 0.0f);
	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(-1.9f, -0.15f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.59f, 0.92f, 0.054f);
	glVertex3f(-2.2f, -0.18f, 0.0f);
	glColor3f(0.074f, 0.533f, 0.0313f);
	glVertex3f(-1.9f, -0.18f, 0.0f);
	glEnd();

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
