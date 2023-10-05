#ifndef COMPLETARPALABRAS
#define COMPLETARPALABRAS

#include <string>
#include <iostream>
#include "DTEjercicio.h"
#include "DTCompletarPalabras.h"
#include "DTTraduccion.h"
#include "ejercicio.h"
using namespace std;

class CompletarPalabras :  public Ejercicio {
    private: 
        string fraseACompletar;
        string solucion;
    public:
        // setter
        void setFraseACompletar(string fraseACompletar);
        void setSolucion(string solucion);

        // getter
        string getFraseACompletar();
        string getSolucion();

        bool compararSoluciones(string sol);
        DTCompletarPalabras* getDTCompletarPalabras();
        
        // constructor y destructor
        CompletarPalabras(int idEjercicio, string descripcion, string fraseACompletar, string solucion);

        virtual ~CompletarPalabras();      
};

#endif