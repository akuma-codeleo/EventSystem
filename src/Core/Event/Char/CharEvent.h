#pragma once
#include <string>
#include "../Event.h"

namespace Core
{
	class KeyCharacterEvent : public Event
	{
	private:
		unsigned int key;
	public:
		KeyCharacterEvent(unsigned int key)
			: Event("Key character Event", Event::EventType::KEY_CHARACTER_EVENT)
			, key(key)
		{}

		unsigned int get_key() const { return key; }

		std::string format() const override
		{
			std::string formatted = name + ": " + (char)key;
			return formatted;
		}
	};
}