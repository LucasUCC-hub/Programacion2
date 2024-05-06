# samples/CMakeLists.txt

cmake_minimum_required(VERSION 3.0)
project(samples)

# Añadir subdirectorios
add_subdirectory(../modules)

add_executable(main TP1/test_range.cpp)

target_link_libraries(main mates)