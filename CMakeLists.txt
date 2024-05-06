# Principal
cmake_minimum_required(VERSION 3.10)
project(AppLucas)

# Añadir subdirectorios, compila automaticamente todas las librerias (subdirectorios) definidos en /modules
add_subdirectory(modules)

add_executable(main samples/TP1/test_range.cpp)

target_link_libraries(main mates)
