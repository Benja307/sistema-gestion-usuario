#ifndef DTINFOINSCRIPCION
#define DTINFOINSCRIPCION

#include <string>
#include <iostream>
#include "DTFecha.h"
using namespace std;

class DTInfoInscripcion {
    private: 
        string nombreEstudiante;
        DTFecha* fechaInscripcion;
    public:
        /* setters */
        void setNombreEstudiante(string nombreEstudiante);
        void setFechaInscripcion(DTFecha* fechaInscripcion);

        /* getters */ 
        string getNombreEstudiante();
        DTFecha* getFechaInscripcion();

        /* constructor y destructor */
        DTInfoInscripcion(string nombreEstudiante, DTFecha* fechaInscripcion);
        ~DTInfoInscripcion();      
};

#endif