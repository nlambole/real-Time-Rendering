//Headers
#include <windows.h>

//global function declarations

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
bool gbFullscreen = false;
HWND ghwnd = NULL;
DEVMODE screen = { sizeof(DEVMODE) };
LONG result = 0;
UINT nNewMode;


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
	// int ToggleFullScreen(void);
	
	//BOOL ChangeResolution(UINT nNewMode, HWND hwnd);
	
	void GetCurrentSettings();
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
			//ChangeResolution(nNewMode, hwnd);
			GetCurrentSettings();
			break;

		default:
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

/*
void GetCurrentSettings(void)
{
	DEVMODE dm = { 0 };
	LONG ret = 0; 
	DWORD i = 0;


	dm.dmSize = sizeof(DEVMODE);
	dm.dmDriverExtra = 0;

	while (EnumDisplaySettings(0, i, &dm))
	{
		if (dm.dmPelsHeight == GetSystemMetrics(SM_CXSCREEN) && dm.dmPelsWidth == GetSystemMetrics(SM_CYSCREEN) && dm.dmBitsPerPel == 32)
		{
			ret = 1;
			break;
		}
		i++;
	}

	if (ret)
	{
		dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;
		ret = ChangeDisplaySettings(&dm, CDS_FULLSCREEN);
		if (ret != DISP_CHANGE_SUCCESSFUL) 
		{
			return;
		}
	}
}*/

void GetCurrentSettings(void)
{
	if (gbFullscreen) 
	{
		DEVMODE screen;
		screen.dmSize = sizeof(DEVMODE);
		screen.dmPelsWidth = GetSystemMetrics(SM_CXSCREEN);
		screen.dmPelsHeight = GetSystemMetrics(SM_CYSCREEN);
		screen.dmBitsPerPel = 32;
		screen.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;
		result = ChangeDisplaySettings(&screen, 0) == DISP_CHANGE_SUCCESSFUL;
	}

	// reset display mode if destination mode is windowed
	if (!gbFullscreen)
		result = ChangeDisplaySettings(0, 0) == DISP_CHANGE_SUCCESSFUL;
	
	//Local Variable Declarations


	MONITORINFO mi = { sizeof(MONITORINFO) };

	//Code
	if (gbFullscreen == false)
	{
		
		

		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && result)
			{
				

				SetWindowLong(ghwnd, GWL_STYLE, (dwStyle & ~WS_OVERLAPPEDWINDOW));
				//SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, (mi.rcMonitor.right - mi.rcMonitor.left), (mi.rcMonitor.bottom - mi.rcMonitor.top), SWP_NOZORDER | SWP_FRAMECHANGED);

				DEVMODE screen;
				screen.dmSize = sizeof(DEVMODE);
				screen.dmPelsWidth = GetSystemMetrics(SM_CXSCREEN);
				screen.dmPelsHeight = GetSystemMetrics(SM_CYSCREEN);
				screen.dmBitsPerPel = 32;
				screen.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

				result = ChangeDisplaySettings(&screen, CDS_FULLSCREEN); //== DISP_CHANGE_SUCCESSFUL;
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




/*
BOOL ChangeResolution(UINT nNewMode, HWND hwnd)
{
	BOOL IsNT;
	UINT nOldMode;
	LONG gnCurrentMode;
	DEVMODE gpDevModes;
	DEVMODE gpCurrentMode;

	nOldMode = gnCurrentMode;
	gnCurrentMode = nNewMode;

	gpCurrentMode = gpDevModes;
	gpCurrentMode += nNewMode;

	if (IsNT())
	{
		EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &screen);
	}

	result = ChangeDisplaySettings(&gpCurrentMode, CDS_TEST);
	
}
*/








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