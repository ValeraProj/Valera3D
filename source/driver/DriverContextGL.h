#ifndef _V3D_DRIVER_CONTEXT_GL_H_
#define _V3D_DRIVER_CONTEXT_GL_H_

#include "DriverContext.h"

namespace v3d
{
namespace renderer
{

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CDriverContextGL : public CDriverContext
	{
	public:

						CDriverContextGL( platform::CPlatform* platform );
		virtual			~CDriverContextGL();

		void			driverInfo();
		void			checkForErrors( const std::string& error );


	protected:

		virtual void	createContext();

#if defined(_PLATFORM_WIN_)
		void			createWin32Context();
#elif (_PLATFORM_LINUX_)
		void			createLinuxContext();
#endif
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif