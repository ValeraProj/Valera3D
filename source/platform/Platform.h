#ifndef _V3D_PLATFORM_MANAGER_H_
#define _V3D_PLATFORM_MANAGER_H_

#include "Window.h"

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CPlatform
	{
	public:
		CPlatform();
		~CPlatform();

		static CWindow* createWindowWithContext(
			const core::Dimension2D& size = core::Dimension2D(800U, 600),
			bool isFullscreen             = false,
			bool isResizeble              = false,
			EDriverType driverType        = EDriverType::eDriverOpenGL
			);
		
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////s
}
}
#endif