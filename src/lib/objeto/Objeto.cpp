
#include "Objeto.h"
#include <iostream>

/// constructor 
/*
Objeto::Objeto(int ataque, int x, int y, int z)
    : ataque(ataque), posicionX(x), posicionY(y), posicionZ(z) {}
*/

Objeto::Objeto(int ataque, int x, int y, int z) {
    this->ataque = ataque;
    this->posicionX = x;
    this->posicionY = y;
    this->posicionZ = z;
}

/// metodo para obtener la posicion

string Objeto::posicion() {
    return "Posicion: " + to_string(posicionX) + ", " + to_string(posicionY) + ", " + to_string(posicionZ);
}