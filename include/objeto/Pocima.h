#ifndef POCIMA_H
#define POCIMA_H

#include "Objeto.h"
#include "Util.h"


class Pocima : public Objeto {

  private:

    int vidaExtra;
    Util util;
  public:

    Pocima()
        :Objeto("Pocima"),
        vidaExtra(util.aleatorio_en_rango(4,8)){};

    int getPosima(){
      return vidaExtra;
    };


    ~Pocima() override = default;

};

#endif