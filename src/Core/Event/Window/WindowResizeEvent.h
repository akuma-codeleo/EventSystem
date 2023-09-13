#pragma once
#include <string>
#include "../Event.h"

namespace Core
{
	class WindowResizeEvent : public Event
	{
	private:
		int width;
		int height;
	public:
		WindowResizeEvent(int width, int height)
			: Event("Window resize Event", Event::EventType::WINDOW_RESIZED_EVENT)
			, width(width)
			, height(height)
		{}

		int get_width() const { return width; }
		int get_height() const { return height; }

		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(width) + "*" + std::to_string(height);
			return formatted;
		}
	};
}