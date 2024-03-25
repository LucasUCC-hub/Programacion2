#include <iostream>
#include "../../include/mathf.h"

using namespace std;

int main(int argc, char*argv[]) {
    int a, b, c;
    cout << "Start position: "; cin >> a;
    cout << "End position: "; cin >> b;
    cout << "Jump distance: "; cin >> c;
    cout << "\nMinimum jumps: " << min_steps(a, b, c);
    return 0;
}