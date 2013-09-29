#ifndef _V3D_PLATFORM_MAC_OSX_H_
#define _V3D_PLATFORM_MAC_OSX_H_

#include "Platform.h"

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CPlatformMacOSX : public CPlatform
	{
	public:
						CPlatformMacOSX( const PlatformParam& param );
		virtual			~CPlatformMacOSX();

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