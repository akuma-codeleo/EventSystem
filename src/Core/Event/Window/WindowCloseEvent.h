#pragma once
#include <string>
#include "../Event.h"

namespace Core
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent()
			: Event("Window Close Event", Event::EventType::WINDOW_CLOSED_EVENT)
		{}

		std::string format() const override
		{
			return name;
		}
	};
}