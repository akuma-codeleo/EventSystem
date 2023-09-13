#pragma once
#include <string>

namespace Core
{
	class Event
	{
	public:
		enum class EventType : int8_t
		{
			MOUSE_MOVED_EVENT = 1,
			MOUSE_SCROLLED_EVENT,
			MOUSE_BUTTON_PRESSED_EVENT,
			MOUSE_BUTTON_RELEASED_EVENT,
			KEY_PRESSED_EVENT,
			KEY_RELEASED_EVENT,
			KEY_REPEATED_EVENT,
			KEY_CHARACTER_EVENT,
			WINDOW_RESIZED_EVENT,
			WINDOW_CLOSED_EVENT
		};
	protected:
		EventType type;
		std::string name;

	protected:
		Event(std::string _name, EventType _type)
			: name(_name)
			, type(_type)
		{}

	public:
		virtual ~Event() = default;
		inline std::string getName() const { return name; }
		inline EventType getType() const { return type; }
		virtual std::string format() const = 0;

	};
}