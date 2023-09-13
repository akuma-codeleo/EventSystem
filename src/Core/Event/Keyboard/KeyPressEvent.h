#pragma once
#include <string>
#include "../Event.h"

namespace Core
{
	class KeyPressEvent : public Event
	{
	private:
		int key;
		int scancode;
		int action;
		int mods;
	public:
		KeyPressEvent(int _key, int _scancode, int _action, int _mods)
			: Event("Key pressed Event", Event::EventType::KEY_PRESSED_EVENT)
			, key(_key)
			, scancode(_scancode)
			, action(_action)
			, mods(_mods)
		{}

		int get_key() const { return key; }
		int get_scancode() const { return scancode; }
		int get_action() const { return action; }
		int get_mods() const { return mods; }

		std::string format() const override
		{
			std::string formatted = name + ": " + (char)key;
			return formatted;
		}
	};
}