#ifndef PISTA_H
#define PISTA_H

#include "Objeto.h"


class Pista : public Objeto {

  private:
    string temperatura;

  public:

    Pista():
    Objeto("Pista"),
    temperatura("Frio"){};

    string getPista(){
      return temperatura;
    };

    void setPista(string temperatura){
      this->temperatura = temperatura;
    }

    ~Pista() override = default;
};


#endif