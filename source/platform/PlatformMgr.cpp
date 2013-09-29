#include "PlatformMgr.h"



#ifdef _PLATFORM_WIN_
#	include "platform\PlatformWin32.h"
#endif

#ifdef _PLATFORM_MACOSX_
#	include "platform\PlatformMacOSX.h"
#endif

#ifdef _PLATFORM_LINUX_
#	include "platform\PlatformLinux.h"
#endif

using namespace v3d;
using namespace platform;

CPlatformMgr::CPlatformMgr()
{
}

CPlatformMgr::~CPlatformMgr()
{
}

CPlatform* CPlatformMgr::createWindow(const WindowSize& size, bool isFullscreen, bool isResizeble)
{
	CPlatform* platform = nullptr;

	PlatformParam param;
	param.windowSize   = size;
	param.isFullscreen = isFullscreen;
	param.isResizeble  = isFullscreen ? false : isResizeble;

#ifdef _PLATFORM_WIN_
	param.platformType = EPlatformType::ePlatformWindows;
	platform = new CPlatformWin32(param);
#endif

#ifdef _PLATFORM_MACOSX_
	param.platformType = EPlatformType::ePlatformMacOSX;
	platform = new CPlatformMacOSX(param);
#endif

#ifdef _PLATFORM_LINUX_
	param.platformType = EPlatformType::ePlatformLinux;
	platform = new CPlatformLinux(param);
#endif

	return platform;
}

CPlatform* CPlatformMgr::createWindowWithDriver()
{
	//
	return nullptr;
}