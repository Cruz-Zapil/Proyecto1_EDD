#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>

using namespace std;

template <typename T>

/// definimos classe casilla
class NodoCasilla{

    /// atributos de Casiila
public:
    T *contenido;
    bool bloqueado;
    bool ocupado;

    // Punteros 3D
    // nueva dimesion Z
    NodoCasilla<T> *arriba;
    NodoCasilla<T> *abajo;
    /// dimesion xy
    NodoCasilla<T> *izquierda;
    NodoCasilla<T> *derecha;
    NodoCasilla<T> *adelante;
    NodoCasilla<T> *atras;

    // Constructor
    NodoCasilla()
    {
        contenido = nullptr;
        bloqueado = false;
        ocupado = false;
        arriba = abajo = izquierda = derecha = adelante = atras = nullptr;
    }
};

/// definimos clase Tablero
template <typename T>
class Tablero
{

public:
    NodoCasilla<T> *inicio;
    /// Tablero 3D
    /// dimesiones del tablero
    int filas=2;
    int columnas=2;
    int altura=2;
    NodoCasilla<T>*** tablero = new NodoCasilla<T>**[filas];

    Tablero(int filas, int columnas, int altura);

    void construirTablero3D();
    void imprimirTablero2D(int z);                    // Imprime un plano 2D desde vita de planta

    void agregarObjetoRamdon();
    NodoCasilla<T> *getCasilla(int x, int y, int z);  /// coordenadas del Objeto
    bool setObjeto(int x, int y, int z, T *objeto);   // agregregar Objeto en 3D

};



#endif

