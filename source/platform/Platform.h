#ifndef _PLATFORM_H_
#define _PLATFORM_H_

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
						CPlatform( const PlatformParam& param );
		virtual			~CPlatform();
		
		virtual void	minimizeWindow  ()                      = 0;
		virtual void	maximizeWindow  ()                      = 0;
		virtual void	restoreWindow   ()                      = 0;
		virtual void	setFullScreen   ( bool value = true )   = 0;
		virtual void	setResizeble    ( bool value = true )   = 0;
		virtual void	setWindowCaption( const wchar_t* text ) = 0;
		virtual void	setWindowCaption( const char* text )    = 0;
		

		virtual bool	isWindowMaximized() const               = 0;
		virtual bool	isWindowMinimized() const               = 0;
		virtual bool	isWindowActive()    const               = 0;
		virtual bool	isWindowFocused()   const               = 0;
		bool			isFullscreen()      const;
		bool			isResizeble()       const;
		
		virtual void	mainLoop()                              = 0;

	protected:

		virtual void	createWindows()                         = 0;
		virtual void	closeWindow()                           = 0;

		PlatformParam	m_param;
		void*			m_windowID;
		
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif