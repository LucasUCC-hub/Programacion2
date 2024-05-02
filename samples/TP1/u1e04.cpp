#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    int a;
    cout << "Factorial de "; cin >> a;
    cout << "= " << factorial(a);
    return 0;
}