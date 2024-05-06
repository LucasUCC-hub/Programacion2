#include <iostream>
#include <fstream>
#include <string>

void hacerCopias(const std::string& unidad, int ej_inicio, int ej_final, const std::string& destino, const std::string& template_archivo) {
    for (int i = ej_inicio; i <= ej_final; ++i) {
        std::string nombre_copia = destino + "/u" + unidad + "e" + std::to_string(i) + ".cpp";
        std::string contenido;

        // Leer el contenido del archivo template
        std::ifstream archivo_template(template_archivo);
        if (archivo_template.is_open()) {
            std::string linea;
            while (std::getline(archivo_template, linea)) {
                contenido += linea + "\n";
            }
            archivo_template.close();
        } else {
            std::cerr << "Error: No se pudo abrir el archivo template " << template_archivo << std::endl;
            return;
        }

        // Escribir el contenido en la copia con el nombre adecuado
        std::ofstream archivo_copia(nombre_copia);
        if (archivo_copia.is_open()) {
            archivo_copia << contenido;
            archivo_copia.close();
            std::cout << "Copia creada: " << nombre_copia << std::endl;
        } else {
            std::cerr << "Error: No se pudo crear la copia " << nombre_copia << std::endl;
        }
    }
}

int main() {
    std::string unidad = "1";
    int ej_inicio = 1;
    int ej_final = 5;
 
    std::string destino = "samples/destino"; // CUIDADO! puede haber problema con el path
    std::string template_archivo = "samples/template.cpp";

    hacerCopias(unidad, ej_inicio, ej_final, destino, template_archivo);

    return 0;
}
