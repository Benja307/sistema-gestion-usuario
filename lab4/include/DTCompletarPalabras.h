#ifndef DTCOMPLETARPALABRAS
#define DTCOMPLETARPALABRAS

#include <string>
#include <iostream>
#include "DTEjercicio.h"
using namespace std;

class DTCompletarPalabras :  public DTEjercicio {
    private: 
        string fraseACompletar;
        // string solucion;
    public:
        // setter
        void setFraseACompletar(string fraseACompletar);


        // getter
        string getFraseACompletar();


        // constructor y destructor
        DTCompletarPalabras(string fraseACompletar, string descripcion);
        ~DTCompletarPalabras();      

        // otros
        void mostrarDTCompletarPalabras();
};

#endif