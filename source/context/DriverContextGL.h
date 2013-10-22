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

						CDriverContextGL( const platform::CPlatform* platform );
		virtual			~CDriverContextGL();

		virtual void	driverInfo();
		virtual void	checkForErrors( const std::string& error );
		virtual bool	createContext();

	protected:

#if defined(_PLATFORM_WIN_)
		bool			createWin32Context();
#elif (_PLATFORM_LINUX_)
		bool			createLinuxContext();
#endif
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif