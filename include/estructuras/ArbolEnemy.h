//
// Created by CruzZapil on 7/04/25.
//

#ifndef ARBOLENEMY_H
#define ARBOLENEMY_H
#include <Enemigo.h>


using namespace std;

struct NodoEnemy {
    Enemigo* enemigo;
    NodoEnemy* izquierda;
    NodoEnemy* derecho;
    int ordenIngreso;

    NodoEnemy(Enemigo* e, int orden )
        : enemigo(e), izquierda(nullptr), derecho(nullptr), ordenIngreso(orden) {}

};

class ArbolEnemy {

private:
    NodoEnemy* raiz = nullptr;
    int cont=0;
    NodoEnemy* insertar(NodoEnemy* nodo, Enemigo* enemigo) {

        if (nodo == nullptr) return new NodoEnemy(enemigo, ++cont);

        if (enemigo->getClaveUbicacion() < nodo->enemigo->getClaveUbicacion())
            nodo->izquierda = insertar(nodo->izquierda, enemigo);
        else
            nodo->derecho = insertar(nodo->derecho, enemigo);

        return nodo;

    }

    void limpiar(NodoEnemy* nodo) {
        if (nodo != nullptr) {
            limpiar(nodo->izquierda);
            limpiar(nodo->derecho);
            delete nodo; // libera memoria
        }
    }


public:
    void insertar(Enemigo* e) {
        raiz = insertar(raiz, e);
    }

    void enOrden(NodoEnemy* nodo,  string lado ) {

        if (nodo != nullptr) {
            enOrden(nodo->izquierda, "izquierda");

            cout << "🧟 Enemigo No.: " << nodo->enemigo->getClaveUbicacion();
            cout << "  [Está en el lado: " << lado << "]" ;
            cout <<"  [Orden: "<< nodo->ordenIngreso<<"]"<<endl;

            enOrden(nodo->derecho, "derecha");
        }
    }

    void imprimirArbol(NodoEnemy* nodo, int espacio = 0, int separacion = 6) {
        if (nodo == nullptr)
            return;

        espacio += separacion;

        // Primero imprime el subárbol derecho (como rama derecha arriba)
        imprimirArbol(nodo->derecho, espacio);

        // Imprime el nodo actual con espacios
        cout << endl;
        for (int i = separacion; i < espacio; i++)
            cout << " ";
        cout << "🧟" << nodo->enemigo->getClaveUbicacion() << endl;

        // Luego imprime el subárbol izquierdo (como rama izquierda abajo)
        imprimirArbol(nodo->izquierda, espacio);
    }



    void mostrar() {
        enOrden(raiz, "raiz");
    }

    void mostrarArbol() {
        cout << "\n📦 Árbol Enemigos:\n";
        imprimirArbol(raiz);
    }


    void vaciar() {
        limpiar(raiz);
        raiz = nullptr;
    }

};



#endif //ARBOLENEMY_H
