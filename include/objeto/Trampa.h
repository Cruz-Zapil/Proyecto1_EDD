#ifndef TRAMPA_H
#define TRAMPA_H

#include "Objeto.h"
#include <string>

class Trampa : public Objeto {

  private:
     int nivelAtaque=3;

  public:

    Trampa();
    int ataqueTrampa();

    ~Trampa() override = default;


};

#endif