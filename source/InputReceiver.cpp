#include "InputReceiver.h"

#include "KeyCodes.h"

using namespace v3d;

InputReceiver::InputReceiver()
{
	for (u32 key = 0; key < eKey_Key_Codes_Count; ++key)
	{
		m_keysDown[key] = false;
		m_keysUp[key] = false;
	}
}

InputReceiver::~InputReceiver()
{
}

bool InputReceiver::OnEvent(const SEvent& event)
{
	switch (event.getType())
	{
		case eKeyInputEvent:
		{
			const SKeyEvent keyEvent = (SKeyEvent&)event;

			switch (keyEvent.event)
			{
				case eKeyPressedDown:
				{
					m_keysDown[keyEvent.key] = true;
					m_keysUp[keyEvent.key] = false;

					return true;
				}

				case eKeyPressedUp:
				{
					m_keysUp[keyEvent.key] = true;
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
				case	eMouseMoved:
				{
					m_mousePosition.width = mouseEvent.x;
					m_mousePosition.height = mouseEvent.y;
				}
				case	eMouseWheel:
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

bool InputReceiver::isKeyDown(const EKeyCode& code) const
{
	return m_keysDown[code];
}

bool InputReceiver::isKeyUp(const EKeyCode& code) const
{
	return m_keysUp[code];
}

bool InputReceiver::isLeftMousePressed() const
{
	return true;
}

bool InputReceiver::isLeftMouseDown() const
{
	return true;
}
bool InputReceiver::isLeftMouseReleased() const
{
	return true;
}

bool InputReceiver::isLeftMouseUp() const
{
	return true;
}

bool InputReceiver::isRightMousePressed() const
{
	return true;
}
bool InputReceiver::isRightMouseDown() const
{
	return true;
}
bool InputReceiver::isRightMouseReleased() const
{
	return true;
}
bool InputReceiver::isRightMouseUp() const
{
	return true;
}

const core::Dimension2D& InputReceiver::mouseCursor() const
{
	return core::Dimension2D(0, 0);
}

float InputReceiver::mouseWheel() const
{
	return 0;
}