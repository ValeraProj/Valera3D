#ifndef _V3D_PLATFORM_MGR_H_
#define _V3D_PLATFORM_MGR_H_

#include "Platform.h"

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CPlatformMgr
	{
	public:
		CPlatformMgr();
		~CPlatformMgr();

		static CPlatform* createWindow(
			const WindowSize& size = WindowSize(800U, 600),
			bool isFullscreen      = false,
			bool isResizeble       = false
			);
		
		
		static CPlatform* createWindowWithDriver();
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////s
}
}
#endif