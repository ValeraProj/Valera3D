#include "InputEventHandler.h"

using namespace v3d;
using namespace v3d::event;

CInputEventHandler::CInputEventHandler()
{
	resetKeyPressed();
}

CInputEventHandler::~CInputEventHandler()
{
}

void CInputEventHandler::resetKeyPressed()
{
	for (u32 key = 0; key < eKey_Codes_Count; ++key)
	{
		m_keysPressed[key] = false;
	}
}

bool CInputEventHandler::onEvent(const CEvent& event)
{
	switch (event.getType())
	{
		case eKeyboardInputEvent:
		{
			const CKeyboardInputEvent keyEvent = (CKeyboardInputEvent&)event;

			switch (keyEvent.m_event)
			{
				case eKeyboardPressedDown:
				{
					m_keysPressed[keyEvent.m_key] = true;

					return true;
				}

				case eKeyboardPressedUp:
				{
					m_keysPressed[keyEvent.m_key] = false;

					return true;
				}

				default:
				{
					return false;
				}
			}

			return false;
		}

		case eMouseInputEvent:
		{
			const CMouseInputEvent mouseEvent = (CMouseInputEvent&)event;
			
			for (u32 state = 0; state < eMouseCount; ++state)
			{
				m_mouseStates[state] = state == mouseEvent.m_event;
			}
			
			switch (mouseEvent.m_event)
			{
				case	eLeftMousePressedDown:
				case	eLeftMousePressedUp:
				case	eLeftMouseDoubleClick:
				case	eRightMousePressedDown:
				case	eRightMousePressedUp:
				case	eRightMouseDoubleClick:
				case	eMiddleMousePressedDown:
				case	eMiddleMousePressedUp:
				case	eMiddleMouseDoubleClick:
			}

			return false;
		};

		case eJoystickInputEvent:
		{
			return false;
		};

		default:
		{
			return false;
		};

	}
}

bool CInputEventHandler::isKeyPressed(const EKeyCode& code)  const
{
	return m_keysPressed[code];
}

bool CInputEventHandler::isKeyDown(const EKeyCode& code) const
{
	return m_keysDown[code];
}

bool CInputEventHandler::isKeyUp(const EKeyCode& code) const
{
	return false;//m_keysDown[code];
}

bool CInputEventHandler::isLeftMouseDown() const
{
	return true;
}

bool CInputEventHandler::isLeftMouseUp() const
{
	return true;
}


bool CInputEventHandler::isRightMouseDown() const
{
	return true;
}

bool CInputEventHandler::isRightMouseUp() const
{
	return true;
}

const core::Dimension2D& CInputEventHandler::mouseCursor() const
{
	return core::Dimension2D(0, 0);
}

float CInputEventHandler::mouseWheel() const
{
	return 0;
}