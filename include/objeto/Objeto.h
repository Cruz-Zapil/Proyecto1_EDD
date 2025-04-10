#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>

using namespace std;

class Objeto {

protected:
    string tipoObjeto;
    int posicionX, posicionY, posicionZ;

public:
    Objeto() = default;

    /// Constructor
    Objeto(string tipoObjeto) {
        this->tipoObjeto = tipoObjeto;
    };

    void posicionamiento() {
        cout << tipoObjeto << "esta en la posicion:" << posicionX << " " << posicionY << " " << posicionZ << endl;
    };

    void setPosicion(int posX, int posY, int posZ) {
        this->posicionX = posX;
        this->posicionY = posY;
        this->posicionZ = posZ;
    }

    int getPosZ() {
        return posicionZ;
    };

    int getPosY() {
        return posicionY;
    }

    int getPosX() {
        return posicionX;
    }


    string getipoObjeto() {
        return tipoObjeto;
    };

    /// metodo concreto
    string posicion();

    /// destructor
    virtual ~Objeto() = default;
};


#endif
