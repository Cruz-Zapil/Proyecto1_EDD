#ifndef PISTA_H
#define PISTA_H

#include "Objeto.h"
#include "Util.h"


class Pista : public Objeto {

  private:
    string temperatura;
    Util util;

  public:

    Pista():
    Objeto("Pista"),
    temperatura("Frio"){};

    void  getPista(){
      util.colorVerdeJ("____________  "); util.colorAmarilloT(temperatura); util.colorVerde("  ____________");
    };



    void setPista(string temperatura){
      this->temperatura = temperatura;
    }

    ~Pista() override = default;
};


#endif