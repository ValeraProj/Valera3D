#ifndef _V3D_INPUT_EVENTS_H_
#define _V3D_INPUT_EVENTS_H_

#include "common.h"
#include "KeyCodes.h"

namespace v3d
{
namespace event
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EInputEventType
	{
		eUnknownInputEvent = 0,
		eMouseInputEvent,
		eKeyboardInputEvent,
		eGamepadInputEvent,
		eJoystickInputEvent,
		eTouchInputEvent
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EPriority
	{
		eLow = 10,
		eNormal = 20,
		eHigh = 30
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EKeyboardInputEvent
	{
		eKeyboardUnknown = 0,
		eKeyboardPressDown,
		eKeyboardPressUp,

		eKeyboardCount
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EMouseInputEvent
	{
		eMouseUnknown = 0,
		eLeftMousePressedDown,
		eLeftMousePressedUp,
		eLeftMouseDoubleClick,
		eRightMousePressedDown,
		eRightMousePressedUp,
		eRightMouseDoubleClick,
		eMiddleMousePressedDown,
		eMiddleMousePressedUp,
		eMiddleMouseDoubleClick,
		eMouseMoved,
		eMouseWheelUp,
		eMouseWheelDown,

		eMouseCount
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct SInputEvent
	{
		SInputEvent();
		~SInputEvent();

		bool			operator<(const SInputEvent& event);

		EInputEventType	m_eventType;
		EPriority		m_priority;
		v3d::u64		m_timeStamp;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct SKeyboardInputEvent : public SInputEvent
	{
		SKeyboardInputEvent();
		~SKeyboardInputEvent();

		v3d::c8              m_character;
		EKeyCode             m_key;
		EKeyboardInputEvent  m_event;
		v3d::u16             m_modifers;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct SMouseInputEvent : public SInputEvent
	{
		SMouseInputEvent();
		~SMouseInputEvent();

		core::Dimension2D m_position; //WARN: need class Point
		v3d::f32          m_wheel;
		EMouseInputEvent  m_event;
		v3d::u16          m_modifers;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}


#endif