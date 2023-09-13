#pragma once
#include "../Event.h"
#include <string>

namespace Core
{
	class MouseScrolledEvent : public Event
	{
	private:
		int offset;
	public:
		MouseScrolledEvent(int offset)
			: Event("Mose Scrolled Event", Event::EventType::MOUSE_SCROLLED_EVENT)
			, offset(offset)
		{}

		std::string format() const override
		{
			std::string formatted = "";
			return (offset < 0) ? formatted = name + ": " + "to bottom" : formatted = name + ": " + "to top";
		}
	};
}