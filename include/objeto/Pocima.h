#ifndef POCIMA_H
#define POCIMA_H

#include "Objeto.h"


class Pocima : public Objeto {

  private:

    int vidaExtra=4;

  public:

    Pocima();
    int vidaExtraPocima();


    ~Pocima() override = default;

};

#endif