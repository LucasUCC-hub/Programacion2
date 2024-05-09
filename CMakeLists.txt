# Principal
cmake_minimum_required(VERSION 3.0)
project(AppLucas)

# Añadir subdirectorios, compila automaticamente todas las librerias (subdirectorios) definidos en /modules
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/custom-libs/mates)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/imgui)

# Verificar si se proporciona un archivo .cpp como argumento para 
if(DEFINED Archivo)
    add_executable(${CMAKE_PROJECT_NAME} ${Archivo})
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} mates imgui)
