#ifndef DTTRADUCCION
#define DTTRADUCCION

#include <string>
#include <iostream>
#include "DTEjercicio.h"
using namespace std;


class DTTraduccion : public DTEjercicio {
    private: 
        string fraseATraducir;
    public:
        // setter
        void setFraseATraducir(string fraseATraducir);

        // getter
        string getFraseATraducir();

        // constructor y destructor
        DTTraduccion(string fraseATraducir, string descripcion);
        ~DTTraduccion();   

        // otros
        void mostrarDTTraduccion();
};

#endif