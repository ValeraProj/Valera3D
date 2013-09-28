#ifndef _PLATFORM_LINUX_H_
#define _PLATFORM_LINUX_H_

#include "Platform.h"

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CPlatformLinux : public CPlatform
	{
	public:
						CPlatformLinux( const PlatformParam& param );
		virtual			~CPlatformLinux();

		virtual void	minimizeWindow();
		virtual void	maximizeWindow();
		virtual void	restoreWindow();
		virtual void	setFullScreen( bool value = false );
		virtual void	setWindowCaption( const wchar_t* text );

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