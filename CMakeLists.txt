cmake_minimum_required(VERSION 3.15)

project(opengl_template CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("./libraries/glfw-3.4")
add_subdirectory("./libraries/glad/")
add_subdirectory("./libraries/glm/")
add_subdirectory("./libraries/imgui/")

set(CMAKE_SOURCE_DIR "${CMAKE_HOME_DIRECTORY}/src")
set(EXECUTABLE_NAME "${PROJECT_NAME}_bin")

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")

add_executable("${EXECUTABLE_NAME}" ${SOURCES})

target_link_libraries("${EXECUTABLE_NAME}" glfw)
target_link_libraries("${EXECUTABLE_NAME}" glad)
target_link_libraries("${EXECUTABLE_NAME}" glm)
target_link_libraries("${EXECUTABLE_NAME}" imgui)
