#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    int x, y, d;
    
    cout << "Posicion inicial: "; cin >> x;
    cout << "Posicion final: "; cin >> y;
    cout << "Largo de salto: "; cin >> d;

    cout << "Saltos minimos:" << calcular_saltos(x, y, d);
}