# Principal
cmake_minimum_required(VERSION 3.10)
project(AppLucas)

# Añadir subdirectorios, compila automaticamente todas las librerias (subdirectorios) definidos en /modules
add_subdirectory(custom-libs)

add_executable(main ./main.cpp)

target_link_libraries(main mates)
