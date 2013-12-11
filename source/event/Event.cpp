#include "Event.h"

using namespace v3d;
using namespace v3d::event;

CEvent::CEvent()
: m_eventType(eUnknownInputEvent)
, m_priority(eNormal)
, m_timeStamp(0) //TODO: get current time, need CTimer
{
}

CEvent::~CEvent()
{
}

EEventType CEvent::getType() const
{
	return m_eventType;
}

EPriority CEvent::getPriority() const
{
	return m_priority;
}

v3d::u64 CEvent::getTimeStamp() const
{
	return m_timeStamp;
}