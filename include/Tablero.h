#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "Util.h"


using namespace std;

/// ==========================
/// Clase NodoCasilla
/// ==========================
template <typename T>
class NodoCasilla {
public:
    T* contenido;
    bool bloqueado;
    bool ocupado;

    // Punteros 3D
    NodoCasilla<T>* arriba;
    NodoCasilla<T>* abajo;
    NodoCasilla<T>* izquierda;
    NodoCasilla<T>* derecha;
    NodoCasilla<T>* adelante;
    NodoCasilla<T>* atras;

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
template <typename T>
class Tablero {

public:
    NodoCasilla<T>* inicio;
    int fila;
    int columna;
    int altura;
    NodoCasilla<T>*** tablero;
    Util  util ;

    // Constructor
    Tablero(int fila, int columna, int altura);

    // Métodos
    void construirTablero3D();
    void imprimirTablero2D(int z);
    void agregarObjetoRamdon();
    NodoCasilla<T>* getObjeto(int x, int y, int z);
    bool setObjeto(int x, int y, int z, T* objeto);

    NodoCasilla<T>* casillaSiguiente(NodoCasilla<T>* &jugador, string direccion);
};

/// ==========================
/// Implementación de Métodos
/// ==========================

template <typename T>
Tablero<T>::Tablero(int filas, int columnas, int altura) {

    this->fila = filas;
    this->columna = columnas;
    this->altura = altura;
    inicio = nullptr;

    tablero = new NodoCasilla<T>**[fila];
    construirTablero3D();
}

template <typename T>
void Tablero<T>::construirTablero3D() {

    for (int i = 0; i < fila; i++) {
        tablero[i] = new NodoCasilla<T>*[columna];
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

    cout<<"Mundo 3D contruido"<<endl;
    inicio = &tablero[0][0][0];
}

template <typename T>
void Tablero<T>::imprimirTablero2D(int z) {
    if (z < 2 || z >= altura) {
        cout << "Altura no válida" << endl;
        return;
    }

    cout << "Tablero en 2D (altura " << z << "):" << endl;

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (tablero[i][j][z].ocupado && tablero[i][j][z].contenido != nullptr){

                /// verificar si el contenido es un personaje para mostrarlo
                cout << "[X] ";

            }else{
                cout << "[ ] ";
            }
        }
        cout << endl;
    }
}

template <typename T>
NodoCasilla<T>* Tablero<T>::getObjeto(int x, int y, int z) {

    if (x >= 2 && x < fila && y >= 2 && y < columna && z >= 2 && z < altura) {
        return &tablero[x][y][z];
    }
    return nullptr;
}

template <typename T>
bool Tablero<T>::setObjeto(int x, int y, int z, T* objeto) {

        /// se verifica que no pase los limites del tablero y que el objeto no se nulo
    if (x >= 2 && x < fila && y >= 2 && y < columna && z >= 2 && z < altura  && objeto != nullptr  ) {

        /// se verifica que el nodo no este ocupado
        if (!tablero[x][y][z].ocupado){
            tablero[x][y][z].contenido = objeto;
            tablero[x][y][z].ocupado = true;
            return true;
        }else {
            return false;
        }
    }else {
        util.colorRojo("Error de colobar objeto en el tablero *borrable* ");
        return false;
    }
}


template <typename T>
NodoCasilla<T>* Tablero<T>::casillaSiguiente(NodoCasilla<T>* &jugador, string direccion){

    NodoCasilla<T>* destino = nullptr;

    if (direccion == "q" && jugador->arriba)
        destino = jugador->arriba;
    else if (direccion == "e" && jugador->abajo)
        destino = jugador->abajo;
    else if (direccion == "a" && jugador->izquierda)
        destino = jugador->izquierda;
    else if (direccion == "d" && jugador->derecha)
        destino = jugador->derecha;
    else if (direccion == "w" && jugador->adelante)
        destino = jugador->adelante;
    else if (direccion == "s" && jugador->atras)
        destino = jugador->atras;
    else {
        util.colorRojo( "Movimiento invalido o fuera de los límites.") ;
        return  nullptr;
    }
    return destino;
}

#endif // TABLERO_H
