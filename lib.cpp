
#include "lib.h"
#include <cmath>

int calcular_saltos(int inicio, int fin, int zancada){
    if (zancada <= 0) return -1;

    int distancia = fin - inicio;

    if (distancia <= 0) return -1;

    int saltos = distancia / zancada;

    if (distancia % zancada != 0) {
        saltos += 1;
    }
    return saltos;
}

int divisores(int a, int b, int k) {
    if (a > b) return -1;

    int cant = 0;
    for (int i = a; i < b; i++) {
        if (i % k == 0) cant++;
    }

    return cant;
}

bool es_primo(int n) {
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

int MCD(int a, int b) {
    // Si `b` es 0, el MCD es `a`
    if (b == 0) {
        return a;
    }
    // Llamada recursiva con `b` y `a % b`
    return MCD(b, a % b);
}

int factorial(int N) {
    if (N == 0 || N == 1) {
        return 1;
    } else {
        return N * factorial(N - 1);
    }
}

bool mismos_divisores_primos(int N, int M) {
    for (int i = 0; i < N; i++) {
        if (es_primo(i)) {
            if ((N % i == 0 && M % i != 0) || (N % i != 0 && M % i == 0)) return false;
        }
    }
    return true;
}

