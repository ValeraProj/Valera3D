#ifndef _V3D_VALERA_ENGINE_H_
#define _V3D_VALERA_ENGINE_H_

#include "ValeraConfig.h"
#include "Singleton.h"
#include "platform/Platform.h"

namespace v3d
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CValeraEngine : public Singleton<CValeraEngine>
	{
	public:
		CValeraEngine();
		~CValeraEngine();
		
		platform::CPlatformPtr	getPlatform() const;

		bool					begin();
		bool					end();

	private:

		void					init();

		platform::CPlatformPtr	m_platform;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif
