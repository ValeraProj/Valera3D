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
		virtual						~CPlatformMacOSX();
		
		virtual void				minimizeWindow  ();
		virtual void				maximizeWindow  ();
		virtual void				restoreWindow   ();
		virtual void				setFullScreen   ( bool value = true );
		virtual void				setResizeble    ( bool value = true );
		virtual void				setWindowCaption( const std::string& text );
        
		virtual bool				isWindowMaximized() const;
		virtual bool				isWindowMinimized() const;
		virtual bool				isWindowActive()    const;
		virtual bool				isWindowFocused()   const;
		const core::Dimension2D&	getWindowsSize()    const;
		EPlatformType				getPlatformType()   const;
        
		virtual bool				begin();
		virtual bool				end();

	protected:

		void                        createWindows();
		void                        closeWindow();

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif