#include "PlatformManager.h"



#ifdef _PLATFORM_WIN_
#	include "platform/PlatformWin32.h"
#endif

#ifdef _PLATFORM_MACOSX_
#	include "platform/PlatformMacOSX.h"
#endif

#ifdef _PLATFORM_LINUX_
#	include "platform/PlatformLinux.h"
#endif

using namespace v3d;
using namespace platform;

CPlatformMgr::CPlatformMgr()
{
}

CPlatformMgr::~CPlatformMgr()
{
}

CPlatform* CPlatformMgr::createWindow(const core::Dimension2D& size, bool isFullscreen, bool isResizeble, EDriverType driverType )
{
	CPlatform* platform = nullptr;

	PlatformParam param;
	param.windowSize   = size;
	param.isFullscreen = isFullscreen;
	param.isResizeble  = isFullscreen ? false : isResizeble;
	param.driverType   = driverType;

#ifdef _PLATFORM_WIN_
	platform = new CPlatformWin32(param);
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

CPlatform* CPlatformMgr::createWindowWithDriver()
{
	//
	return nullptr;
}