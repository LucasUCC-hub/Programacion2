
# Añadir los archivos de origen de la librería
add_library(mylib STATIC src/mymaths.cpp)

# Incluir directorio de encabezado para que se pueda acceder a los archivos de encabezado usando #include <mylib/maths.h>
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(mylib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")