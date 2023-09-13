#include "Window.h"

#include "Event/Char/CharEvent.h"

#include "Event/Keyboard/KeyPressEvent.h"
#include "Event/Keyboard/KeyReleaseEvent.h"

#include "Event/Mouse/MouseMoveEvent.h"
#include "Event/Mouse/MousePressEvent.h"
#include "Event/Mouse/MouseReleaseEvent.h"
#include "Event/Mouse/MouseScrollEvent.h"

#include "Event/Window/WindowCloseEvent.h"
#include "Event/Window/WindowResizeEvent.h"

#include <iostream>

namespace Core
{
	Window::Window(const std::string& _name, int _width, int _height)
	{
		init(_name, _width, _height);

		setfnCallback([this](Event& e)
			{
				if (e.getType() == Event::EventType::WINDOW_CLOSED_EVENT)
				{
					glfwSetWindowShouldClose(window, GL_TRUE);
				}

				std::cout << e.format() << std::endl;
			});
	}
	
	Window::~Window()
	{
		glfwWindowShouldClose(window);
	}

	Window& Window::getInstanse()
	{
		static Window instanse("Window", 1280, 720);
		return instanse;
	}

	int Window::init(const std::string& _name, int _width, int _height)
	{
		this->name = _name;
		this->width = _width;
		this->height = _height;

		if (!glfwInit())
			return -1;

		window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

		if (!window)
			return -1;

		glfwMakeContextCurrent(window);

		glfwSetWindowUserPointer(window, this);
		glfwSetCursorPosCallback(window, mouseMovedCallback);
		glfwSetScrollCallback(window, mouseScrollCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwSetKeyCallback(window, keyCallback);
		glfwSetCharCallback(window, characterCallback);
		glfwSetWindowSizeCallback(window, windowResizeCallback);
		glfwSetWindowCloseCallback(window, windowCloseCallback);
	}

	void Window::mouseMovedCallback(GLFWwindow* window, double x, double y)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MouseMovedEvent e(x, y);
		handle.fnCallback(e);
	}

	void Window::mouseScrollCallback(GLFWwindow* window, double x, double y)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MouseScrolledEvent e(y);
		handle.fnCallback(e);
	}

	void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS)
		{
			MousePressEvent e(button);
			handle.fnCallback(e);
		}
		else
		{
			MouseReleaseEvent e(button);
			handle.fnCallback(e);
		}
		
	}

	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//std::cout << key << " " << scancode << " " << action << " " << mods << "\n";
		//if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		//	std::cout << "exit""\n";
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS)
		{
			KeyPressEvent e(key, scancode, action, mods);
			handle.fnCallback(e);
		}
		else if(action == GLFW_RELEASE)
		{
			KeyReleaseEvent e(key, scancode, action, mods);
			handle.fnCallback(e);
		}
	}

	void Window::characterCallback(GLFWwindow* window, unsigned int codepoint)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		KeyCharacterEvent e(codepoint);
		handle.fnCallback(e);
	}

	void Window::windowResizeCallback(GLFWwindow* window, int width, int height)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		WindowResizeEvent e(width, height);
		handle.width = width;
		handle.height = height;
		handle.fnCallback(e);
	}

	void Window::windowCloseCallback(GLFWwindow* window)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		WindowCloseEvent e;
		handle.fnCallback(e);
	}
}