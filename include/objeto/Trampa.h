#ifndef TRAMPA_H
#define TRAMPA_H

#include "Objeto.h"
#include <string>
#include "Util.h"

class Trampa : public Objeto {

  private:
     int nivelDanio;
     Util utils;
     int posicion;

  public:

    Trampa()
        :Objeto("Trampa"),
        nivelDanio(utils.aleatorio_en_rango(2,6)){};

    int getAtaqueTrampa(){
      return nivelDanio;
    };

    ~Trampa() override = default;


};

#endif