cmake_minimum_required(VERSION 3.10)
project(TuProyecto)

# Añadir subdirectorios
add_subdirectory(lib)
add_executable(main main.cpp)

target_link_libraries(main mylib)
# Enlazar las librerías con el ejecutable principal
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)