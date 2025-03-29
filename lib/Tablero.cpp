#include "Tablero.h"

template <typename T>
Tablero<T>::Tablero(int filas, int columnas, int altura)  {

        if (filas > 2 || columnas > 2 || altura > 2) {
            
            this->fila = filas;
            this->columna = columnas;
            this->altura = altura;
        }

        inicio = nullptr;

        construirTablero3D();
    }


template <typename T>
void Tablero<T>::construirTablero3D(){

    /// creamos el tablero en 3D

    for (int i = 0; i < fila; i++) {
        tablero[i] = new NodoCasilla<T>*[columna];
        for (int j = 0; j < columna; j++) {
            tablero[i][j] = new NodoCasilla<T>[altura];
        }
    }


    /// enlazamos cada nodo con sus vecinos
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            for (int k = 0; k < altura; k++) {
                if (i > 0) {
                    tablero[i][j][k].arriba = &tablero[i - 1][j][k];
                }
                if (i < fila - 1) {
                    tablero[i][j][k].abajo = &tablero[i + 1][j][k];
                }
                if (j > 0) {
                    tablero[i][j][k].izquierda = &tablero[i][j - 1][k];
                }
                if (j < columna - 1) {
                    tablero[i][j][k].derecha = &tablero[i][j + 1][k];
                }
                if (k > 0) {
                    tablero[i][j][k].adelante = &tablero[i][j][k - 1];
                }
                if (k < altura - 1) {
                    tablero[i][j][k].atras = &tablero[i][j][k + 1];
                }
            }
        }

        /// apuntamos al nodo inicio:
        inicio = &tablero[0][0][0];


    }

}

template <typename T>
void Tablero<T>::imprimirTablero2D(int z) {

        /// Imprime un plano 2D desde vista de planta
        /// z = altura
        if (z < 0 || z >= altura) {
            cout << "Altura no valida" << endl;
            return;
        }

        cout << "Tablero en 2D (altura " << z << "):" << endl;
        cout << "   ";

        for (int i = 0; i < fila; i++) {

            (i>9) ? cout << "   "<<i : cout << "  "<<i;

            for (int j = 0; j < columna; j++) {
                (j>9) ? cout << " "<<i : cout <<i;

                cout << tablero[i][j][z].ocupado ? tablero[i][j][z]->contenido->getString() : "[ ] ";

            }
            cout << endl;
        }
    }




