#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>

using namespace std;

class Objeto {

    private:
        int ataque;
        int posicionX, posicionY, posicionZ;

    public:
        /// Constructor
        Objeto(int ataque, int posicionX, int posicionY, int posicionZ);

        /// metodo virtual 
        virtual void atacar() = 0;

        /// metodo concreto 
        string posicion()  ;

        /// destructor
        virtual ~Objeto() = default;

};


#endif