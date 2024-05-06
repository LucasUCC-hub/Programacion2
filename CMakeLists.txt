# Principal
cmake_minimum_required(VERSION 3.10)
project(AppLucas)

# Añadir subdirectorios, compila automaticamente todas las librerias (subdirectorios) definidos en /modules
add_subdirectory(custom-libs)

# Verificar si se proporciona un archivo .cpp como argumento para 
if(DEFINED Archivo)
    add_executable(${CMAKE_PROJECT_NAME} ${Archivo})
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} mates)
