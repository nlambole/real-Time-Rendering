//Headers
#include <windows.h>

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
bool gbFullscreen = false;
HWND ghwnd = NULL;
DEVMODE screen = { sizeof(DEVMODE) };
LONG result;


//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)

{
	//Varable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("FullScreen Window");

	// code
	// Initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadIcon(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	
	/*screen.dmPelsWidth = GetSystemMetrics(SM_CXSCREEN);
	screen.dmPelsHeight = GetSystemMetrics(SM_CXSCREEN);
	screen.dmBitsPerPel = 6;
	screen.dmDisplayFrequency = 60;
	screen.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;*/
	

	// Register Abouve Code
	RegisterClassEx(&wndclass);

	// Create Window
	hwnd = CreateWindow(szAppName, TEXT("FullScreen Mode"), WS_OVERLAPPEDWINDOW, (GetSystemMetrics(SM_CXSCREEN) / 2 - 400), (GetSystemMetrics(SM_CYSCREEN) / 2 - 300), 800, 600, NULL, NULL, hInstance, NULL);

	ghwnd = hwnd;

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	// Message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Variable Declaration
	int ToggleFullScreen(void);
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	TCHAR str[] = TEXT("Press F or f for FullScreen Mode !!!");

	// Code
	switch (iMsg)
	{
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(0, 255, 0));
		DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case 0x46:
		case 0x66:
			ToggleFullScreen();
		
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

/*
int ToggleFullScreen(void)
{
	HDC hdc1 = GetDC(NULL);
	screen.dmSize = sizeof(screen);
	screen.dmPelsWidth = GetDeviceCaps(hdc1, HORZRES);
	screen.dmPelsHeight = GetDeviceCaps(hdc1, VERTRES);
	screen.dmBitsPerPel = GetDeviceCaps(hdc1, BITSPIXEL);
	screen.dmDisplayFrequency = GetDeviceCaps(hdc1, VREFRESH);
	ReleaseDC(NULL, hdc1);

	result = ChangeDisplaySettings(&screen, CDS_FULLSCREEN);
	if (result == DISP_CHANGE_SUCCESSFUL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}

}
*/