cmake_minimum_required(VERSION 3.0)

# CMake file for compiling the imgui library
project(imgui)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} backends)
# Add THIS Directory in the top level CMakeLists.txt file using
#    add_subdirectory(/home/jorge/code-new/imgui-demo/external/imgui/)

# Add the library that is built on this subdirectory.
add_library(imgui STATIC imgui.cpp imgui.h imgui_internal.h backends/imgui_impl_glfw.h)

# target_include_directories(${PROJECT_NAME}.out PRIVATE Adder)
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})