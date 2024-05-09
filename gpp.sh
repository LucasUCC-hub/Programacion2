#!/bin/bash

# Verifica si se proporciona la ruta del archivo como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 <ruta_del_archivo_cpp>"
    exit 1
fi

# Ruta del archivo C++ proporcionada como argumento
cpp_file="$1"

# Nombre del archivo ejecutable (sin la extensión .cpp)
executable_name=$(basename "$cpp_file" .cpp)

# Compilación del archivo C++
echo "Compilando $cpp_file ..."
g++ -o "$executable_name" "$cpp_file"

# Verifica si la compilación fue exitosa
if [ $? -ne 0 ]; then
    echo "Error: la compilación falló."
    exit 1
fi

# Carpeta de destino para el ejecutable
destination_folder="/tmp"

# Mover el ejecutable a la carpeta /tmp
mv "$executable_name" "$destination_folder"

# Ejecutar el ejecutable desde la carpeta /tmp
echo "Ejecutando $executable_name desde $destination_folder ..."
echo
cd "$destination_folder"
"./$executable_name"
echo
