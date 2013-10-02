#ifndef _V3D_DRIVER_CONTEXT_H_
#define _V3D_DRIVER_CONTEXT_H_

#include "common.h"
#include "platform\Platform.h"

namespace v3d
{
namespace renderer
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class ERendererType
	{
		eNull = -1,
		eOpenGL,
		eDirect3D,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	class CDriverContext
	{
	public:

								CDriverContext( platform::CPlatform* platform );
		virtual					~CDriverContext();

	protected:

		virtual void			createContext() = 0;

		platform::CPlatform*	m_platform;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif