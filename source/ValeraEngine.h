#ifndef _VALERA_ENGINE_H_
#define _VALERA_ENGINE_H_

#include "ValeraConfig.h"
#include "Singleton.h"
#include "platform\Platform.h"

namespace v3d
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CValeraEngine : public Singleton<CValeraEngine>
	{
	public:
		CValeraEngine();
		~CValeraEngine();
		
		platform::CPlatform*	getPlatform() const;

	private:

		platform::CPlatform*	m_platform;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif