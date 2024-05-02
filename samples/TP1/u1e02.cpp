#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    int a, b, k;
    cout << "Intervalo desde: "; cin >> a;
    cout << "Hasta: "; cin >> b;
    cout << "Divisible por: "; cin >> k;
    
    cout << "Divisores: " << divisores(a, b, k);
    return 0;
}