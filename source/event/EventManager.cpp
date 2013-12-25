#include "EventManager.h"

using namespace v3d;
using namespace v3d::event;

CEventManager::CEventManager()
{
}

CEventManager::~CEventManager()
{
}

void CEventManager::update()
{
	while (!m_events.empty())
	{
		SInputEvent& event = m_events.front();
		
		if (onEvent(event))
		{
			int a = 0;
			//TODO:
		}

		m_events.pop();
	}
}

void CEventManager::pushEvent(const SInputEvent& event)
{
	m_events.push(event);
}
