#include "../include/DTInfoInscripcion.h"

DTInfoInscripcion::DTInfoInscripcion(string nombreEstudiante, DTFecha* fechaInscripcion){
    this->nombreEstudiante = nombreEstudiante;
    this->fechaInscripcion = fechaInscripcion;
};

DTInfoInscripcion::~DTInfoInscripcion(){};      

/* setters */
void DTInfoInscripcion::setNombreEstudiante(string nombreEstudiante){
    this->nombreEstudiante = nombreEstudiante;
};

void DTInfoInscripcion::setFechaInscripcion(DTFecha* fechaInscripcion){
    this->fechaInscripcion = fechaInscripcion;
};


/* getters */ 
string DTInfoInscripcion::getNombreEstudiante(){
    return nombreEstudiante;
};

DTFecha* DTInfoInscripcion::getFechaInscripcion(){
    return fechaInscripcion;
};

        