#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>

using namespace std;

class Objeto {

    private:

        string tipoObjeto;
        int posicionX, posicionY, posicionZ;


    public:
        /// Constructor
        Objeto(string tipoObjeto, int posicionX, int posicionY, int posicionZ) {

            this->tipoObjeto = tipoObjeto;
            this->posicionX = posicionX;
            this->posicionY = posicionY;
            this->posicionZ = posicionZ;

        };

        void posicionamiento () {

            cout<< tipoObjeto <<"esta en la posicion:" << posicionX << " " << posicionY << " " << posicionZ << endl;
        };


        string gettipoObjeto() {
            return tipoObjeto;
        };

        /// metodo concreto 
        string posicion()  ;

        /// destructor
        virtual ~Objeto() = default;

};


#endif