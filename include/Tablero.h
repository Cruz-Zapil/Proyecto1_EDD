#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "Util.h"
#include "Objeto.h"
#include "Jugador.h"
#include "Pista.h"
#include "Pocima.h"


using namespace std;

/// ==========================
/// Clase NodoCasilla
/// ==========================
template<typename T>
class NodoCasilla {
public:
    int x, y, z;
    T *contenido;
    bool bloqueado;
    bool ocupado;

    // Punteros 3D
    NodoCasilla<T> *arriba;
    NodoCasilla<T> *abajo;
    NodoCasilla<T> *izquierda;
    NodoCasilla<T> *derecha;
    NodoCasilla<T> *adelante;
    NodoCasilla<T> *atras;

    // Constructor
    NodoCasilla() {
        contenido = nullptr;
        bloqueado = false;
        ocupado = false;
        arriba = abajo = izquierda = derecha = adelante = atras = nullptr;
    }
};

/// ==========================
/// Clase Tablero
/// ==========================
template<typename T>
class Tablero {
public:
    NodoCasilla<T> *inicio;
    int fila;
    int columna;
    int altura;
    NodoCasilla<T> ***tablero;
    Util util;

    // Constructor
    Tablero(int fila, int columna, int altura);

    // Métodos
    void construirTablero3D();

    void imprimirTablero2D(int z);

    void agregarObjetoRamdon();

    NodoCasilla<T> *getObjeto(int x, int y, int z);

    bool setObjeto(int x, int y, int z, T *objeto);

    void eliminarObjeto(int x, int y, int z);

    NodoCasilla<T> *casillaSiguiente(Objeto *jugador, string direccion);
};

/// ==========================
/// Implementación de Métodos
/// ==========================

template<typename T>
Tablero<T>::Tablero(int filas, int columnas, int altura) {
    this->fila = filas;
    this->columna = columnas;
    this->altura = altura;
    inicio = nullptr;

    construirTablero3D();
}

template<typename T>
void Tablero<T>::construirTablero3D() {
    tablero = new NodoCasilla<T> **[fila];
    for (int i = 0; i < fila; i++) {
        tablero[i] = new NodoCasilla<T> *[columna];
        for (int j = 0; j < columna; j++) {
            tablero[i][j] = new NodoCasilla<T>[altura];
        }
    }

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            for (int k = 0; k < altura; k++) {
                if (i > 0)
                    tablero[i][j][k].arriba = &tablero[i - 1][j][k];
                if (i < fila - 1)
                    tablero[i][j][k].abajo = &tablero[i + 1][j][k];
                if (j > 0)
                    tablero[i][j][k].izquierda = &tablero[i][j - 1][k];
                if (j < columna - 1)
                    tablero[i][j][k].derecha = &tablero[i][j + 1][k];
                if (k > 0)
                    tablero[i][j][k].adelante = &tablero[i][j][k - 1];
                if (k < altura - 1)
                    tablero[i][j][k].atras = &tablero[i][j][k + 1];
            }
        }
    }

    cout << "Mundo 3D construido" << endl;
    inicio = &tablero[0][0][0];
}

template<typename T>
void Tablero<T>::imprimirTablero2D(int z) {
    if (z < 2 || z >= altura) {
        cout << "Altura no válida" << endl;
        return;
    }

    cout << "Tablero en 2D (altura " << z << "):" << endl;

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (tablero[i][j][z].ocupado && tablero[i][j][z].contenido != nullptr) {
                /// verificar si el contenido es un personaje para mostrarl

                Objeto *obj = tablero[i][j][z].contenido; // Correcto

                if (obj == nullptr) {
                    cout << "[ ] ";
                    continue;
                }
                if (dynamic_cast<Jugador *>(obj)) {
                    util.colorVerdeJ("[Õ] ");
                } else if (dynamic_cast<Pista *>(obj)) {
                    util.colorMagentaP("[╬] ");
                } else if (dynamic_cast<Pocima *>(obj)) {
                    util.colorAzulP("[°] ");
                } else {
                    cout << "[ ] ";
                }
            } else {
                cout << "[ ] ";
            }
        }
        cout << endl;
    }
}


template<typename T>
NodoCasilla<T> *Tablero<T>::casillaSiguiente(Objeto *jugador, string direccion) {
    NodoCasilla<T> *destino = nullptr;

    // Obtener las coordenadas actuales del jugador
    int x = jugador->getPosX();
    int y = jugador->getPosY();
    int z = jugador->getPosZ();

    // Según la dirección, determinamos la casilla destino
    if (direccion == "q" && x > 0) {
        // Mover hacia arriba (si no está en el borde)
        destino = &tablero[x - 1][y][z];
    } else if (direccion == "e" && x < fila - 1) {
        // Mover hacia abajo (si no está en el borde)
        destino = &tablero[x + 1][y][z];
    } else if (direccion == "a" && y > 0) {
        // Mover hacia la izquierda
        destino = &tablero[x][y - 1][z];
    } else if (direccion == "d" && y < columna - 1) {
        // Mover hacia la derecha
        destino = &tablero[x][y + 1][z];
    } else if (direccion == "w" && z > 0) {
        // Mover hacia adelante
        destino = &tablero[x][y][z - 1];
    } else if (direccion == "s" && z < altura - 1) {
        // Mover hacia atrás
        destino = &tablero[x][y][z + 1];
    }

    // Si el destino es válido y no está ocupado, podemos mover al jugador
    if (destino != nullptr && !destino->ocupado) {
        return destino;
    } else {
        util.colorRojo("Movimiento inválido o fuera de los límites.");
        return nullptr;
    }
}


template<typename T>
NodoCasilla<T> *Tablero<T>::getObjeto(int x, int y, int z) {
    if (x >= 0 && x < fila && y >= 0 && y < columna && z >= 0 && z < altura) {
        return &tablero[x][y][z];
    }
    return nullptr;
}


template<typename T>
bool Tablero<T>::setObjeto(int x, int y, int z, T *objeto) {
    if (x >= 0 && x < fila && y >= 0 && y < columna && z >= 0 && z < altura) {
        NodoCasilla<T> *nodo = &tablero[x][y][z];

        if (!nodo->ocupado && !nodo->bloqueado) {
            nodo->contenido = objeto;
            nodo->ocupado = true;
            return true;
        }
    }
    return false;
}

template<typename T>
void Tablero<T>::eliminarObjeto(int x, int y, int z) {
    // Verificamos que la posición sea válida
    if (x >= 0 && x < fila && y >= 0 && y < columna && z >= 0 && z < altura) {
        // Establecemos el contenido del nodo en nullptr para eliminar el objeto

        tablero[x][y][z].contenido = nullptr;
        tablero[x][y][z].ocupado = false;
    }
}


#endif // TABLERO_H
