#pragma once
#include "GLFW/glfw3.h"
#include <string>
#include <functional>
#include "Event/Event.h"

namespace Core
{
	class Window final
	{
	public:
		enum class WindowStatus : int8_t
		{
			MAIN = 1,
			TEXT_INPUT,
			GAME_MODE,
			MENU
		};
	private:
		std::string name;
		int width;
		int height;
		GLFWwindow* window = nullptr;
		std::function<void(Event&)> fnCallback;
		WindowStatus status;

	public:
		Window(const Window&) = delete;
		Window& operator= (const Window&) = delete;

	private:
		Window(const std::string& _name, int _width, int _height);
		~Window();

	public:
		static Window& getInstanse();

		int init(const std::string& _name, int _width, int _height);

		__forceinline GLFWwindow* getGLFWwindow() const { return window; }

		void setfnCallback(const std::function<void(Event&)>& fn) { fnCallback = fn; }

		static void mouseMovedCallback(GLFWwindow* window, double x, double y);
		static void mouseScrollCallback(GLFWwindow* window, double x, double y);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		static void characterCallback(GLFWwindow* window, unsigned int codepoint);
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
		static void windowCloseCallback(GLFWwindow* window);


	};
}