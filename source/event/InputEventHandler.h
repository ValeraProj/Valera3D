#ifndef _V3D_INPUT_EVENT_HANDLER_H_
#define _V3D_INPUT_EVENT_HANDLER_H_

#include "common.h"
#include "event/EventManager.h"
#include "event/InputEvents.h"

namespace v3d
{
namespace event
{

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CInputEventHandler : public CEventManager
	{

	public:

		CInputEventHandler();
		~CInputEventHandler();

		void						connectKeyboardEvent(std::function<void(const SKeyboardInputEvent&)>);
		void						connectMouseEvent(std::function<void(const SMouseInputEvent&)>);

		void						update()                               override;

		bool						isKeyPressed(const EKeyCode& code)     const;

		bool						isLeftMousePressed()                   const;
		bool						isRightMousePressed()                  const;
		bool						isMiddleMousePressed()                 const;

		const core::Dimension2D&	getCursorPosition()                    const;
		float						getMouseWheel()                        const;

	private:

		bool						onEvent(const SInputEvent& event)      override;
		void						resetKeyPressed();

		bool						m_keysPressed[eKey_Codes_Count];
		bool						m_mouseStates[eMouseCount];

		core::Dimension2D			m_mousePosition; //WARN: need Point class
		float						m_mouseWheel;

		std::function<void(const SKeyboardInputEvent&)>	m_keyboardSignature;
		std::function<void(const SMouseInputEvent&)>	m_mouseSignature;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	typedef std::shared_ptr<CInputEventHandler>		CInputEventHandlerPtr;

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif