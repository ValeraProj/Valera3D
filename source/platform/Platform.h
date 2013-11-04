#ifndef _V3D_PLATFORM_H_
#define _V3D_PLATFORM_H_

#include "common.h"

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class EDriverType
	{
		eDriverNull = -1,
		eDriverOpenGL,
		eDriverDirect3D,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class EPlatformType
	{
		ePlatformNull = -1,
		ePlatformWindows,
		ePlatformLinux,
		ePlatformMacOSX,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct PlatformParam
	{
		EDriverType       driverType;
		core::Dimension2D windowSize;
		bool              isFullscreen;
		bool              isResizeble;
		
		PlatformParam()
			: driverType(EDriverType::eDriverNull)
			, windowSize(core::Dimension2D(800U, 600U))
			, isFullscreen(false)
			, isResizeble(false)
		{
		}
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CPlatform
	{
	public:
									CPlatform( const PlatformParam& param );
		virtual						~CPlatform();
		
		virtual void				minimizeWindow  ()                           = 0;
		virtual void				maximizeWindow  ()                           = 0;
		virtual void				restoreWindow   ()                           = 0;
		virtual void				setFullScreen   ( bool value = true )        = 0;
		virtual void				setResizeble    ( bool value = true )        = 0;
		virtual void				setWindowCaption( const std::string& text )  = 0;
		virtual void				setWindowCaption( const std::wstring& text ) = 0;
		

		virtual bool				isWindowMaximized() const                    = 0;
		virtual bool				isWindowMinimized() const                    = 0;
		virtual bool				isWindowActive()    const                    = 0;
		virtual bool				isWindowFocused()   const                    = 0;
		bool						isFullscreen()      const;
		bool						isResizeble()       const;
		const core::Dimension2D&	getWindowsSize()    const;
		EPlatformType				getPlatformType()   const;

		virtual bool				begin()                                      = 0;
		virtual bool				end()                                        = 0;

	protected:

		PlatformParam				m_param;
		EPlatformType				m_platformType;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif