#ifndef _V3D_PLATFORM_H_
#define _V3D_PLATFORM_H_

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

		CWindowPtr					createWindowWithContext(
										const core::Dimension2D& size = core::Dimension2D(800U, 600),
										const core::Dimension2D& pos  = core::Dimension2D(0U, 0U),
										bool isFullscreen             = false,
										bool isResizeble              = false,
										EDriverType driverType        = EDriverType::eDriverOpenGL );
	
		bool						begin();	//WARN: ?
		bool						end();

	private:

		std::vector<CWindowPtr>		m_windowsList;
		
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	typedef std::shared_ptr<CPlatform>	CPlatformPtr;

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}
#endif