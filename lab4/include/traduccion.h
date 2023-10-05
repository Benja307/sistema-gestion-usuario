#ifndef TRADUCCION
#define TRADUCCION

#include <string>
#include <iostream>
#include "DTEjercicio.h"
#include "DTCompletarPalabras.h"
#include "DTTraduccion.h"
#include "ejercicio.h"
using namespace std;

class Traduccion :  public Ejercicio {
    private: 
        string fraseATraducir;
        string solucion;
    public:
        // setter
        void setFraseATraducir(string fraseATraducir);
        void setSolucion(string solucion);

        // getter
        string getFraseATraducir();
        string getSolucion();
        bool compararSoluciones(string sol); // he doesnt know
        DTTraduccion* getDTTraduccion();
        // constructor y destructor
        Traduccion(int idEjercicio, string descripcion, string fraseATraducir, string solucion);
        virtual ~Traduccion();      
};



#endif