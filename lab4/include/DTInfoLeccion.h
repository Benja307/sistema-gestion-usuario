#ifndef DTINFOLECCION
#define DTINFOLECCION

#include <string>
#include <set>
#include <iostream>
#include "DTInfoEjercicio.h"
using namespace std;

// set<DTInfoEjercicio> ejercicio;

class DTInfoLeccion {
    private: 
        string tema;
        string objetivo;
        set<DTInfoEjercicio> ejercicios;
    public:
        /* setters */
        void setTema(string tema);
        void setObjetivo(string objetivo);
        void setEjercicios(set<DTInfoEjercicio>);

        /* getters */ 
        string getTema();
        string getObjetivo();

        /* constructor y destructor */
        DTInfoLeccion(string tema, string objetivo);
        ~DTInfoLeccion();      
};

#endif