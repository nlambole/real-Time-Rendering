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

int Width;
int Height;

//************* Light / Texure*************
bool gbLight = true;


//Light Arrays
GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
//GLfloat LightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 0.0f, 3.0f, 3.0f, 0.0f }; 

//Material Arrays
GLfloat MaterialAmbient[4];
GLfloat MaterialDiffuse[4];
GLfloat MaterialSpecular[4];
GLfloat MaterialShininess = 128.0f;

//Light Model
GLfloat GL_Light_Model_Ambient[] = { 0.2f, 0.2f, 0.2f };
GLfloat GL_Light_Model_Local_Viewer[] = { 0.0f };

//Axis Rotations Variable
GLfloat Angle_xRotation = 0.0f;
GLfloat Angle_yRotation = 0.0f;
GLfloat Angle_zRotation = 0.0f;

GLUquadric* quadric[24];

//Toggle
GLint KeyPressed = 0;

//*******************************************

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
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("24 Spheres : Nandlal Lambole"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, Width, Height, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
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
			if (gbLight == false)
			{
				glEnable(GL_LIGHTING);
				gbLight = true;
			}
			else
			{
				glDisable(GL_LIGHTING);
				gbLight = false;
			}
			break;

		case 'x':
		case 'X':
			KeyPressed = 1;
			Angle_xRotation = 0.0f;
			break;

		case 'y':
		case 'Y':
			KeyPressed = 2;
			Angle_yRotation = 0.0f;
			break;

		case 'z':
		case 'Z':
			KeyPressed = 3;
			Angle_zRotation = 0.0f;
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

	//Automatic Normals
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightAmbient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, LightAmbient);
	//_________________________________________*LIGHT*_________________________________________
	//Light 
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient); //f - float. v- Vector
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular); 

	glEnable(GL_LIGHT0); //Enable Light
	//__________________________________________________________________________________________

	for (int i = 0; i < 24; i++)
	{
		quadric[i] = gluNewQuadric();
	}

	//SetClearColour
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

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
	if (Width <= Height)
	{
		glOrtho(0.0f, 15.5f, 0.0f, (GLdouble)15.5f * ((GLfloat)Height / (GLfloat)Width), -10.0f, 10.0f);
	}
	else
	{
		glOrtho(0.0f, (GLdouble)15.5f * ((GLfloat)Width / (GLfloat)Height), 0.0f, 15.5f , -10.0f, 10.0f);
	}
}

void Display(void)
{
	//Function Declarations
	void Draw_24_Sphere(void);

	//Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -0.55f);
	
	if (KeyPressed == 1)
	{
		Angle_xRotation += 1.0f;
		glRotatef(Angle_xRotation, 1.0f, 0.0f, 0.0f);
		LightPosition[1] = Angle_xRotation;
		
	}
	else if (KeyPressed == 2)
	{
		Angle_yRotation += 1.0f;
		glRotatef(Angle_yRotation, 0.0f, 1.0f, 0.0f);
		LightPosition[2] = Angle_yRotation;
		
	}
	else if (KeyPressed == 3)
	{
		Angle_zRotation += 1.0f;
		glRotatef(Angle_zRotation, 0.0f, 0.0f, 1.0f);
		LightPosition[0] = Angle_zRotation;
		
	}

	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

	Draw_24_Sphere();

	SwapBuffers(ghdc); //Native API for Windowing
}

void Draw_24_Sphere(void)
{
	/*glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-100.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -100.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	glEnd();*/


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

/*-----------------------Emerald--------------------------*/
	MaterialAmbient[0] = 0.0215f;
	MaterialAmbient[1] = 0.1745f;
	MaterialAmbient[2] = 0.0215f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.07568f;
	MaterialDiffuse[1] = 0.61424f;
	MaterialDiffuse[2] = 0.07568f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.633f;
	MaterialSpecular[1] = 0.727811f;
	MaterialSpecular[2] = 0.633f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);

	MaterialShininess = 0.6f * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, MaterialShininess);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 14.0f, 0.0f);
	gluSphere(quadric[0], 1.0f, 30, 30);

/*-----------------------Jade--------------------------*/
	MaterialAmbient[0] = 0.135f;
	MaterialAmbient[1] = 0.2225f;
	MaterialAmbient[2] = 0.1575f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.54f;
	MaterialDiffuse[1] = 0.89f;
	MaterialDiffuse[2] = 0.63f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.316228f;
	MaterialSpecular[1] = 0.316228f;
	MaterialSpecular[2] = 0.316228f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);

	MaterialShininess = 0.1f * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(15.0f, 14.0f, 0.0f);
	gluSphere(quadric[1], 1.0f, 30, 30);

	/*-----------------------Obsidian--------------------------*/
	MaterialAmbient[0] = 0.05375f;
	MaterialAmbient[1] = 0.05f;
	MaterialAmbient[2] = 0.06625f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.18275f;
	MaterialDiffuse[1] = 0.17f;
	MaterialDiffuse[2] = 0.022525f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.332741f;
	MaterialSpecular[1] = 0.328634f;
	MaterialSpecular[2] = 0.346435f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);

	MaterialShininess = 0.1f * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(20.0f, 14.0f, 0.0f);
	gluSphere(quadric[2], 1.0f, 30, 30);

	/*-----------------------Pearl--------------------------*/
	MaterialAmbient[0] = 0.25f;
	MaterialAmbient[1] = 0.20725f;
	MaterialAmbient[2] = 0.20725f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 1.0f;
	MaterialDiffuse[1] = 0.829f;
	MaterialDiffuse[2] = 0.829f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.296648f;
	MaterialSpecular[1] = 0.296648f;
	MaterialSpecular[2] = 0.296648f;
	MaterialSpecular[3] = 0.296648f;
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);

	MaterialShininess = 0.088f * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(25.0f, 14.0f, 0.0f);
	gluSphere(quadric[3], 1.0f, 30, 30);

	/*-----------------------Ruby--------------------------*/
	MaterialAmbient[0] = 0.1745f;
	MaterialAmbient[1] = 0.01175f;
	MaterialAmbient[2] = 0.01175f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.61424f;
	MaterialDiffuse[1] = 0.04136f;
	MaterialDiffuse[2] = 0.04136f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.727811f;
	MaterialSpecular[1] = 0.626959f;
	MaterialSpecular[2] = 0.626959f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);

	MaterialShininess = 0.6f * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 11.5f, 0.0f);
	gluSphere(quadric[4], 1.0f, 30, 30);

	/*-----------------------Turquoise--------------------------*/
	MaterialAmbient[0] = 0.1f;
	MaterialAmbient[1] = 0.18725f;
	MaterialAmbient[2] = 0.1745f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.396f;
	MaterialDiffuse[1] = 0.74151f;
	MaterialDiffuse[2] = 0.69102f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.297254f;
	MaterialSpecular[1] = 0.30829f;
	MaterialSpecular[2] = 0.306678f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);

	MaterialShininess = 0.1f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(15.0f, 11.5f, 0.0f);
	gluSphere(quadric[5], 1.0f, 30, 30);
	

	/*-----------------------Brass--------------------------*/
	MaterialAmbient[0] = 0.329412f;
	MaterialAmbient[1] = 0.223529f;
	MaterialAmbient[2] = 0.027451f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.780392f;
	MaterialDiffuse[1] = 0.568627f;
	MaterialDiffuse[2] = 0.113725f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.992157f;
	MaterialSpecular[1] = 0.941176f;
	MaterialSpecular[2] = 0.807843f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.21794872f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(20.0f, 11.5f, 0.0f);
	gluSphere(quadric[6], 1.0f, 30, 30);

	/*-----------------------Bronze--------------------------*/
	MaterialAmbient[0] = 0.2125f;
	MaterialAmbient[1] = 0.1275f;
	MaterialAmbient[2] = 0.054f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.714f;
	MaterialDiffuse[1] = 0.4284f;
	MaterialDiffuse[2] = 0.18144f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.393548f;
	MaterialSpecular[1] = 0.271906f;
	MaterialSpecular[2] = 0.166721f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.2f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(25.0f, 11.5f, 0.0f);
	gluSphere(quadric[7], 1.0f, 30, 30);

	/*-----------------------Chrome--------------------------*/
	MaterialAmbient[0] = 0.25f;
	MaterialAmbient[1] = 0.25f;
	MaterialAmbient[2] = 0.25f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.4f;
	MaterialDiffuse[1] = 0.4f;
	MaterialDiffuse[2] = 0.4f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.774597f;
	MaterialSpecular[1] = 0.774597f;
	MaterialSpecular[2] = 0.774597f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.6f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 9.0f, 0.0f);
	gluSphere(quadric[8], 1.0f, 30, 30);

	/*-----------------------Copper--------------------------*/
	MaterialAmbient[0] = 0.19125f;
	MaterialAmbient[1] = 0.0735f;
	MaterialAmbient[2] = 0.225f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.7038f;
	MaterialDiffuse[1] = 0.27048f;
	MaterialDiffuse[2] = 0.0828f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.256777f;
	MaterialSpecular[1] = 0.137622f;
	MaterialSpecular[2] = 0.086014f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.1f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(15.0f, 9.0f, 0.0f);
	gluSphere(quadric[9], 1.0f, 30, 30);

	/*-----------------------Gold--------------------------*/
	MaterialAmbient[0] = 0.24725f;
	MaterialAmbient[1] = 0.1995f;
	MaterialAmbient[2] = 0.0745f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.75164f;
	MaterialDiffuse[1] = 0.60648f;
	MaterialDiffuse[2] = 0.22648f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.628281f;
	MaterialSpecular[1] = 0.555802f;
	MaterialSpecular[2] = 0.366065f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.4f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(20.0f, 9.0f, 0.0f);
	gluSphere(quadric[10], 1.0f, 30, 30);

	/*-----------------------Silver--------------------------*/
	MaterialAmbient[0] = 0.19225f;
	MaterialAmbient[1] = 0.19225f;
	MaterialAmbient[2] = 0.19225f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.50754f;
	MaterialDiffuse[1] = 0.50754f;
	MaterialDiffuse[2] = 0.50754f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.508273f;
	MaterialSpecular[1] = 0.508273f;
	MaterialSpecular[2] = 0.508273f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.4f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(25.0f, 9.0f, 0.0f);
	gluSphere(quadric[11], 1.0f, 30, 30);

	/*-----------------------Black--------------------------*/
	MaterialAmbient[0] = 0.0f;
	MaterialAmbient[1] = 0.0f;
	MaterialAmbient[2] = 0.0f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.01f;
	MaterialDiffuse[1] = 0.01f;
	MaterialDiffuse[2] = 0.01f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.50f;
	MaterialSpecular[1] = 0.50f;
	MaterialSpecular[2] = 0.50f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.25f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 6.5f, 0.0f);
	gluSphere(quadric[12], 1.0f, 30, 30);

	/*-----------------------Cyan--------------------------*/
	MaterialAmbient[0] = 0.0f;
	MaterialAmbient[1] = 0.1f;
	MaterialAmbient[2] = 0.06f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.00f;
	MaterialDiffuse[1] = 0.50980392f;
	MaterialDiffuse[2] = 0.50980392f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.50196078f;
	MaterialSpecular[1] = 0.50196078f;
	MaterialSpecular[2] = 0.50196078f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.25f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(15.0f, 6.5f, 0.0f);
	gluSphere(quadric[13], 1.0f, 30, 30);

	/*-----------------------Green--------------------------*/
	MaterialAmbient[0] = 0.0f;
	MaterialAmbient[1] = 0.0f;
	MaterialAmbient[2] = 0.0f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.1f;
	MaterialDiffuse[1] = 0.35f;
	MaterialDiffuse[2] = 0.1f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.45f;
	MaterialSpecular[1] = 0.55f;
	MaterialSpecular[2] = 0.45f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.25f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(20.0f, 6.5f, 0.0f);
	gluSphere(quadric[14], 1.0f, 30, 30);

	/*-----------------------Red--------------------------*/
	MaterialAmbient[0] = 0.0f;
	MaterialAmbient[1] = 0.0f;
	MaterialAmbient[2] = 0.0f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.5f;
	MaterialDiffuse[1] = 0.0f;
	MaterialDiffuse[2] = 0.0f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.7f;
	MaterialSpecular[1] = 0.6f;
	MaterialSpecular[2] = 0.6f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.25f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(25.0f, 6.5f, 0.0f);
	gluSphere(quadric[15], 1.0f, 30, 30);

	/*-----------------------White--------------------------*/
	MaterialAmbient[0] = 0.0f;
	MaterialAmbient[1] = 0.0f;
	MaterialAmbient[2] = 0.0f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.55f;
	MaterialDiffuse[1] = 0.55f;
	MaterialDiffuse[2] = 0.55f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.70f;
	MaterialSpecular[1] = 0.70f;
	MaterialSpecular[2] = 0.70f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.25f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 4.0f, 0.0f);
	gluSphere(quadric[16], 1.0f, 30, 30);

	/*-----------------------Yellow Plastic--------------------------*/
	MaterialAmbient[0] = 0.0f;
	MaterialAmbient[1] = 0.0f;
	MaterialAmbient[2] = 0.0f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.55f;
	MaterialDiffuse[1] = 0.55f;
	MaterialDiffuse[2] = 0.0f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.60f;
	MaterialSpecular[1] = 0.60f;
	MaterialSpecular[2] = 0.50f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.25f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(15.0f, 4.0f, 0.0f);
	gluSphere(quadric[17], 1.0f, 30, 30);

	/*-----------------------Black--------------------------*/
	MaterialAmbient[0] = 0.02f;
	MaterialAmbient[1] = 0.02f;
	MaterialAmbient[2] = 0.02f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.01f;
	MaterialDiffuse[1] = 0.01f;
	MaterialDiffuse[2] = 0.01f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.4f;
	MaterialSpecular[1] = 0.4f;
	MaterialSpecular[2] = 0.4f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.078125f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(20.0f, 4.0f, 0.0f);
	gluSphere(quadric[18], 1.0f, 30, 30);

	/*-----------------------Cyan--------------------------*/
	MaterialAmbient[0] = 0.0f;
	MaterialAmbient[1] = 0.05f;
	MaterialAmbient[2] = 0.05f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.4f;
	MaterialDiffuse[1] = 0.5f;
	MaterialDiffuse[2] = 0.5f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.04f;
	MaterialSpecular[1] = 0.7f;
	MaterialSpecular[2] = 0.7f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.078125f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(25.0f, 4.0f, 0.0f);
	gluSphere(quadric[19], 1.0f, 30, 30);

	/*-----------------------Green--------------------------*/
	MaterialAmbient[0] = 0.0f;
	MaterialAmbient[1] = 0.05f;
	MaterialAmbient[2] = 0.05f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.4f;
	MaterialDiffuse[1] = 0.5f;
	MaterialDiffuse[2] = 0.4f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.04f;
	MaterialSpecular[1] = 0.7f;
	MaterialSpecular[2] = 0.04f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.078125f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(10.0f, 1.5f, 0.0f);
	gluSphere(quadric[20], 1.0f, 30, 30);

	/*-----------------------Red--------------------------*/
	MaterialAmbient[0] = 0.05f;
	MaterialAmbient[1] = 0.00f;
	MaterialAmbient[2] = 0.00f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.5f;
	MaterialDiffuse[1] = 0.4f;
	MaterialDiffuse[2] = 0.4f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.7f;
	MaterialSpecular[1] = 0.04f;
	MaterialSpecular[2] = 0.04f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.078125f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(15.0f, 1.5f, 0.0f);
	gluSphere(quadric[21], 1.0f, 30, 30);

	/*-----------------------White--------------------------*/
	MaterialAmbient[0] = 0.05f;
	MaterialAmbient[1] = 0.05f;
	MaterialAmbient[2] = 0.05f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.5f;
	MaterialDiffuse[1] = 0.5f;
	MaterialDiffuse[2] = 0.5f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.7f;
	MaterialSpecular[1] = 0.7f;
	MaterialSpecular[2] = 0.7f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.078125f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(20.0f, 1.5f, 0.0f);
	gluSphere(quadric[22], 1.0f, 30, 30);

	/*-----------------------Yellow Rubber--------------------------*/
	MaterialAmbient[0] = 0.05f;
	MaterialAmbient[1] = 0.05f;
	MaterialAmbient[2] = 0.00f;
	MaterialAmbient[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);

	MaterialDiffuse[0] = 0.5f;
	MaterialDiffuse[1] = 0.5f;
	MaterialDiffuse[2] = 0.4f;
	MaterialDiffuse[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);

	MaterialSpecular[0] = 0.7f;
	MaterialSpecular[1] = 0.7f;
	MaterialSpecular[2] = 0.04f;
	MaterialSpecular[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialSpecular);

	MaterialShininess = 0.078125f * 128;
	glMaterialf(GL_FRONT, GL_DIFFUSE, MaterialShininess);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(25.0f, 1.5f, 0.0f);
	gluSphere(quadric[23], 1.0f, 30, 30);
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

	for (int i = 0; i < 24; i++)
	{
		gluDeleteQuadric(quadric[i]);
		quadric[i] = NULL;
	}
}
