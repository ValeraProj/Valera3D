#ifndef _V3D_VALERA_ENGINE_H_
#define _V3D_VALERA_ENGINE_H_

#include "ValeraConfig.h"
#include "Singleton.h"
#include "platform/Window.h"

namespace v3d
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CValeraEngine : public Singleton<CValeraEngine>
	{
	public:
		CValeraEngine();
		~CValeraEngine();
		
		platform::CWindow*		getWindow() const;
		void					setWindow(platform::CWindow* window); //Temporary

	private:

		platform::CWindow*		m_platform;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif
