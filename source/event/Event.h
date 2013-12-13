#ifndef _V3D_EVENT_H_
#define _V3D_EVENT_H_

#include "common.h"

namespace v3d
{
namespace event
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EEventType
	{
		eUnknownInputEvent = 0,
		eMouseInputEvent,
		eKeyboardInputEvent,
		eGamepadInputevent,
		eJoystickInputEvent
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum EPriority
	{
		eLow    = 10,
		eNormal = 20,
		eHigh   = 30
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CEvent
	{
	public:

		CEvent();
		~CEvent();

		EEventType	getType() const;
		EPriority	getPriority() const;
		v3d::u64	getTimeStamp() const;

		bool		operator<(const CEvent& event);

	protected:

		EEventType	m_eventType;
		EPriority	m_priority;
		v3d::u64	m_timeStamp;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif