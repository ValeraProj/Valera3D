#include "InputEvents.h"

using namespace v3d;
using namespace v3d::event;

CKeyboardInputEvent::CKeyboardInputEvent()
: m_character(0)
, m_key(eKey_Uknown)
, m_event(eKeyboardUnknown)
, m_modifers(0)
{
	m_eventType = eKeyboardInputEvent;
}

CKeyboardInputEvent::~CKeyboardInputEvent()
{
}


CMouseInputEvent::CMouseInputEvent()
: m_position(0,0)
, m_wheel(0.0f)
, m_event(eMouseUnknown)
, m_modifers(0)
{
	m_eventType = eMouseInputEvent;
}

CMouseInputEvent::~CMouseInputEvent()
{
}