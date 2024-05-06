#include "range.h"
#include <iostream>

using namespace std;

int main() {
    for(int i : Range(10, 20)) {
        cout << i;
    }
}