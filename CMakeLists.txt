cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(PROJECT_NAME EventSystem)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/main.cpp
	
	src/Core/Window.h
	src/Core/Window.cpp
	
	#src/Core/Event/
	src/Core/Event/Event.h
	src/Core/Event/Event.cpp
	
	src/Core/Event/Char/CharEvent.h
	src/Core/Event/Char/CharEvent.cpp
	
	src/Core/Event/Keyboard/KeyPressEvent.h
	src/Core/Event/Keyboard/KeyPressEvent.cpp
	src/Core/Event/Keyboard/KeyReleaseEvent.h
	src/Core/Event/Keyboard/KeyReleaseEvent.cpp
	
	src/Core/Event/Mouse/MouseMoveEvent.h
	src/Core/Event/Mouse/MouseMoveEvent.cpp
	src/Core/Event/Mouse/MouseScrollEvent.h
	src/Core/Event/Mouse/MouseScrollEvent.cpp
	src/Core/Event/Mouse/MousePressEvent.h
	src/Core/Event/Mouse/MousePressEvent.cpp
	src/Core/Event/Mouse/MouseReleaseEvent.h
	src/Core/Event/Mouse/MouseReleaseEvent.cpp
	
	src/Core/Event/Window/WindowResizeEvent.h
	src/Core/Event/Window/WindowResizeEvent.cpp
	src/Core/Event/Window/WindowCloseEvent.h
	src/Core/Event/Window/WindowCloseEvent.cpp
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)