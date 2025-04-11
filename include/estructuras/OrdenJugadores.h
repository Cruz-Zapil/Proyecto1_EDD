//
// Created by CruzZapil on 9/04/25.
//

#ifndef ORDENJUGADORES_H
#define ORDENJUGADORES_H
#include <Jugador.h>


struct NodoJugador {

    Jugador* jugador;
    NodoJugador* siguiente;

    NodoJugador(Jugador* jug) {
        jugador = jug;
        siguiente = nullptr;
    }
};

// clase
class OrdenJugadores {

private:
    NodoJugador* inicio;


public:
    OrdenJugadores() {
        inicio = nullptr;
    }

    // ingresar al final
    void ingresar(Jugador* jug) {
        NodoJugador* nuevo = new NodoJugador(jug);
        if (inicio==nullptr) {
            inicio= nuevo;
        }else {
            NodoJugador* tmp = inicio;
            while (tmp->siguiente!=nullptr) {
                tmp = tmp->siguiente;
            }
            tmp->siguiente = nuevo;
        }
    }
    void ordenarLista() {
        if (inicio == nullptr || inicio->siguiente == nullptr) {
            return;
        }

        bool ordenado;
        do {
            ordenado = true;
            NodoJugador* actual = inicio;
            while (actual->siguiente != nullptr) {
                if (actual->jugador->getPuntos() < actual->siguiente->jugador->getPuntos()) {
                    // Intercambiar valores
                    Jugador* temp = actual->jugador;
                    actual->jugador = actual->siguiente->jugador;
                    actual->siguiente->jugador = temp;
                    ordenado = false;
                }
                actual = actual->siguiente;
            }
        } while (!ordenado);
    }

    void mostrarJugadores() {
        NodoJugador* tmp = inicio;
        while (tmp != nullptr) {
            tmp->jugador->mostrarInfoJugador();  // Método que muestra datos
            tmp = tmp->siguiente;
        }
    }

    void limpiarLista() {
        NodoJugador* temp;
        while (inicio != nullptr) {
            temp = inicio;
            inicio = inicio->siguiente;
            delete temp->jugador;  // También libera la memoria
            delete temp;
        }
        inicio = nullptr;
    }


    // Destructor
    ~OrdenJugadores() {
        NodoJugador* temp;
        while (inicio != nullptr) {
            temp = inicio;
            inicio = inicio->siguiente;
            delete temp->jugador; // liberamos también el jugador
            delete temp;
        }
    }

};



#endif //ORDENJUGADORES_H
