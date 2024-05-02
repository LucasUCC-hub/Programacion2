#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[]) {
    // Verificar si se pasó un argumento
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " archivo_cpp" << std::endl;
        return 1;
    }

    std::string destino = "build";
    // Asignar el archivo C++ pasado como argumento a una variable
    std::string archivo_cpp = argv[1];

    // Extraer el nombre base del archivo C++ sin la extensión
    std::string nombre_base = archivo_cpp.substr(0, archivo_cpp.find_last_of('.'));

    // Ruta del archivo lib.cpp
    std::string lib_cpp = "lib.cpp";

    // Compilar el archivo C++ junto con lib.cpp usando g++
    std::string comando_compilacion = "g++ \"" + archivo_cpp + "\" \"" + lib_cpp + "\" -o \"" + destino + "\"" + nombre_base + ".exe\"";

    std::cout << "Compilando " << archivo_cpp << " con " << lib_cpp << "..." << std::endl;
    
    // Ejecutar el comando de compilación
    int resultado_compilacion = std::system(comando_compilacion.c_str());

    // Verificar si la compilación tuvo éxito
    if (resultado_compilacion != 0) {
        std::cerr << "Error durante la compilación." << std::endl;
        return 1;
    }

    // Comando para ejecutar el archivo ejecutable resultante
    std::string comando_ejecucion = "\"" + destino + "\"" + nombre_base + ".exe\"";

    std::cout << "Ejecutando " << comando_ejecucion << "..." << std::endl;

    // Ejecutar el archivo ejecutable resultante
    std::system(comando_ejecucion.c_str());

    return 0;
}
