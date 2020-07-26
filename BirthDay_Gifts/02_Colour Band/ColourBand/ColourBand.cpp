//Headers
#include <windows.h>
#include <stdio.h>
#include "NRL.h"

#pragma comment (lib , "winmm.lib")

#define MYTIMER 1000

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
bool gbFullscreen = false;
HWND ghwnd = NULL;
HINSTANCE hInstance;

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdlie, int iCmdShow)
{

	//Varable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("Centering Window");

	// code
	// Initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
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

	// Register Abouve Codes
	RegisterClassEx(&wndclass);

	// Create Window

	hwnd = CreateWindow(szAppName, TEXT("Nandlal Lambole"), WS_OVERLAPPEDWINDOW , (GetSystemMetrics(SM_CXSCREEN) / 2 - 400), (GetSystemMetrics(SM_CYSCREEN) / 2 - 300), CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
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
	//Function Prototype
	void ToggleFullScreen(void);
	//Variable Declaration

	HDC hdc, hdcBmpDC;
	static int iPaint = -1;
	PAINTSTRUCT ps;
	RECT rc, rc1, rc2;
	static HBRUSH hBrush;
	 static HBITMAP hBmap;

	static BITMAP bitmap;
	TCHAR szBitmap[] = TEXT("Hello World !!!");
	static int left = 0;  //length of prev band
	static int iwidth = 0;  //length of prev band

	// Code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		PlaySound(MAKEINTRESOURCE(MYMUSIC), hInstance, SND_LOOP | SND_RESOURCE | SND_ASYNC);

		GetClientRect(hwnd, &rc);
		hBmap = (HBITMAP)LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(MYBITMAP));

		if (hBmap == NULL)
		{
			MessageBox(hwnd, TEXT("hBmap Failed !!!"), MB_OK, NULL);
			exit(0);
		}
		iPaint = SetTimer(hwnd, MYTIMER, 10000, NULL);

		//if (iPaint == 0)
		///	MessageBox(hwnd, TEXT(" SetTimer() is NOt Set!", "Error"), MB_OK, NULL);
		break;

	case WM_TIMER:
	{
		KillTimer(hwnd, MYTIMER);
		iPaint = iPaint + 1;

		if (iPaint < 8)
		{
			InvalidateRect(hwnd, NULL, FALSE);
		}
		else
		{
			iPaint = 0;
			left = 0;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		SetTimer(hwnd, MYTIMER, 10000, NULL);

	}
	break;

	case WM_SIZE:
		iPaint = 0;
		left = 0;
		InvalidateRect(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
	{
		GetClientRect(hwnd, &rc); //It returns Co-Ordinate Of Window
		iwidth = rc.right / 8;
		if (iPaint < 8)
		{
			rc1.left = left;
			left = iwidth + left;
			rc1.right = left;
			rc1.top = rc.top;
			rc1.bottom = rc.bottom / 2;
			
		}
		else
		{
			rc1.left = left;
			left = (rc.right / 8) + left;
			rc1.right = left;
			rc1.top = rc.bottom/2;
			rc1.bottom = rc.bottom ;
		}
		hdc = BeginPaint(hwnd, &ps);


		switch (iPaint)
		{

		case 0:
			hBrush = CreateSolidBrush(RGB(255, 128, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			hdcBmpDC = CreateCompatibleDC(NULL); 

			SelectObject(hdcBmpDC, hBmap);
			GetObject(hBmap, sizeof(BITMAP), &bitmap);
			StretchBlt(hdc, rc1.left, rc1.top, iwidth, rc1.bottom, hdcBmpDC, 0, 0, bitmap.bmWidth ,bitmap.bmHeight, SRCCOPY);
			DeleteDC(hdcBmpDC);
			break;

		case 1:
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		case 2:
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);

			break;

		case 3:
			hBrush = CreateSolidBrush(RGB(0, 255, 128));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		case 4:
			hBrush = CreateSolidBrush(RGB(128, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		case 5:
			hBrush = CreateSolidBrush(RGB(255, 128, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		case 6:
			hBrush = CreateSolidBrush(RGB(255, 128, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			hdcBmpDC = CreateCompatibleDC(NULL); 
			SelectObject(hdcBmpDC, hBmap);
			GetObject(hBmap, sizeof(BITMAP), &bitmap);
			StretchBlt(hdc, rc1.left, rc1.top, iwidth, rc1.bottom, hdcBmpDC, 0, 0, bitmap.bmWidth ,bitmap.bmHeight, SRCCOPY);
			DeleteDC(hdcBmpDC);
			break;

		case 7:
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		case 8:
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		case 9:
			hBrush = CreateSolidBrush(RGB(0, 255, 128));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		case 10:
			hBrush = CreateSolidBrush(RGB(128, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		case 11:
			hBrush = CreateSolidBrush(RGB(255, 128, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc1, hBrush);
			break;

		default:
			break;
		}
		EndPaint(hwnd, &ps);
		DeleteObject(hBrush);

	}
	
	break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 0x46:
		case 0x66:
			ToggleFullScreen(); //Call
			break;

		default:
			break;
		}
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


