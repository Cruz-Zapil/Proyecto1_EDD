#include <iostream>
#include <fstream>
#include <limits>

#include "Jugar.h"
#include "Trampa.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Pista.h"
#include "Pocima.h"


using namespace std;


void Jugar::iniciarJuego() {
    string nombreJugador;

    util.colorVerde(" Ingrese su nombre: ");
    cin >> nombreJugador;
    jugador = new Jugador(nombreJugador);

    util.colorMagenta("Ingrese el tamaño del Mundo");
    cin >> fila >> columna >> altura;
    // Manejo de error por entrada no numérica
    if (cin.fail() || fila < 2 || columna < 2 || altura < 2) {
        cin.clear(); // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        numeroNodos = tamanioFijo * tamanioFijo * tamanioFijo;
        crearTablero(tamanioFijo, tamanioFijo, tamanioFijo);
    } else {
        numeroNodos = fila * columna * altura;
        crearTablero(fila, columna, altura);
    }

    /// mas metodos:
    crearPersonaje();
    crearTesoro();
    crearPista();
    crearObjetos();
    tablero3D->imprimirTablero2D(jugador->getPosZ());

    jugar();
}

void Jugar::crearTablero(int fila, int columna, int altura) {
    if (tablero3D != nullptr) {
        delete tablero3D;
    }
    /// crear tablero
    tablero3D = new Tablero<Objeto>(fila, columna, altura);

}

void Jugar::crearPersonaje() {
    bool tmpPersonaje;
    do {
        int tmpx = util.aleatorio_en_rango(0, fila);
        int tmpy = util.aleatorio_en_rango(0, columna);
        int tmpz = util.aleatorio_en_rango(0, altura);
        tmpPersonaje = (tablero3D->setObjeto(tmpx, tmpy, tmpz, jugador));

        if (tmpPersonaje) {
            cout << "Jugador creado en (" << tmpx << ", " << tmpy << ", " << tmpz << ")\n";
            jugador->setPosicion(tmpx, tmpy, tmpz);
        }

    } while (!tmpPersonaje);
}

void Jugar::crearTesoro() {
    Objeto* tesoro = new Tesoro();
    if (!colocarObjetoEnTablero(tesoro)) {
        delete tesoro; // Si no se colocó, liberar memoria
    }
}


void Jugar::crearPista() {
    int cantidad = numeroNodos / 8;
    for (int i = 0; i < cantidad; i++) {
        Objeto* pista = new Pista();
        if (!colocarObjetoEnTablero(pista)) {
            delete pista; // Liberar si no se pudo colocar
        }
    }
}

void Jugar::crearObjetos() {
    int cantidad = numeroNodos / 8;

    for (int i = 0; i < cantidad; i++) {
        // Enemigo
        Objeto* enemigo = new Enemigo();
        if (!colocarObjetoEnTablero(enemigo)) {
            delete enemigo;
        }

        // Trampa
        Objeto* trampa = new Trampa();
        if (!colocarObjetoEnTablero(trampa)) {
            delete trampa;
        }

        // Pócima
        Objeto* pocima = new Pocima();
        if (!colocarObjetoEnTablero(pocima)) {
            delete pocima;
        }
    }
}


bool Jugar::colocarObjetoEnTablero(Objeto* obj) {

    int intentos = 0;
    int intentosFijos = numeroNodos / 8;
    bool colocado = false;
    while (!colocado && intentos < intentosFijos) {
        int x = util.aleatorio_en_rango(0, fila);
        int y = util.aleatorio_en_rango(0, columna);
        int z = util.aleatorio_en_rango(0, altura);
        colocado = tablero3D->setObjeto(x, y, z, obj);
        if (colocado) {
            // Guardar la posición si el objeto es un Tesoro
            Tesoro* t = dynamic_cast<Tesoro*>(obj);
            if (t != nullptr) {
                tesoroX = x;
                tesoroY = y;
                tesoroZ = z;
            }

            // Si es una pista, asignar la pista según distancia al tesoro
            Pista* pista = dynamic_cast<Pista*>(obj);
            if (pista != nullptr) {
                int distancia = abs(x - tesoroX) + abs(y - tesoroY) + abs(z - tesoroZ);
                if (distancia == 1) {
                    pista->setPista("Caliente");
                } else if (distancia <= 3) {
                    pista->setPista("Tibio");
                } else {
                    pista->setPista("Frío");
                }
            }
        } else {
            ++intentos;
        }
    }
    return colocado;
}


void Jugar::jugar() {

    bool vida = false;

    do {
      //  moverJugador(direccion);


    }while (!vida);

}


void Jugar::moverJugador(string direccion) {

    NodoCasilla<Objeto>* destino = tablero3D->casillaSiguiente(jugador, direccion);

    if (destino != nullptr) {

        if (destino->ocupado) {
            Objeto* objDestino = destino->contenido;

            // Verificar el tipo de objeto en la casilla destino
            if (dynamic_cast<Enemigo*>(objDestino)) {
                iniciarBatalla(dynamic_cast<Enemigo*>(objDestino));
            }
            else if (dynamic_cast<Trampa*>(objDestino)) {
                manejarTrampa(dynamic_cast<Trampa*>(objDestino));
            }
            else if (dynamic_cast<Pocima*>(objDestino)) {
                manejarPocima(dynamic_cast<Pocima*>(objDestino));
            }
            else if (dynamic_cast<Pista*>(objDestino)) {
                manejarPista(dynamic_cast<Pista*>(objDestino));
            }
            else {
                util.colorRojo("Movimiento inválido: la casilla está ocupada por un objeto desconocido.");
            }
        } else {
            // Si la casilla no está ocupada, solo movemos al jugador
            tablero3D->eliminarObjeto(jugador->getPosX(), jugador->getPosY(), jugador->getPosZ());
            jugador->setPosicion(destino->x, destino->y, destino->z);
            tablero3D->setObjeto(jugador->getPosX(), jugador->getPosY(), jugador->getPosZ(), jugador);
        }

        // Imprimir el tablero después del movimiento
        tablero3D->imprimirTablero2D(jugador->getPosZ());
    } else {
        cout << "Movimiento fallido: fuera de los límites o dirección inválida." << endl;
    }
}


