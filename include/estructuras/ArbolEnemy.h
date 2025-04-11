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
    int altura;

    NodoEnemy(Enemigo* e, int orden )
        : enemigo(e), izquierda(nullptr), derecho(nullptr),
          ordenIngreso(orden), altura(1) {}
};
class ArbolEnemy {

private:
    NodoEnemy* raiz = nullptr;
    int cont=0;

    /// complejidad:
    /// complejidad insertar:
    /// peor de lo casos: O(log n)
    /// mejor de los casos: O(log n)
    ///
    NodoEnemy* insertar(NodoEnemy* nodo, Enemigo* enemigo) {
        if (nodo == nullptr) return new NodoEnemy(enemigo, ++cont);

        if (enemigo->getClaveUbicacion() < nodo->enemigo->getClaveUbicacion())
            nodo->izquierda = insertar(nodo->izquierda, enemigo);
        else if (enemigo->getClaveUbicacion() > nodo->enemigo->getClaveUbicacion())
            nodo->derecho = insertar(nodo->derecho, enemigo);
        else
            return nodo; // no se permie repetidos

        // chqueamos altura
        nodo->altura = 1 + max(altura(nodo->izquierda), altura(nodo->derecho));

        // vemos valance
        int balance = obtenerBalance(nodo);


        // de izquirda a izquierda
        if (balance > 1 && enemigo->getClaveUbicacion() < nodo->izquierda->enemigo->getClaveUbicacion())
            return rotarDerecha(nodo);

        // de derecha  a dercha
        if (balance < -1 && enemigo->getClaveUbicacion() > nodo->derecho->enemigo->getClaveUbicacion())
            return rotarIzquierda(nodo);

        // de izquierda a derecha
        if (balance > 1 && enemigo->getClaveUbicacion() > nodo->izquierda->enemigo->getClaveUbicacion()) {
            nodo->izquierda = rotarIzquierda(nodo->izquierda);
            return rotarDerecha(nodo);
        }

        // de derehca a izquierda
        if (balance < -1 && enemigo->getClaveUbicacion() < nodo->derecho->enemigo->getClaveUbicacion()) {
            nodo->derecho = rotarDerecha(nodo->derecho);
            return rotarIzquierda(nodo);
        }

        return nodo;
    }


    void limpiar(NodoEnemy* nodo) {
        if (nodo != nullptr) {
            limpiar(nodo->izquierda);
            limpiar(nodo->derecho);
            delete nodo; // libera memoria
        }
    }

    int altura(NodoEnemy* nodo) {
        return nodo ? nodo->altura : 0;
    }

    int obtenerBalance(NodoEnemy* nodo) {
        return nodo ? altura(nodo->izquierda) - altura(nodo->derecho) : 0;
    }

    NodoEnemy* rotarDerecha(NodoEnemy* y) {
        NodoEnemy* x = y->izquierda;
        NodoEnemy* T2 = x->derecho;

        x->derecho = y;
        y->izquierda = T2;

        y->altura = max(altura(y->izquierda), altura(y->derecho)) + 1;
        x->altura = max(altura(x->izquierda), altura(x->derecho)) + 1;

        return x;
    }

    NodoEnemy* rotarIzquierda(NodoEnemy* x) {
        NodoEnemy* y = x->derecho;
        NodoEnemy* T2 = y->izquierda;

        y->izquierda = x;
        x->derecho = T2;

        x->altura = max(altura(x->izquierda), altura(x->derecho)) + 1;
        y->altura = max(altura(y->izquierda), altura(y->derecho)) + 1;

        return y;
    }

public:
    void insertar(Enemigo* e) {
        raiz = insertar(raiz, e);
    }

    /// complejidad:
    /// complejidad enOrden:
    /// peor de lo casos: O(n)
    /// mejor de los casos: O(n)
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
