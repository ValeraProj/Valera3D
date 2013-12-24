#ifndef _V3D_EVENT_MANAGER_H_
#define _V3D_EVENT_MANAGER_H_

#include "common.h"
#include "event/Event.h"

namespace v3d
{
namespace event
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CEventManager
	{
	public:

						CEventManager();
		virtual			~CEventManager();

		virtual void	update();

		void			pushEvent(const CEvent& event);

	private:

		virtual bool	onEvent(const CEvent& event) = 0;


		std::queue<CEvent> m_events;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif