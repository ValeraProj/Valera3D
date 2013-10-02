#include "DriverContextGL.h"

#if defined (_PLATFORM_WIN_)
#	include <windows.h>
#	include <winuser.h>
#endif

using namespace v3d;
using namespace renderer;

CDriverContextGL::CDriverContextGL( platform::CPlatform* platform )
	: CDriverContext(platform)
{
}

CDriverContextGL::~CDriverContextGL()
{
}

void CDriverContextGL::createContext()
{
#if defined (_PLATFORM_WIN_)
	createWin32Context();

#elif defined(_PLATFORM_LINUX_)
	createLinuxContext();
#endif
}

#if defined (_PLATFORM_WIN_)

void CDriverContextGL::createWin32Context()
{
	// Create a window to test antialiasing support
	HINSTANCE hInstance = GetModuleHandle(NULL);
	LPCWSTR className = __TEXT("ValeraWin32GL");

	// Register Class
	WNDCLASSEX wcex;
	wcex.cbSize         = sizeof(WNDCLASSEX);
	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = (WNDPROC)DefWindowProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = NULL;
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName   = 0;
	wcex.lpszClassName  = className;
	wcex.hIconSm        = 0;
	wcex.hIcon          = 0;
	RegisterClassEx(&wcex);

	RECT clientSize;
	clientSize.top    = 0;
	clientSize.left   = 0;
	clientSize.right  = m_platform->getWindowsSize().width;
	clientSize.bottom = m_platform->getWindowsSize().height;

	DWORD style = WS_POPUP;
	if (!m_platform->isFullscreen())
	{
		style = WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	}
	AdjustWindowRect(&clientSize, style, FALSE);

	const s32 realWidth  = clientSize.right - clientSize.left;
	const s32 realHeight = clientSize.bottom - clientSize.top;

	const s32 windowLeft = (GetSystemMetrics(SM_CXSCREEN) - realWidth) / 2;
	const s32 windowTop  = (GetSystemMetrics(SM_CYSCREEN) - realHeight) / 2;

	HWND temp_window = CreateWindow(className, __TEXT(""), style, windowLeft,
			windowTop, realWidth, realHeight, NULL, NULL, hInstance, NULL);

	if (!temp_window)
	{
		//"Cannot create a temporary window."
		UnregisterClass(className, hInstance);
		return;
	}

	HDC HDc = GetDC(temp_window);

	// Set up pixel format descriptor with desired parameters
	PIXELFORMATDESCRIPTOR pfd = 
	{
		sizeof(PIXELFORMATDESCRIPTOR),             // Size Of This Pixel Format Descriptor
		1,                                         // Version Number
		PFD_DRAW_TO_WINDOW |                       // Format Must Support Window
		PFD_SUPPORT_OPENGL |                       // Format Must Support OpenGL
		PFD_DOUBLEBUFFER   |                       // Must Support Double Buffering
		PFD_TYPE_RGBA,                             // Request An RGBA Format
		32,                                        // Select Our Color Depth
		0, 0, 0, 0, 0, 0,                          // Color Bits Ignored
		0,                                         // No Alpha Buffer
		0,                                         // Shift Bit Ignored
		0,                                         // No Accumulation Buffer
		0, 0, 0, 0,	                               // Accumulation Bits Ignored
		24,                                        // Z-Buffer (Depth Buffer)
		0,                                         // Stencil Buffer Depth
		0,                                         // No Auxiliary Buffer
		PFD_MAIN_PLANE,                            // Main Drawing Layer
		0,                                         // Reserved
		0, 0, 0                                    // Layer Masks Ignored
	};

	//GLuint PixelFormat = ChoosePixelFormat(HDc, &pfd);
}

#endif

#if defined(_PLATFORM_LINUX_)

void CDriverContextGL::createLinuxContext()
{
}

#endif