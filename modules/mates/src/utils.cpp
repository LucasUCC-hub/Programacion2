#include "utils.h"
#include <cmath>

int count_divs(int a, int b, int k) {
    if (a > b) return -1;

    int c = 0;
    for (int i = a; i < b; i++) {
        if (i % k == 0) c++;
    }

    return c;
}

bool is_prime(int n) {
    // Si `n` es menor que 2, no es primo
    if (n < 2) {
        return false;
    }

    // Verificar si `n` es divisible por algún número desde 2 hasta la raíz cuadrada de `n`
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            // Si `n` es divisible por `i`, entonces no es primo
            return false;
        }
    }

    // Si no se encontró ningún divisor, `n` es primo
    return true;
}

int rmcd(int a, int b) {
    // Si `b` es 0, el MCD es `a`
    if (b == 0) {
        return a;
    }
    // Llamada recursiva con `b` y `a % b`
    return rmcd(b, a % b);
}

int rfact(int N) {
    if (N == 0 || N == 1) {
        return 1;
    } else {
        return N * rfact(N - 1);
    }
}

bool same_prime_divs(int N, int M) {
    for (int i = 0; i < N; i++) {
        if (is_prime(i)) {
            if ((N % i == 0 && M % i != 0) || (N % i != 0 && M % i == 0)) return false;
        }
    }
    return true;
}

