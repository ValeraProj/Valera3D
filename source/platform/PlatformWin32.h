#ifndef _PLATFORM_WIN32_H_
#define _PLATFORM_WIN32_H_

#include "Platform.h"
#include <windows.h>

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CPlatformWin32 : public CPlatform
	{
	public:
						CPlatformWin32( const PlatformParam& param );
		virtual			~CPlatformWin32();

		virtual void	minimizeWindow();
		virtual void	maximizeWindow();
		virtual void	restoreWindow();
		virtual void	setFullScreen( bool value = false );
		virtual void	setResizeble( bool value = true );
		virtual void	setWindowCaption( const wchar_t* text );
		virtual void	setWindowCaption( const char* text );

		virtual bool	isWindowMaximized() const;
		virtual bool	isWindowMinimized() const;
		virtual bool	isWindowActive()    const;
		virtual bool	isWindowFocused()   const;

	protected:

		virtual void	mainLoop();

		virtual void	createWindows();
		virtual void	closeWindow();

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif