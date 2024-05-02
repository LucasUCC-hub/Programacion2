// .\crear_e.exe 1 2 16 plantilla.txt

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

int main(int argc, char* argv[]) {
    // Verifica si se pasaron suficientes argumentos
    if (argc != 5) {
        std::cerr << "Uso: " << argv[0] << " unidad inicio fin archivo_plantilla" << std::endl;
        return 1;
    }

    // Convierte los argumentos de cadena a números enteros
    int unidad = std::stoi(argv[1]);
    int inicio = std::stoi(argv[2]);
    int fin = std::stoi(argv[3]);

    // Nombre del archivo plantilla
    std::string archivo_plantilla = argv[4];

    // Bucle desde inicio hasta fin
    for (int i = inicio; i <= fin; i++) {
        // Formatear el número con ceros a la izquierda a 2 dígitos
        std::ostringstream numero_stream;
        numero_stream << std::setw(2) << std::setfill('0') << i;
        std::string numero = numero_stream.str();

        // Convertir la unidad a cadena
        std::string str_unidad = std::to_string(unidad);
        
        // Nombre del archivo de destino
        std::string nombre = "u" + str_unidad + "e" + numero + ".cpp";

        // Abre el archivo plantilla
        std::ifstream archivo_entrada(archivo_plantilla, std::ios::binary);
        if (!archivo_entrada) {
            std::cerr << "No se pudo abrir el archivo plantilla: " << archivo_plantilla << std::endl;
            return 1;
        }

        // Abre o crea el archivo de destino
        std::ofstream archivo_salida(nombre, std::ios::binary);
        if (!archivo_salida) {
            std::cerr << "No se pudo crear el archivo de destino: " << nombre << std::endl;
            archivo_entrada.close();
            return 1;
        }

        // Copia el contenido del archivo plantilla al archivo de destino
        archivo_salida << archivo_entrada.rdbuf();

        // Cierra los archivos
        archivo_entrada.close();
        archivo_salida.close();

        std::cout << "Copiado " << archivo_plantilla << " a " << nombre << std::endl;
    }

    std::cout << "Tarea completada." << std::endl;
    return 0;
}
