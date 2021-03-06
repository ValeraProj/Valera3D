#include "Platform.h"

#ifdef _PLATFORM_WIN_
#	include "platform/WindowWin32.h"
#endif

#ifdef _PLATFORM_MACOSX_
#	include "platform/WindowMacOSX.h"
#endif

#ifdef _PLATFORM_LINUX_
#	include "platform/PlatformLinux.h"
#endif

#ifdef _OPENGL_DRIVER_
#	include "context/DriverContextGL.h"
#endif


using namespace v3d;
using namespace v3d::platform;

CPlatform::CPlatform()
{
}

CPlatform::~CPlatform()
{
}

CWindowPtr CPlatform::createWindowWithContext(const core::Dimension2D& size, const core::Dimension2D& pos,
	bool isFullscreen, bool isResizeble, EDriverType driverType )
{
	CWindowPtr window = nullptr;

	WindowParam param;
	param.size = size;
	param.position = pos;
	param.isFullscreen = isFullscreen;
	param.isResizeble  = isFullscreen ? false : isResizeble;
	param.driverType   = driverType;

#ifdef _PLATFORM_WIN_
	window = std::make_shared<CWindowWin32>(CWindowWin32(param));
#endif

#ifdef _PLATFORM_MACOSX_
	window = std::make_shared<CWindowMacOSX>(CWindowMacOSX(param));
#endif

#ifdef _PLATFORM_LINUX_
	window = new CPlatformLinux(param);
#endif

	window->create();

	window->setResizeble(param.isResizeble);
	window->setFullScreen(param.isFullscreen);

	renderer::CDriverContext* driver = nullptr;
	
	switch (param.driverType)
	{
		case EDriverType::eDriverOpenGL:
		{
			driver = new renderer::CDriverContextGL(window);
		}
		break;

		case EDriverType::eDriverDirect3D:
		{
			//driver = new renderer::CDriverContextD3D(this);
		}
		break;

		default:
		{
			//Wrong Driver Context
			window->close();
			system("pause");

			return nullptr;
		}
		break;
	}

	if (!driver->createContext())
	{
		//Error crete context
		window->close();
		system("pause");

		return nullptr;
	}

	m_window = window;

	return window;
}

bool CPlatform::begin()
{
	return m_window->begin();
}

bool CPlatform::end()
{
	return m_window->end();;
}
