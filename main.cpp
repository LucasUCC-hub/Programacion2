#include "range.h"
#include <iostream>

using namespace std;

int main() {
    for(int i : Range(1,20)) {
        cout << i;
    }
}