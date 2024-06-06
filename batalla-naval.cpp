#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>

class Barco {
public:
    Barco(int size) : size(size), hits(0) {}

    bool estaHundido() const {
        return hits >= size;
    }

    void registrarImpacto() {
        ++hits;
    }

    int getSize() const {
        return size;
    }

private:
    int size;
    int hits;
};

class Tablero {
public:
    Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
        grid.resize(filas, std::vector<Barco*>(columnas, nullptr));
    }

    void colocarBarco(int fila, int columna, Barco* barco, bool horizontal) {
        for (int i = 0; i < barco->getSize(); ++i) {
            if (horizontal) {
                grid[fila][columna + i] = barco;
            } else {
                grid[fila + i][columna] = barco;
            }
        }
    }

    bool hayBarco(int fila, int columna) const {
        return grid[fila][columna] != nullptr;
    }

    bool impacto(int fila, int columna) const {
    if (grid[fila][columna] != nullptr) {
        grid[fila][columna]->registrarImpacto();
        return true;
    }
    return false;
}

    void renderizar() const {
        std::cout << "  ";
        for (int i = 0; i < columnas; ++i) {
            std::cout << char('A' + i) << ' ';
        }
        std::cout << std::endl;

        for (int i = 0; i < filas; ++i) {
            std::cout << i + 1 << ' ';
            for (int j = 0; j < columnas; ++j) {
                if (grid[i][j] == nullptr) {
                    std::cout << ". ";
                } else {
                    std::cout << (grid[i][j]->estaHundido() ? "X " : "O ");
                }
            }
            std::cout << std::endl;
        }
    }

    int getFilas() const {
        return filas;
    }

    int getColumnas() const {
        return columnas;
    }

private:
    int filas;
    int columnas;
    std::vector<std::vector<Barco*>> grid;
};

class Jugador {
public:
    Jugador(const std::string& nombre) : nombre(nombre) {}

    const std::string& getNombre() const {
        return nombre;
    }

private:
    std::string nombre;
};

class Partida {
public:
    Partida(int filas, int columnas, Jugador& jugador1, Jugador& jugador2) : 
        tableroJugador1(filas, columnas), tableroJugador2(filas, columnas),
        jugador1(jugador1), jugador2(jugador2) {}

    void colocarBarco(Jugador& jugador, int fila, int columna, Barco* barco, bool horizontal) {
        if (&jugador == &jugador1) {
            tableroJugador1.colocarBarco(fila, columna, barco, horizontal);
        } else {
            tableroJugador2.colocarBarco(fila, columna, barco, horizontal);
        }
    }

    bool realizarAtaque(Jugador& atacante, int fila, int columna) {
        Jugador& defensor = (&atacante == &jugador1) ? jugador2 : jugador1;
        Tablero& tableroDefensor = (&atacante == &jugador1) ? tableroJugador2 : tableroJugador1;

        if (tableroDefensor.impacto(fila, columna)) {
            std::cout << "¡Impacto en el barco de " << defensor.getNombre() << "!" << std::endl;
            if (tableroDefensor.hayBarco(fila, columna) && tableroDefensor.impacto(fila, columna)) {
                std::cout << "¡Hundido!" << std::endl;
                return true; // Barco hundido
            }
        } else {
            std::cout << "¡Agua!" << std::endl;
        }
        return false; // No se hundió barco
    }

    bool todosBarcosDerribados(Jugador& jugador) const {
        Jugador& oponente = (&jugador == &jugador1) ? jugador2 : jugador1;
        const Tablero& tableroOponente = (&jugador == &jugador1) ? tableroJugador2 : tableroJugador1;

        for (int i = 0; i < tableroOponente.getFilas(); ++i) {
            for (int j = 0; j < tableroOponente.getColumnas(); ++j) {
                if (tableroOponente.hayBarco(i, j) && !tableroOponente.impacto(i, j)) {
                    return false; // Todavía hay barcos no derribados
                }
            }
        }
        return true; // Todos los barcos enemigos han sido derribados
    }

    void renderizar() const {
        std::cout << "Tablero de " << jugador1.getNombre() << std::endl;
        tableroJugador1.renderizar();
        std::cout << std::endl;
        std::cout << "Tablero de " << jugador2.getNombre() << std::endl;
        tableroJugador2.renderizar();
    }

private:
    Tablero tableroJugador1;
    Tablero tableroJugador2;
    Jugador& jugador1;
    Jugador& jugador2;
};

int main() {
    Jugador jugador1("Jugador 1");
    Jugador jugador2("Jugador 2");
    Partida partida(10, 10, jugador1, jugador2);

    // Función para colocar barcos aleatoriamente
    auto colocarBarcosAleatoriamente = [](Partida& partida, Jugador& jugador) {
        srand(time(nullptr)); // Semilla para generación aleatoria
        for (int i = 0; i < 10; ++i) {
            int fila = rand() % 10; // Generar fila aleatoria
            int columna = rand() % 10; // Generar columna aleatoria
            bool horizontal = rand() % 2 == 0; // Generar orientación aleatoria

            Barco* barco = new Barco(i < 1 ? 4 : (i < 3 ? 3 : (i < 6 ? 2 : 1))); // Crear barco con tamaño correspondiente
            partida.colocarBarco(jugador, fila, columna, barco, horizontal); // Colocar barco en el tablero del jugador
        }
    };

    // Colocar barcos aleatoriamente para ambos jugadores
    colocarBarcosAleatoriamente(partida, jugador1);
    colocarBarcosAleatoriamente(partida, jugador2);

    // Bucle principal del juego
    while (true) {
        // Turno de jugador 1
        std::cout << "Turno de " << jugador1.getNombre() << std::endl;
        partida.renderizar();
        std::cout << "Ingrese coordenadas para el ataque (fila columna): ";
        int fila, columna;
        std::cin >> fila >> columna;
        if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
            std::cout << "Coordenadas inválidas. Debe ser un número entre 1 y 10." << std::endl;
            continue;
        }
        if (partida.realizarAtaque(jugador1, fila - 1, columna - 1)) {
            std::cout << "¡" << jugador1.getNombre() << " ha ganado!" << std::endl;
            break;
        }

        // Turno de jugador 2
        std::cout << "Turno de " << jugador2.getNombre() << std::endl;
        partida.renderizar();
        std::cout << "Ingrese coordenadas para el ataque (fila columna): ";
        std::cin >> fila >> columna;
        if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
            std::cout << "Coordenadas inválidas. Debe ser un número entre 1 y 10." << std::endl;
            continue;
        }
        if (partida.realizarAtaque(jugador2, fila - 1, columna - 1)) {
            std::cout << "¡" << jugador2.getNombre() << " ha ganado!" << std::endl;
            break;
        }
    }

    return 0;
}
