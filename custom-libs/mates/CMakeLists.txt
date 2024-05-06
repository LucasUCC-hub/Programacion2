# /modules/mates
cmake_minimum_required(VERSION 3.0)
project(mates)

# Añadir los archivos de origen de la librería
add_library(mates STATIC src/range.cpp src/utils.cpp)

# Incluir directorio de encabezado para que se pueda acceder a los archivos de encabezado usando #include <mates/range.h>
target_include_directories(mates PUBLIC include)

set_target_properties(mates PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "build")
