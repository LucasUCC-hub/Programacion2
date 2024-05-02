#include <iostream>
#include "lib.h"

using namespace std;


int main() {
    // Ejemplo de uso
    int N = 25;
    int M = 75;
    if (mismos_divisores_primos(N, M)) {
        std::cout << "N y M tienen los mismos divisores primos." << std::endl;
    } else {
        std::cout << "N y M no tienen los mismos divisores primos." << std::endl;
    }

    return 0;
}