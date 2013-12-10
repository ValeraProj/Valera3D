#ifndef _V3D_INPUT_RECEIVER_H_
#define _V3D_INPUT_RECEIVER_H_

#include "common.h"
#include "Singleton.h"

namespace v3d
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EKeyCode;

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EEventType
	{
		eUnknownInputEvent = 0,
		eMouseInputEvent,
		eKeyInputEvent,
		eJoystickInputEvent
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EKeyInputEvent
	{
		eKeyPressedDown = 0,
		eKeyPressedUp,

		eKeyCount
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EMouseInputEvent
	{
		eLeftMousePressedDown = 0,
		eLeftMousePressedUp,
		eLeftMouseDoubleClick,
		eRightMousePressedDown,
		eRightMousePressedUp,
		eRightMouseDoubleClick,
		eMiddleMousePressedDown,
		eMiddleMousePressedUp,
		eMiddleMouseDoubleClick,
		eMouseMoved,
		eMouseWheel,

		eMouseCount
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct SEvent
	{
		SEvent() : eventType(eUnknownInputEvent) 
		{
		}

		EEventType getType() const
		{
			return eventType;
		}

	protected:

		EEventType eventType;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct SKeyEvent : public SEvent
	{
		SKeyEvent()
		: shift(false)
		, control(false)
		, alt(false)
		{
			eventType = eKeyInputEvent;
		}

		v3d::c8        character;
		EKeyCode       key;
		EKeyInputEvent event;
		bool           shift;
		bool           control;
		bool           alt;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct SMouseEvent : public SEvent
	{
		SMouseEvent()
		: shift(false)
		, control(false)
		, alt(false)
		{
			eventType = eMouseInputEvent;
		}

		v3d::s32         x;
		v3d::s32         y;
		v3d::f32         wheel;
		EMouseInputEvent event;
		bool             shift;
		bool             control;
		bool             alt;
		
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class InputReceiver : public Singleton<InputReceiver>
	{

	public:

		InputReceiver();
		~InputReceiver();

		bool						OnEvent( const SEvent& event );

		bool						isKeyPressed(const EKeyCode& code)  const;
		bool						isKeyReleased(const EKeyCode& code) const;
		bool						isKeyDown(const EKeyCode& code)     const;
		bool						isKeyUp(const EKeyCode& code)       const;

		bool						isLeftMousePressed()                const;
		bool						isLeftMouseDown()                   const;
		bool						isLeftMouseReleased()               const;
		bool						isLeftMouseUp()                     const;

		bool						isRightMousePressed()               const;
		bool						isRightMouseDown()                  const;
		bool						isRightMouseReleased()              const;
		bool						isRightMouseUp()                    const;

		const core::Dimension2D&	mouseCursor()                       const;
		float						mouseWheel()                        const;

	private:

		bool						m_keysDown[256];
		bool						m_keysUp[256];
		bool						m_mouseStates[eMouseCount];
		core::Dimension2D			m_mousePosition;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif