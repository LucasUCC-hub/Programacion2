# Principal
cmake_minimum_required(VERSION 3.10)
project(AppLucas)

# Añadir subdirectorios
add_subdirectory(modules)
add_subdirectory(samples)

add_executable(main main.cpp)

target_link_libraries(main mates)
