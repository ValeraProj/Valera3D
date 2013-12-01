#include "Platform.h"

#ifdef _PLATFORM_WIN_
#	include "platform/WindowWin32.h"
#endif

#ifdef _PLATFORM_MACOSX_
#	include "platform/PlatformMacOSX.h"
#endif

#ifdef _PLATFORM_LINUX_
#	include "platform/PlatformLinux.h"
#endif

using namespace v3d;
using namespace v3d::platform;

CPlatform::CPlatform()
{
}

CPlatform::~CPlatform()
{
}

CWindow* CPlatform::createWindowWithContext(const core::Dimension2D& size, bool isFullscreen, bool isResizeble, EDriverType driverType)
{
	CWindow* platform = nullptr;

	WindowParam param;
	param.windowSize   = size;
	param.isFullscreen = isFullscreen;
	param.isResizeble  = isFullscreen ? false : isResizeble;
	param.driverType   = driverType;

#ifdef _PLATFORM_WIN_
	platform = new CWindowWin32(param);
#endif

#ifdef _PLATFORM_MACOSX_
	platform = new CPlatformMacOSX(param);
#endif

#ifdef _PLATFORM_LINUX_
	platform = new CPlatformLinux(param);
#endif

	platform->setResizeble(param.isResizeble);
	platform->setFullScreen(param.isFullscreen);


	return platform;
}
