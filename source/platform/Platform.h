#ifndef _V3D_PLATFORM_H_
#define _V3D_PLATFORM_H_

#include "common.h"

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class EPlatformType
	{
		ePlatformNull = -1,
		ePlatformWindows,
		ePlatformLinux,
		ePlatformMacOSX,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct WindowSize
	{
		u32 width;
		u32 height;

		WindowSize( u32 w, u32 h )
			: width(w)
			, height(h)
		{
		}
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct PlatformParam
	{
		EPlatformType   platformType;
		WindowSize      windowSize;
		bool            isFullscreen;
		bool            isResizeble;

		PlatformParam()
			: platformType(EPlatformType::ePlatformNull)
			, windowSize(800U, 600U)
			, isFullscreen(false)
			, isResizeble(false)
		{
		}
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CPlatform
	{
	public:
						CPlatform();
		virtual			~CPlatform();
		
		virtual void	minimizeWindow  ()                           = 0;
		virtual void	maximizeWindow  ()                           = 0;
		virtual void	restoreWindow   ()                           = 0;
		virtual void	setFullScreen   ( bool value = true )        = 0;
		virtual void	setResizeble    ( bool value = true )        = 0;
		virtual void	setWindowCaption( const std::string& text )  = 0;
		virtual void	setWindowCaption( const std::wstring& text ) = 0;
		

		virtual bool	isWindowMaximized() const                    = 0;
		virtual bool	isWindowMinimized() const                    = 0;
		virtual bool	isWindowActive()    const                    = 0;
		virtual bool	isWindowFocused()   const                    = 0;
		virtual bool	isFullscreen()      const                    = 0;
		virtual bool	isResizeble()       const                    = 0;
		
		virtual void	mainLoop()                                   = 0;

	protected:

		virtual void	createWindows()                              = 0;
		virtual void	closeWindow()                                = 0;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif