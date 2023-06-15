#include "vibora.h"

vibora::vibora(char f) {
    Cabeza_x = 5;
    Cabeza_y = 5;
    Direcion = f;
    Cuerpo.push_back(std::make_pair(Cabeza_x, Cabeza_y));
    longitud = 1;
}

void vibora::setDirecion(char f) {
    Direcion = f;
}

char vibora::getDirecion() {
    return Direcion;
}

void vibora::setCabeza_x(int x) {
    Cabeza_x += x;
    actualizarCuerpo();  // Actualizar el cuerpo de la serpiente después de mover la cabeza
}

void vibora::setCabeza_y(int z) {
    Cabeza_y += z;
    actualizarCuerpo();  // Actualizar el cuerpo de la serpiente después de mover la cabeza
}

int vibora::getCabeza_x() {
    return Cabeza_x;
}

int vibora::getCabeza_y() {
    return Cabeza_y;
}

void vibora::actualizarCuerpo() {
    Cuerpo.push_back(std::make_pair(Cabeza_x, Cabeza_y));

    if (Cuerpo.size() > longitud) {
        Cuerpo.erase(Cuerpo.begin());
    }
}

int vibora::obtenerDireccionCabeza(jugador J) {
    switch (getDirecion()) {
        case 's':
            setCabeza_y(1);
            return 4;
        case 'w':
            setCabeza_y(-1);
            return 5;
        case 'd':
            setCabeza_x(1);
            return 7;
        case 'a':
            setCabeza_x(-1);
            return 6;
        default:
            std::cout << "Ingresaste un valor invalido" << std::endl;
            exit;
            break;
    }
    return 0;
}