
# Configuración para todas las librerías en el directorio lib

# Lista de todas las subcarpetas en el directorio lib
file(GLOB LIB_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

# Iterar sobre cada subdirectorio encontrado
foreach(LIB_DIR ${LIB_DIRS})
    # Comprobar si es un directorio válido y no es el directorio actual ni el directorio padre
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_DIR} AND NOT ${LIB_DIR} STREQUAL "." AND NOT ${LIB_DIR} STREQUAL "..")
        # Agregar subdirectorio como una subcarpeta de lib
        add_subdirectory(${LIB_DIR})
    endif()
endforeach()