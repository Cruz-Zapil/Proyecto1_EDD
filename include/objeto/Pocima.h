#ifndef POCIMA_H
#define POCIMA_H

#include "Objeto.h"


class Pocima : public Objeto {

  private:

    int vidaExtra;

  public:

    Pocima()
        :Objeto("Pocima"),
        vidaExtra(10){};

    int getPosima(){
      return vidaExtra;
    };


    ~Pocima() override = default;

};

#endif