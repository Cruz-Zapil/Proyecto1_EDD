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

    string getPistaTree() {
    return temperatura;
  }


  int getClaveUbicacion() {
    // Normal para enemigos: XYZ → 153
    return posicionX * 100 + posicionY * 10 + posicionZ;
  }

    void setPista(string temperatura){
      this->temperatura = temperatura;
    }

    ~Pista() override = default;
};


#endif