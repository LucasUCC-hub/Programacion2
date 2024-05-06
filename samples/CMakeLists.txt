# samples/CMakeLists.txt

cmake_minimum_required(VERSION 3.0)
project(samples)

# Define una lista vacía para almacenar los archivos de prueba
set(TEST_SOURCES "")

# Busca todos los archivos .cpp en el directorio "samples" y los agrega a la lista TEST_SOURCES
file(GLOB TEST_SOURCES "TP1/*.cpp")

# Añade un objetivo ejecutable para cada archivo de prueba
foreach(TEST_SOURCE ${TEST_SOURCES})
    # Extrae el nombre del archivo sin la extensión
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    
    # Define el objetivo ejecutable
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    
    # Enlaza la biblioteca con el objetivo ejecutable
    target_link_libraries(${TEST_NAME} mates)

    # Incluye la carpeta de includes de la biblioteca 'mates'
    target_include_directories(${TEST_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/modules/mates/include")
endforeach()
