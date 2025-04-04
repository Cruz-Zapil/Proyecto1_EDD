#ifndef TRAMPA_H
#define TRAMPA_H

#include "Objeto.h"
#include <string>

class Trampa : public Objeto {

  private:
     int nivelDanio;

  public:

    Trampa()
        :Objeto("Trampa"),
        nivelDanio(3){};

    int ataqueTrampa(){
      return nivelDanio;
    };

    ~Trampa() override = default;


};

#endif