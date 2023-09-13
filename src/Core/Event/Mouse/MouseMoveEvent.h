#pragma once
#include "../Event.h"
#include <string>

namespace Core
{
	class MouseMovedEvent : public Event
	{
	private:
		//?double
		int x;
		int y;

	public:
		MouseMovedEvent(int x, int y)
			: Event("Mouse moved Event", Event::EventType::MOUSE_MOVED_EVENT)
			, x(x)
			, y(y)
		{}

		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(x) + ", " + std::to_string(y);
			return formatted;
		}
	};
}