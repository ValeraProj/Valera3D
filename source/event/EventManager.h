#ifndef _V3D_EVENT_MANAGER_H_
#define _V3D_EVENT_MANAGER_H_

#include "common.h"
#include "event/InputEvents.h"

namespace v3d
{
namespace event
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CEventManager
	{
	public:
								CEventManager();
		virtual					~CEventManager();

		virtual void			update();
		void					pushEvent(const SInputEvent& event);

	private:

		virtual bool			onEvent(const SInputEvent& event) = 0;

		std::queue<const SInputEvent> m_events;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif