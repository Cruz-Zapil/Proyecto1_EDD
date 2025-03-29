#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(int ataque, int x, int y, int z, int vida, int nivel, string nombre, int tiempoTotal)
    : Objeto(ataque, x, y, z), vida(vida), nivel(nivel), nombre(nombre), tiempoTotal(tiempoTotal) {}

void Jugador::atacar() {
    cout << nombre <<" ataca con un poder de: " << ataque <<endl;
}

void Jugador::recibirAtaque(int ataque, string nombre) {
    vida -= ataque;
    cout << nombre << " ha recibido un ataque de "<< nombre << ataque << " puntos de daño" << endl;
    cout << "Vida restante: " << vida << endl;
}
