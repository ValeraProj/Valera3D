#ifndef _V3D_DRIVER_CONTEXT_H_
#define _V3D_DRIVER_CONTEXT_H_

#include "common.h"
#include "platform/Window.h"

namespace v3d
{
namespace renderer
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CDriverContext
	{
	public:

									CDriverContext( const platform::CWindow* window );
		virtual						~CDriverContext();

		virtual void				driverInfo()                               = 0;
		virtual void				checkForErrors( const std::string& error ) = 0;
		virtual bool				createContext()                            = 0;

	protected:

		const platform::CWindow*	m_window;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif
