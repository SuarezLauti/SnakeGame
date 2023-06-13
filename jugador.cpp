#include "jugador.h"
#include <iostream>
using namespace std;
jugador::jugador(const std::string& nombre) {
    Nombre = nombre;
}

void jugador::setNombre(const std::string& nombre) {
    Nombre = nombre;
}

const std::string& jugador::getNombre() const {
    return Nombre;
}

char jugador::escuchardireccion() {
    cout << endl << "Ingrese un valor (w, s, a, d): ";
    char dir;
    cin >> dir;
    return dir;
}