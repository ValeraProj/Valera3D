#ifndef _PLATFORM_MGR_H_
#define _PLATFORM_MGR_H_

#include "common.h"

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CPlatform;

	class CPlatformMgr
	{
	public:
		CPlatformMgr();
		~CPlatformMgr();

		static CPlatform* createWindow(
			const Dimension2D& size = Dimension2D(800U, 600),
			bool isFullscreen = false,
			bool isResizeble = false
			);
		
		
		static CPlatform* createWindowWithDriver();
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////s
}
}
#endif