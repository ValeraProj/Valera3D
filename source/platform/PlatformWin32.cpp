#include "PlatformWin32.h"

#include <winuser.h>

using namespace v3d;
using namespace platform;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

CPlatformWin32::CPlatformWin32(const PlatformParam& param)
	: CPlatform(param)
{
	CPlatformWin32::createWindows();

	CPlatformWin32::setResizeble(m_param.isResizeble);
	CPlatformWin32::setFullScreen(m_param.isFullscreen);
}

CPlatformWin32::~CPlatformWin32()
{
}

void CPlatformWin32::minimizeWindow()
{
	WINDOWPLACEMENT wndpl;
	wndpl.length = sizeof(WINDOWPLACEMENT);
	GetWindowPlacement((HWND)m_windowID, &wndpl);
	wndpl.showCmd = SW_SHOWMINNOACTIVE;
	SetWindowPlacement((HWND)m_windowID, &wndpl);
}

void CPlatformWin32::maximizeWindow()
{
	WINDOWPLACEMENT wndpl;
	wndpl.length = sizeof(WINDOWPLACEMENT);
	GetWindowPlacement((HWND)m_windowID, &wndpl);
	wndpl.showCmd = SW_SHOWMAXIMIZED;
	SetWindowPlacement((HWND)m_windowID, &wndpl);
}

void CPlatformWin32::restoreWindow()
{
	WINDOWPLACEMENT wndpl;
	wndpl.length = sizeof(WINDOWPLACEMENT);
	GetWindowPlacement((HWND)m_windowID, &wndpl);
	wndpl.showCmd = SW_SHOWNORMAL;
	SetWindowPlacement((HWND)m_windowID, &wndpl);
}

void CPlatformWin32::setResizeble( bool value )
{
	if  (m_param.isFullscreen || m_param.isResizeble == value)
	{
		return;
	}

	LONG_PTR style = WS_POPUP;
	if (value)
	{
		style = WS_THICKFRAME | WS_SYSMENU | WS_CAPTION | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	}
	else
	{
		style = WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	}
	SetWindowLongPtr((HWND)m_windowID, GWL_STYLE, style);

	RECT clientSize;
	clientSize.top    = 0;
	clientSize.left   = 0;
	clientSize.right  = m_param.windowSize.x;
	clientSize.bottom = m_param.windowSize.y;

	AdjustWindowRect(&clientSize, style, FALSE);

	const s32 realWidth  = clientSize.right - clientSize.left;
	const s32 realHeight = clientSize.bottom - clientSize.top;

	const s32 windowLeft = (GetSystemMetrics(SM_CXSCREEN) - realWidth) / 2;
	const s32 windowTop  = (GetSystemMetrics(SM_CYSCREEN) - realHeight) / 2;

	SetWindowPos((HWND)m_windowID, HWND_TOP, windowLeft, windowTop, realWidth, realHeight,
		SWP_FRAMECHANGED | SWP_NOMOVE | SWP_SHOWWINDOW);

	m_param.isResizeble = value;

}

void CPlatformWin32::setFullScreen( bool value )
{
	LONG_PTR style = WS_POPUP;
	if (!value)
	{
		style = WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	}
	SetWindowLongPtr((HWND)m_windowID, GWL_STYLE, style);

	RECT clientSize;
	clientSize.top    = 0;
	clientSize.left   = 0;
	clientSize.right  = m_param.windowSize.x;
	clientSize.bottom = m_param.windowSize.y;

	AdjustWindowRect(&clientSize, style, FALSE);

	const s32 realWidth  = clientSize.right - clientSize.left;
	const s32 realHeight = clientSize.bottom - clientSize.top;

	const s32 windowLeft = (GetSystemMetrics(SM_CXSCREEN) - realWidth) / 2;
	const s32 windowTop  = (GetSystemMetrics(SM_CYSCREEN) - realHeight) / 2;

	if (value)
	{
		SetWindowPos((HWND)m_windowID, HWND_TOP, 0, 0, realWidth, realHeight, SWP_SHOWWINDOW);

		DEVMODE dmScreenSettings;
		EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dmScreenSettings);
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth  = m_param.windowSize.x;
		dmScreenSettings.dmPelsHeight = m_param.windowSize.y;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;
	
		LONG res = ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
		if (res != DISP_CHANGE_SUCCESSFUL)
		{
			// try again without forcing display frequency
			dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
			res = ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
		}
	}
	else
	{
		LONG res = ChangeDisplaySettings(NULL, 0);
		
		SetWindowPos((HWND)m_windowID, HWND_TOP, windowLeft, windowTop, realWidth, realHeight,
			SWP_FRAMECHANGED | SWP_NOMOVE | SWP_SHOWWINDOW);
	}

	m_param.isFullscreen = value;
}

bool CPlatformWin32::isWindowMaximized() const
{
	WINDOWPLACEMENT plc;
	plc.length = sizeof(WINDOWPLACEMENT);
	
	bool ret = false;
	if (GetWindowPlacement((HWND)m_windowID, &plc))
	{
		ret = (plc.showCmd & SW_SHOWMAXIMIZED) != 0;
	}

	return ret;
}

bool CPlatformWin32::isWindowMinimized() const
{
	WINDOWPLACEMENT plc;
	plc.length = sizeof(WINDOWPLACEMENT);
	
	bool ret = false;
	if (GetWindowPlacement((HWND)m_windowID, &plc))
	{
		ret = (plc.showCmd & SW_SHOWMINIMIZED) != 0;
	}

	return ret;
}

bool CPlatformWin32::isWindowActive() const
{
	bool ret = (GetActiveWindow() == (HWND)m_windowID);
	return ret;
}

bool CPlatformWin32::isWindowFocused() const
{
	bool ret = (GetFocus() == (HWND)m_windowID);
	return ret;
}

void CPlatformWin32::setWindowCaption(const char* text)
{
	SetWindowTextA((HWND)m_windowID, text);
}

void CPlatformWin32::setWindowCaption(const wchar_t* text)
{
	SetWindowText((HWND)m_windowID, text);
}

void CPlatformWin32::mainLoop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//Driver()->run();
		//SwapBuffers( hDC );
	}

	return;
}

void CPlatformWin32::createWindows()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	LPCWSTR className = __TEXT("ValeraWin32");

	// Register Class
	WNDCLASSEX wcex;
	wcex.cbSize         = sizeof(WNDCLASSEX);
	wcex.style          = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = NULL;
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hIcon          = LoadIcon(NULL, IDI_WINLOGO);
	wcex.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName   = NULL;
	wcex.lpszClassName  = className;
	wcex.hIconSm        = 0;
	
	RegisterClassEx(&wcex);

	
	// calculate client size
	RECT clientSize;
	clientSize.top    = 0;
	clientSize.left   = 0;
	clientSize.right  = m_param.windowSize.x;
	clientSize.bottom = m_param.windowSize.y;

	DWORD dwStyle   = WS_POPUP;
	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

	if ( !m_param.isFullscreen )
	{
		dwStyle   = WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
		dwExStyle = WS_EX_APPWINDOW;
	}

	AdjustWindowRectEx(&clientSize, dwStyle, FALSE, dwExStyle);

	const s32 realWidth = clientSize.right - clientSize.left;
	const s32 realHeight = clientSize.bottom - clientSize.top;
	s32 windowLeft = (GetSystemMetrics(SM_CXSCREEN) - realWidth) / 2;
	s32 windowTop  = (GetSystemMetrics(SM_CYSCREEN) - realHeight) / 2;

	if ( windowLeft < 0 )
	{
		windowLeft = 0;
	}
	if ( windowTop < 0 )
	{
		windowTop = 0;
	}

	if ( m_param.isFullscreen )
	{
		windowLeft = 0;
		windowTop  = 0;
	}

	// create window
	HWND HWnd = CreateWindowEx( dwExStyle, className, __TEXT(""), dwStyle, windowLeft, windowTop, 
					realWidth, realHeight, NULL, NULL, hInstance, NULL );
	m_windowID = HWnd;

	ShowWindow(HWnd, SW_SHOWNORMAL);
	UpdateWindow(HWnd);
	
	
	//createDriver();
}

void CPlatformWin32::closeWindow()
{
	MSG msg;
	PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE);
	PostQuitMessage(0);
	PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE);
	
	DestroyWindow((HWND)m_windowID);
	HINSTANCE hInstance = GetModuleHandle(0);
	UnregisterClass(__TEXT("ValeraWin32"), hInstance);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	case WM_KEYDOWN:
	case WM_KEYUP:
		{
			//
			return 0;
		}
		
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
	case WM_MOUSEMOVE:
	case WM_MOUSEWHEEL:
		{
			//
			return 0;
		}
		
	case WM_SIZE:
		{
			//
			return 0;
		}
		
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		
	case WM_ACTIVATE:
		{
			//
			return 0;
		}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}