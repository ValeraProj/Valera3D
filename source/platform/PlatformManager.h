#ifndef _V3D_PLATFORM_MANAGER_H_
#define _V3D_PLATFORM_MANAGER_H_

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
			const core::Dimension2D& size = core::Dimension2D(800U, 600),
			bool isFullscreen             = false,
			bool isResizeble              = false,
			EDriverType driverType        = EDriverType::eDriverOpenGL
			);
		
		
		static CPlatform* createWindowWithDriver();
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////s
}
}
#endif