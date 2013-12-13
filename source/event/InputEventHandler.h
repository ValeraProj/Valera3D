#ifndef _V3D_INPUT_EVENT_HANDLER_H_
#define _V3D_INPUT_EVENT_HANDLER_H_

#include "common.h"
#include "Singleton.h"
#include "EventManager.h"
#include "InputEvents.h"

namespace v3d
{
namespace event
{

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CInputEventHandler : public Singleton<CInputEventHandler>, public CEventManager
	{

	public:

		CInputEventHandler();
		~CInputEventHandler();

		void						update()                           override;

		bool						isKeyPressed(const EKeyCode& code)  const;
		bool						isKeyDown(const EKeyCode& code)     const;
		bool						isKeyUp(const EKeyCode& code)       const;

		void						resetKeyPressed();

		bool						isLeftMouseDown()                   const;
		bool						isLeftMouseUp()                     const;

		bool						isRightMouseDown()                  const;
		bool						isRightMouseUp()                    const;

		const core::Dimension2D&	mouseCursor()                       const;
		float						mouseWheel()                        const;

	private:

		bool						onEvent( const CEvent& event )      override;

		bool						m_keysPressed[eKey_Codes_Count];
		bool						m_mouseStates[eMouseCount];

		core::Dimension2D			m_mousePosition; //WARN: need Point class
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif