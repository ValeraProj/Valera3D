#ifndef _V3D_PLATFORM_WIN32_H_
#define _V3D_PLATFORM_WIN32_H_

#include "Platform.h"
#include <windows.h>

namespace v3d
{
namespace renderer
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class	CDriverContextGL;

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
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
		virtual void	setResizeble ( bool value = true );
		virtual void	setWindowCaption( const std::string& text );
		virtual void	setWindowCaption( const std::wstring& text );

		virtual bool	isWindowMaximized() const;
		virtual bool	isWindowMinimized() const;
		virtual bool	isWindowActive()    const;
		virtual bool	isWindowFocused()   const;

		virtual bool	begin();
		virtual bool	end();

	protected:

		friend			renderer::CDriverContextGL;

		virtual void	createWindows();
		virtual void	closeWindow();

		HWND			m_window;
		HDC				m_context;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif