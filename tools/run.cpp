#include <cstdlib>
#include <iostream>

int main() {
    // Ejecutar el script
    system(R"(
        #!/bin/sh

        # Ejecutar cmake
        echo "Ejecutando CMake..."
        cmake -B build
        cd build

        # Compilar con make
        echo "Compilando con Make..."
        make

        # Ejecutar el programa
        echo "Ejecutando el programa..."
        ./main

        # Volver al directorio raíz
        cd ..

        # Pausa para ver los resultados
        read -p "Presiona Enter para salir"
    )");

    return 0;
}
