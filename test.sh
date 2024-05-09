#!/bin/bash

# Verificar que se haya proporcionado un argumento
if [ -z "$1" ]; then
    echo "Uso: test archivo.cpp"
    exit 1
fi

# Nombre del archivo cpp proporcionado
archivo="$1"
# Nombre del ejecutable generado (sin la extensión .cpp)
ejecutable="${archivo%.*}"

# Compilar y construir el proyecto utilizando CMake
mkdir -p build
cd build
cmake -DArchivo="$archivo" .. > /dev/null
make > /dev/null

# Verificar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    # Ejecutar el ejecutable generado
    echo "Ejecutando..."
    echo
    "./$ejecutable"
    echo
else
    echo "Error al compilar $archivo"
fi
