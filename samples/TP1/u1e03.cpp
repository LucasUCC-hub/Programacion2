#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    int a, b;
    cout << "introduzca dos numeros: "; cin >> a >> b;
    cout << "Maximo comun divisor: " << MCD(a, b);
    return 0;
}