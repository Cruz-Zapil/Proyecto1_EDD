//
// Created by CruzZapil on 9/04/25.
//

#ifndef PISTAS_H
#define PISTAS_H

#include <bits/locale_conv.h>

#include "Pista.h"
using namespace std;

struct NodoPista {
    Pista* pista;
    NodoPista* izquierda;
    NodoPista* derecha;
    int ordenIngreso;

    NodoPista(Pista* p, int orden) {
        pista = p;
        izquierda = nullptr;
        derecha = nullptr;
        ordenIngreso = orden;
    }

};

class ArbolPista {


    NodoPista* raiz = nullptr;
    int cont =0;
    NodoPista* insertar(NodoPista* nodo, Pista* pista) {

        if (nodo == nullptr) {
            return new NodoPista(pista, ++cont);
        }

        if (pista->getClaveUbicacion() < nodo->pista->getClaveUbicacion()) {
            nodo->izquierda = insertar(nodo->izquierda, pista);
        }else {
            nodo->derecha = insertar(nodo->derecha, pista);
        }
        return nodo;

    }

public:
    void limpiar(NodoPista* nodo) {
        if (nodo == nullptr) {
            limpiar(nodo->izquierda);
            limpiar(nodo->derecha);
            delete nodo;  // liberamos memoria
        }
    }

    void insertar(Pista* t) {
        raiz = insertar(raiz, t);
    }

    void enOrden(NodoPista* nodo, string lado) {
        if (nodo != nullptr) {
            enOrden(nodo->izquierda, "izquierda");

            cout <<"🔍 Pista No.: " << nodo->pista->getClaveUbicacion()<<" " << nodo->pista->getPistaTree();
            cout <<"  [Está en el lado: " << lado << "]" ;
            cout <<"  [Orden: "<< nodo->ordenIngreso<<"]"<<endl;

            enOrden(nodo->derecha, " derecha");
        }
    }

    void mostrar() {
        enOrden(raiz, "raiz");
    }

    void vaciar() {
        limpiar(raiz);
        raiz = nullptr;
    }
};



#endif //PISTAS_H
