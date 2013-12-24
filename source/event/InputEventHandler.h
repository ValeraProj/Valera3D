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

		void						connectKeyboardEvent(std::function<void(const CKeyboardInputEvent&)>);
		void						connectMouseEvent(std::function<void(const CMouseInputEvent&)>);

		void						update()                               override;

		bool						isKeyPressed(const EKeyCode& code)     const;

		bool						isLeftMousePressed()                   const;
		bool						isRightMousePressed()                  const;
		bool						isMiddleMousePressed()                 const;

		const core::Dimension2D&	getCursorPosition()                    const;
		float						getMouseWheel()                           const;

	private:

		bool						onEvent(const CEvent& event)         override;
		void						resetKeyPressed();

		bool						m_keysPressed[eKey_Codes_Count];
		bool						m_mouseStates[eMouseCount];

		core::Dimension2D			m_mousePosition; //WARN: need Point class
		float						m_mouseWheel;

		std::function<void(const CKeyboardInputEvent&)>	m_keyboardSignature;
		std::function<void(const CMouseInputEvent&)>	m_mouseSignature;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif