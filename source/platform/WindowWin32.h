#ifndef _V3D_PLATFORM_WIN32_H_
#define _V3D_PLATFORM_WIN32_H_

#include "Window.h"
#include <windows.h>

namespace v3d
{
namespace platform
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CWindowWin32 : public CWindow
	{
	public:

						CWindowWin32(const WindowParam& param);
		virtual			~CWindowWin32();

		virtual void	minimize();
		virtual void	maximize();
		virtual void	restore();
		virtual void	setFullScreen( bool value = false );
		virtual void	setResizeble ( bool value = true );
		virtual void	setCaption( const std::string& text );

		virtual bool	isMaximized() const;
		virtual bool	isMinimized() const;
		virtual bool	isActive()    const;
		virtual bool	isFocused()   const;

		virtual bool	begin();
		virtual bool	end();

		HWND			getHandleWindow() const;

	protected:

		void			create();
		void			close();

		HWND			m_window;
		HDC				m_context;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif