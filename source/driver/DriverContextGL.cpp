#include "DriverContextGL.h"

#include <windows.h>
#include <winuser.h>

#define GLEW_STATIC
#include "glew.h"
#include "wglew.h"

#if defined(_PLATFORM_WIN_)
#	include "platform\PlatformWin32.h"
#elif (_PLATFORM_LINUX_)
#	include "platform\PlatformLinux.h"
#endif

using namespace v3d;
using namespace renderer;

CDriverContextGL::CDriverContextGL( const platform::CPlatform* platform )
	: CDriverContext( platform )
{
}

CDriverContextGL::~CDriverContextGL()
{
}

bool CDriverContextGL::createContext()
{
#if defined(_PLATFORM_WIN_)
	return createWin32Context();

#elif (_PLATFORM_LINUX_)
	return createLinuxContext();

#endif
}

#if defined(_PLATFORM_WIN_)

bool CDriverContextGL::createWin32Context()
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
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
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

	HWND tempWindow = CreateWindow( className, __TEXT(""), style, windowLeft,
			windowTop, realWidth, realHeight, NULL, NULL, hInstance, NULL );

	if (!tempWindow)
	{
		//Cannot create a temp window;
		UnregisterClass(className, hInstance);
		
		return false;
	}

	HDC hDC = GetDC( tempWindow );

	// Set up pixel format descriptor with desired parameters
	PIXELFORMATDESCRIPTOR pfd = {
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

	GLuint pixelFormat;
	pixelFormat = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, pixelFormat, &pfd);
	
	HGLRC hRc = wglCreateContext(hDC);
	if (!hRc)
	{
		//Cannot create a temporary GL rendering context;
		ReleaseDC(tempWindow, hDC);
		DestroyWindow(tempWindow);
		UnregisterClass(className, hInstance);
		
		return false;
	}

	if (!wglMakeCurrent(hDC, hRc))
	{
		//Cannot activate a temporary GL rendering context.
		wglDeleteContext(hRc);
		ReleaseDC(tempWindow, hDC);
		DestroyWindow(tempWindow);
		UnregisterClass(className, hInstance);
		
		return false;
	}

	GLenum error = glewInit();
	if (error !=  GLEW_OK )
	{
		const GLubyte* errorStr = glewGetErrorString(error);
		//"Couldn't initialize GLEW! error errorStr

		return false;
	}

	if( !wglewIsSupported("WGL_ARB_create_context") ||
		!wglewIsSupported("WGL_ARB_pixel_format"  ) || 
		!wglewIsSupported("WGL_ARB_multisample"   )  )
	{
		//"Error Supported GLEW Lib;
		
		return false;	
	}

	int antiAlias = 32;

	f32 fAttributes[] = {0.0f, 0.0f};
	s32 iAttributes[] =
		{
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB,
			WGL_COLOR_BITS_ARB,     24,
			WGL_ALPHA_BITS_ARB,     8,
			WGL_DEPTH_BITS_ARB,     24,
			WGL_STENCIL_BITS_ARB,   0,
			WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
			WGL_STEREO_ARB,         0,
			WGL_PIXEL_TYPE_ARB,     WGL_TYPE_RGBA_ARB,
			WGL_SAMPLES_ARB,        antiAlias,
			WGL_SAMPLE_BUFFERS_ARB, GL_TRUE,
			//WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB, GL_TRUE,
			0, 0,
			0, 0
		};

	GLuint numFormats     = 0;
	GLint  newPixelFormat = 0;
	
	while(numFormats == 0)
	{
		if ( !wglChoosePixelFormatARB( hDC, iAttributes, fAttributes, 1, &newPixelFormat, &numFormats) )
		{
			//Can't Find A Suitable ExPixelFormat.;
		
			return false;
		}

		--iAttributes[21]; //WGL_SAMPLES_ARB, antiAlias
		if (iAttributes[21] < 0)
		{
			//Can't Choose ExPixelFormat.;
			iAttributes[21] = 0;
			break;
		}
	}

	wglMakeCurrent(hDC, NULL);
	wglDeleteContext(hRc);
	ReleaseDC(tempWindow, hDC);
	DestroyWindow(tempWindow);
	UnregisterClass(className, hInstance);

	
	// Get HWND
	HWND window = static_cast<const platform::CPlatformWin32*>(m_platform)->getHandleWindow();
	
	hDC = GetDC( window );
	if (!hDC)
	{
		//Cannot create a GL device context.
		return false;
	}

	if ( newPixelFormat == 0 || !SetPixelFormat(hDC, newPixelFormat, &pfd) )
	{
		//Cannot create ExPixelFormat
		//set default pixel format
		newPixelFormat = ChoosePixelFormat(hDC, &pfd);
		hRc = wglCreateContext(hDC);
	}
	else
	{
		int attribs[] =
		{
			WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
			WGL_CONTEXT_MINOR_VERSION_ARB, 3,
			WGL_CONTEXT_FLAGS_ARB,         WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
			WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
			0
		};

		hRc = wglCreateContextAttribsARB( hDC, 0, attribs );
	}

	if ( !hRc || !wglMakeCurrent(hDC, hRc) )
	{
		//Can't Create GL Rendering Context
		return false;
	}

	int pf = GetPixelFormat(hDC);
	DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	return true;
}

#elif (_PLATFORM_LINUX_)

void CDriverContextGL::createLinuxContext()
{

}

#endif

void CDriverContextGL::driverInfo()
{
	// print renderer information
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* GLSL = glGetString(GL_SHADING_LANGUAGE_VERSION);
	const GLubyte* version = glGetString(GL_VERSION);
	
	GLint maxTextureUnits;
	glGetIntegerv( GL_MAX_TEXTURE_UNITS, &maxTextureUnits );
	//TODO: driver info

	/*glewIsSupported("GL_ARB_multitexture");
	glewIsSupported("GL_ARB_vertex_buffer_object");
	glewIsSupported("GL_ARB_vertex_array_object");
	glewIsSupported("GL_ARB_sampler_objects");*/

}

void CDriverContextGL::checkForErrors( const std::string& error )
{
#ifdef _DEBUG
		GLenum glError = glGetError();
		if ( glError != GL_NO_ERROR )
		{
			//( error << glewGetErrorString(glError));
		}
#endif
}
