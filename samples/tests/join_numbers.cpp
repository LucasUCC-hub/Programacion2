#include <iostream>

#define INPUT_LIMIT 16

bool isnum(char c) {
    return '0' <= c && c <= '9';
}

int num_count(char str[INPUT_LIMIT]) {
    int count = 0;
    for(int i = 0; i < INPUT_LIMIT; i++) {
        if (isnum(str[i])) count++;
    }
    return count;
}

char* join_num(char* a, char* b) {
    int size = num_count(a) + num_count(b) + 1;
    char* res = new char[size];

    int k = 0;
    // Une los caracteres en a
    for(int i = 0; i < INPUT_LIMIT; i++) {
        if (isnum(a[i])) {
            res[k] = a[i]; 
            k++;
        }
    }
    // Une los caracteres en b
    for(int i = 0; i < INPUT_LIMIT; i++) {
        if (isnum(b[i])) {
            res[k] = b[i]; 
            k++;
        }
    }

    res[k] = '\0';
    return res;
}

int main() {
    char a[INPUT_LIMIT], b[INPUT_LIMIT];

    std::cout << "Enter strings:";
    std::cin >> a >> b;

    char* number = join_num(a, b);
    std::cout << "Numbers: " << number;

    delete[] number;
}
