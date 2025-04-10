//
// Created by CruzZapil on 7/04/25.
//

#ifndef ARBOLTRAMPA_H
#define ARBOLTRAMPA_H
#include <Trampa.h>

using namespace std;

struct NodoTrampa {

    Trampa* trampa;
    NodoTrampa* izquierda;
    NodoTrampa* derecha;

    NodoTrampa(Trampa* trampa)
        : trampa(trampa), izquierda(nullptr), derecha(nullptr) {}

};

class ArbolTrampa {

private:

    NodoTrampa* raiz = nullptr;

    NodoTrampa* insertar(NodoTrampa* nodo, Trampa* t) {
        if (nodo == nullptr) return new NodoTrampa(t);

        if (t->getClaveUbicacion() < nodo->trampa->getClaveUbicacion())
            nodo->izquierda = insertar(nodo->izquierda, t);
        else
            nodo->derecha = insertar(nodo->derecha, t);

        return nodo;
    }

    void limpiar(NodoTrampa* nodo) {
        if (nodo != nullptr) {
            limpiar(nodo->izquierda);
            limpiar(nodo->derecha);
            delete nodo; // libera memoria
        }
    }


public:
    void insertar(Trampa* t) {
        raiz = insertar(raiz, t);
    }

    void enOrden(NodoTrampa* nodo, string lado ) {
        if (nodo != nullptr) {
            enOrden(nodo->izquierda, "izquierda");
            cout << "💣 Trampa No: " << nodo->trampa->getClaveUbicacion();
            cout << "  [Está en el lado: " << lado << "]" << endl;
            enOrden(nodo->derecha, "derecha");
        }
    }

    void mostrar() {
        enOrden(raiz, "Raiz");
    }

    void vaciar() {
        limpiar(raiz);
        raiz = nullptr;
    }

};



#endif //ARBOLTRAMPA_H
