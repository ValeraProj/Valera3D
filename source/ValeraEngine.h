#ifndef _V3D_VALERA_ENGINE_H_
#define _V3D_VALERA_ENGINE_H_

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
		void					setPlatform( platform::CPlatform* platform ); //Temporary

	private:

		platform::CPlatform*	m_platform;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif