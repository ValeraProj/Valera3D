#ifndef _V3D_INPUT_EVENTS_H_
#define _V3D_INPUT_EVENTS_H_

#include "Event.h"
#include "KeyCodes.h"

namespace v3d
{
namespace event
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EKeyboardInputEvent
	{
		eKeyboardUnknown = 0,
		eKeyboardPressedDown,
		eKeyboardPressedUp,

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

	class CKeyboardInputEvent : public CEvent
	{
	public:

		CKeyboardInputEvent();
		~CKeyboardInputEvent();

	private:

		v3d::c8              m_character;
		EKeyCode             m_key;
		EKeyboardInputEvent  m_event;
		v3d::u16             m_modifers;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct CMouseInputEvent : public CEvent
	{
	public:

		CMouseInputEvent(); 
		~CMouseInputEvent();

	private:

		core::Dimension2D m_position; //WARN: need class Point
		v3d::f32          m_wheel;
		EMouseInputEvent  m_event;
		v3d::u16          m_modifers;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}


#endif