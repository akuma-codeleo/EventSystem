#pragma once
#include "../Event.h"
#include <string>

namespace Core
{
	class MouseReleaseEvent : public Event
	{
	private:
		int button;
	public:
		MouseReleaseEvent(int button)
			: Event("Mose button released", Event::EventType::MOUSE_BUTTON_RELEASED_EVENT)
			, button(button)
		{}

		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(button);
			return formatted;
		}
	};
}