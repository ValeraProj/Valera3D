#ifndef _V3D_INPUT_EVENT_MANAGER_H_
#define _V3D_INPUT_EVENT_MANAGER_H_

#include "common.h"
#include "Singleton.h"
#include "EventManager.h"
#include "InputEvents.h"

namespace v3d
{
namespace event
{

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CInputEventManager : public Singleton<CInputEventManager>, public CEventManager
	{

	public:

		CInputEventManager();
		~CInputEventManager();

		void						update()	override;

		bool						isKeyDown(const EKeyCode& code)     const;
		bool						isKeyUp(const EKeyCode& code)       const;

		bool						isLeftMouseDown()                   const;
		bool						isLeftMouseUp()                     const;

		bool						isRightMouseDown()                  const;
		bool						isRightMouseUp()                    const;

		const core::Dimension2D&	mouseCursor()                       const;
		float						mouseWheel()                        const;

	private:

		bool						onEvent( const CEvent& event ) override;

		bool						m_keysDown[256];
		bool						m_keysUp[256];
		bool						m_mouseStates[eMouseCount];
		core::Dimension2D			m_mousePosition; //WARN: need Point class
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif