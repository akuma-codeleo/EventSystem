cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(PROJECT_NAME EventSystem)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/main.cpp
)