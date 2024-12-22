#ifndef UNICODE
#define UNICODE
#endif


#include <iostream>
#include <windows.h>
#include <CommCtrl.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	// Register the window class.
	const wchar_t CLASS_NAME[] = L"Sample Window Class";

	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	// Create the window.
	HWND mainH = CreateWindowEx(
		WM_LBUTTONDOWN,									// Optional window styles.
		CLASS_NAME,							// Window class
		L"Successful Window Application!!",	// Window text
		WS_OVERLAPPEDWINDOW,				// Window style

		// Size and Position
		CW_USEDEFAULT,		// Horizontal position
		CW_USEDEFAULT,		// vertical position
		800,		// window width
		500,		// window height

		NULL,       // Parent window
		NULL,		// Menu
		hInstance, 	// Instance handle
		NULL		// Additional application data
		);


	// Create the Button
	HWND hwndButton = CreateWindow(
		L"BUTTON",		// Class
		L"OK",			// Button text
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,// styles
		
		// Location and Size
		10, 10, 110, 50,
		mainH,			// Parent Window
		NULL,			// menu Handler
		(HINSTANCE)GetWindowLongPtr(mainH, GWLP_HINSTANCE),
		NULL);			// Pointer




	// Create the ComboBox
	HWND hWndComboBox = CreateWindow(
		WC_COMBOBOX,
		TEXT(""),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,

		// pos and size
		100, 100, 200, 200,

		mainH,
		NULL,
		hInstance,
		NULL);


	// ComboBox Item list
	TCHAR powerPlan[4][22] =  
	{
    TEXT("Ultimate Performance"), TEXT("High Performance"),
    TEXT("Power Save"), TEXT("Balanced")  
	};

	TCHAR A[25];
	int k = 0;

	memset(&A,0,sizeof(A));
	for (k = 0; k <= 3; k += 1)
	{
		wcscpy_s(A, sizeof(A)/sizeof(TCHAR), (TCHAR*)powerPlan[k]);

		// Add String to combobox
		SendMessage(hWndComboBox, (UINT) CB_ADDSTRING, (WPARAM) 0, (LPARAM) A);
	}

	// Send the CB_SETCURSEL message to display an initial item
	// in the selection field
	SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)2, (LPARAM)0);




	if (mainH == NULL)
	{
		return 0;
	}

	ShowWindow(mainH, nCmdShow);

	//Run the message loop.

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	POINT pt;

	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	//case WM_LBUTTONDOWN:
	//	{
	//		pt.x = GET_X_LPARAM(lParam);
	//		pt.y = GET_Y_LPARAM(lParam);
	//	}
	//	break;

	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);

			// All painting occurs here, between BeginPaint and EndPaint.

			FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

			EndPaint(hwnd, &ps);
		}
		return 0;
		
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}