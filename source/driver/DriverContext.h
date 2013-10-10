#ifndef _V3D_DRIVER_CONTEXT_H_
#define _V3D_DRIVER_CONTEXT_H_

#include "common.h"
#include "platform\Platform.h"

namespace v3d
{
namespace renderer
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class EDriverType
	{
		eDriverNull = -1,
		eDriverOpenGL,
		eDriverDirect3D,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CDriverContext
	{
	public:

									CDriverContext( const platform::CPlatform* platform );
		virtual						~CDriverContext();

		virtual void				driverInfo()                               = 0;
		virtual void				checkForErrors( const std::string& error ) = 0;

	protected:

		virtual void				createContext()                            = 0;

		const platform::CPlatform*	m_platform;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif