#pragma once
#include "../Event.h"
#include <string>

namespace Core
{
	class MousePressEvent : public Event
	{
	private:
		int button;
	public:
		MousePressEvent(int button)
			: Event("Mose button pressed", Event::EventType::MOUSE_BUTTON_PRESSED_EVENT)
			, button(button)
		{}

		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(button);
			return formatted;
		}
	};
}