#include "juego.h"
#include "jugador.h"
#include "vibora.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib> // Agregado para la función srand y rand
#include <ctime> // Agregado para la función time

using namespace std;

void Menu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Reintentar" << endl;
    cout << "2. Salir" << endl;
    cout << "Ingrese su opcion: ";
}

void Titulo() {
    cout << "===============================" << endl;
    cout << "          SNAKE GAME" << endl;
    cout << "===============================" << endl;
    cout << endl;
}

int main() {
    srand(time(NULL)); // Inicializar la semilla del generador de números aleatorios

    bool reintentar = false;
    string nombre;
    cout << "Bienvenido jugador, ingresa tu nombre: " << endl;
    cin >> nombre;

    do {
        int opcion;
        bool perdiste = false;
        try {
            Titulo();

            juego A(15, 16);
            jugador J(nombre);
            vibora V('n');

            A.Jugar(V, J);
        } catch (const out_of_range& e) {
            cerr << "Error: Fuera de rango: " << e.what() << endl;
        } catch (const runtime_error& e) {
            cerr << "Error en el juego: " << e.what() << endl;
        } catch (...) {
            cerr << "Error desconocido ocurrido en el juego." << endl;
        }

        Menu();
        cin >> opcion;
        if (opcion == 1) {
            reintentar = true;
            system("cls"); // Limpia la consola (para sistemas UNIX)
        } else if (opcion == 2) {
            reintentar = false;
        } else {
            cout << "Opcion invalida. Saliendo del juego." << endl;
            reintentar = false;
        }

        if (reintentar) {
            juego A(15, 16);
            A.Reiniciar();
        }
    } while (reintentar);

    return 0;
}