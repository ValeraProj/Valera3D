#include "InputEventManager.h"

using namespace v3d;
using namespace v3d::event;

CInputEventManager::CInputEventManager()
{
	for (u32 key = 0; key < eKey_Key_Codes_Count; ++key)
	{
		m_keysDown[key] = false;
		m_keysUp[key] = false;
	}
}

CInputEventManager::~CInputEventManager()
{
}

bool CInputEventManager::onEvent(const CEvent& event)
{
	switch (event.getType())
	{
		case eKeyboardInputEvent:
		{
			const SKeyboardEvent keyEvent = (SKeyboardEvent&)event;

			switch (keyEvent.event)
			{
				case eKeyboardPressedDown:
				{
					m_keysDown[keyEvent.key] = true;

					return true;
				}

				case eKeyboardPressedUp:
				{
					m_keysDown[keyEvent.key] = false;

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
			const SMouseEvent mouseEvent = (SMouseEvent&)event;
			
			for (u32 state = 0; state < eMouseCount; ++state)
			{
				m_mouseStates[state] = state == mouseEvent.event;
			}
			
			switch (mouseEvent.event)
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

bool CInputEventManager::isKeyDown(const EKeyCode& code) const
{
	return m_keysDown[code];
}

bool CInputEventManager::isKeyUp(const EKeyCode& code) const
{
	return m_keysUp[code];
}

bool CInputEventManager::isLeftMouseDown() const
{
	return true;
}

bool CInputEventManager::isLeftMouseUp() const
{
	return true;
}


bool CInputEventManager::isRightMouseDown() const
{
	return true;
}

bool CInputEventManager::isRightMouseUp() const
{
	return true;
}

const core::Dimension2D& CInputEventManager::mouseCursor() const
{
	return core::Dimension2D(0, 0);
}

float CInputEventManager::mouseWheel() const
{
	return 0;
}