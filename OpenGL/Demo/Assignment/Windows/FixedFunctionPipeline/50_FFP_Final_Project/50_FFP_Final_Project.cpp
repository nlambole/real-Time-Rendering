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
#define Pi 3.14159f

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

//GLfloat Y = 0.0f

GLfloat iBody = 0.0f;
GLfloat iSholder = 0.0f;
GLfloat iElbow = 0.0f;


//Cylinder
const GLint Circle_Points = 1500;

GLfloat fRadius_Cake = 1.0f;
GLfloat Angle = 0.0f;
GLfloat fCounter = 0.1f;
GLfloat X = 0.0;
GLfloat X1 = 0.0;
GLfloat Y = 0.0f;
GLfloat Y1 = 1.0f;


//************* Light / Texure*************
bool bLight = true;

//Light Arrays
GLfloat LightAmbient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 0.0f, 0.0f, 100.0f, 1.0f };

//Material Arrays
GLfloat MaterialAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat MaterialDiffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };
GLfloat MaterialSpecular[] = { 0.7f, 0.7f , 0.7f, 1.0f };
GLfloat MaterialShininess = 128.0f;
//*******************************************

GLUquadric* quadric = NULL;

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
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("Light & Material : Nandlal Lambole"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, Width, Height, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
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

		break;

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

	case WM_CHAR:
		switch (wParam)
		{
		case 'L':
		case 'l':
			if (bLight == false)
			{
				glEnable(GL_LIGHTING);
				bLight = true;
			}
			else
			{
				glDisable(GL_LIGHTING);
				bLight = false;
			}
			break;

		case 'B':
			iBody = iBody + 3 % 360;
			break;

		case 'b':
			iBody = iBody - 3 % 360;
			break;


		case 'S':
			iSholder = iSholder + 3 % 360;
			break;

		case 's':
			iSholder = iSholder - 3 % 360;
			break;

		case 'E':
			iElbow = iElbow + 3 % 360;
			break;

		case 'e':
			iElbow = iElbow - 3 % 360;
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

	//************************************_DEPTH_*********************************************
	//Depth Function
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//Accessory Function
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); //Distortion Correction
	//****************************************************************************************

	//SetClearColour
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//_________________________________________*LIGHT*_________________________________________
	//Light 
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient); //f - float. v- Vector
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);

	////Material
	//glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);
	//glMaterialf(GL_FRONT, GL_SHININESS, MaterialShininess);

	glEnable(GL_LIGHT1); //Enable Light
	//__________________________________________________________________________________________

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
	//Variable Declarations
	static GLfloat CenterX = 2.0f;
	static GLfloat CenterY = 0.0f;
	static GLfloat CenterZ = 0.0f;
	static GLfloat Angle = 0.0f;
	static GLfloat fP = 0.0001f;

	//Function Declarastion
	void Humanoid(void);
	void Wings(void);

	//Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 3.0f, CenterX, CenterY, CenterZ, 0.0f, 1.0f, 0.0f);

	CenterX -= 0.001f;
	//CenterZ -= 0.001f;
	// _________________________________________________________________________Bird

	glRotatef((GLfloat)iBody, 0.0f, 1.0f, 0.0f);
	glRotatef((GLfloat)iSholder, 0.0f, 0.0f, 1.0f);
	glRotatef((GLfloat)iElbow, 1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glScalef(0.055f, 0.055f, 0.25f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	glColor3f(0.83f, 0.63f, 0.30f);
	gluSphere(quadric, 0.9f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.0f);
	glTranslatef(0.11f, 0.0f, 0.0f);
	glRotatef((GLfloat)iBody, 0.0f, 1.0f, 0.0f);
	glRotatef((GLfloat)iSholder, 0.0f, 0.0f, 1.0f);
	glRotatef((GLfloat)iElbow, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.0551, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.12, 0.0, 0.0f);
	glScalef(0.2f, 0.0f, 0.2f);
	Wings();
	glScalef(1.0f, 0.0f, -1.0f);
	Wings();
	glPopMatrix();

	// _________________________________________________________________________Humanoid
	
	SwapBuffers(ghdc); //Native API for Windowing
}

void Wings(void)
{
	//glTranslatef(-3.0f, 0.0f, 0.0f);
	
	//Wings
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(1.0f, 0.0, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.2f);
	glVertex3f(0.95f, 0.0f, 0.4f);
	glVertex3f(0.85f, 0.0f, 0.6f);
	glVertex3f(0.75f, 0.0f, 0.8f);
	glVertex3f(0.65f, 0.0f, 0.9f);
	glVertex3f(0.55f, 0.0f, 1.0f);
	glVertex3f(0.45f, 0.0f, 1.2f);
	glVertex3f(0.30f, 0.0f, 1.45f);
	glVertex3f(0.25f, 0.0f, 1.50f);
	glVertex3f(0.25f, 0.0f, 1.55f);
	glVertex3f(0.20f, 0.0f, 1.60f);
	glVertex3f(0.15f, 0.0f, 1.70f);
	glVertex3f(0.10f, 0.0f, 1.75f);
	glVertex3f(0.10f, 0.0f, 1.8f);
	glVertex3f(0.05f, 0.0f, 1.85f);
	glVertex3f(0.0f, 0.0f, 2.0f);
	glVertex3f(-0.2f, 0.0f, 2.25f);

	//Spikes
	glVertex3f(0.10f, 0.0f, 1.6f);
	glVertex3f(-0.15f, -0.0f, 2.0f);
	glVertex3f(0.20f, 0.0f, 1.3f);
	glVertex3f(-0.05f, -0.0f, 1.7f);
	glVertex3f(0.30f, 0.0f, 1.0f);
	glVertex3f(0.15f, 0.0f, 1.2f);
	glVertex3f(0.40f, 0.0f, 0.6f);
	glVertex3f(0.1f, 0.0f, 1.0f);
	glVertex3f(0.35f, 0.0f, 0.3f);
	glVertex3f(0.1f, 0.0f, 0.8f);
	glVertex3f(0.30f, 0.0f, 0.2f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();


}


//void Humanoid(void)
//{
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	quadric = gluNewQuadric();
//
//	//Sphere
//	gluSphere(quadric, 0.2f, 30, 30); //Normals are calculated by gluSphere itself;
//
//}

/*static GLfloat Angle = 0.0f;


	glBegin(GL_LINE_LOOP);
	for (GLint i = 0; i < Circle_Points; i++)
	{
		Angle = 2 * Pi * i / Circle_Points;

		X = fRadius_Cake * (GLfloat)cos(Angle);
		Y = fRadius_Cake * (GLfloat)sin(Angle);

		X1 = fRadius_Cake * (GLfloat)cos(Angle);
		Y1 = fRadius_Cake * (GLfloat)sin(Angle);

		glColor3f(0.701f, 0.462f, 0.274f);
		glVertex3f(X, 1.0f, Y);

		glColor3f(0.4823f, 0.247f, 0.0f);
		glVertex3f(X1, 0.0f, Y1);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
	}
	glEnd();*/

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
