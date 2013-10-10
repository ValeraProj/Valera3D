#ifndef _V3D_PLATFORM_LINUX_H_
#define _V3D_PLATFORM_LINUX_H_

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
		virtual void	setResizeble ( bool value = true );
		virtual void	setWindowCaption( const std::string& text );
		virtual void	setWindowCaption( const std::wstring& text );

		virtual bool	isWindowMaximized() const;
		virtual bool	isWindowMinimized() const;
		virtual bool	isWindowActive()    const;
		virtual bool	isWindowFocused()   const;

		virtual void	mainLoop();

	protected:

		virtual void	createWindows();
		virtual void	closeWindow();

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif