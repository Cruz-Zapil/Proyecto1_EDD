#ifndef TRAMPA_H
#define TRAMPA_H

#include "Objeto.h"
#include <string>
#include "Util.h"

class Trampa : public Objeto {

  private:
     int nivelDanio;
     Util utils;


  public:

    Trampa()
        :Objeto("Trampa"),
        nivelDanio(utils.aleatorio_en_rango(2,6)){};

    int getAtaqueTrampa(){
      return nivelDanio;
    };

    int getClaveUbicacion() {
        // Invertimos el orden  ZYX → 351
        return posicionZ * 100 + posicionY * 10 + posicionX;
    }


    void getPosicion() {
        cout<<posicionX;
    }

    ~Trampa() override = default;


};

#endif