#include "../include/DTInfoEjercicio.h"

DTInfoEjercicio::DTInfoEjercicio(string descripcion, string informacion){
    this->descripcion = descripcion;
    this->informacion = informacion;
};

DTInfoEjercicio::~DTInfoEjercicio(){};

void DTInfoEjercicio::setDescripcion(string descipcion){
    this->descripcion = descipcion;
};

void DTInfoEjercicio::setInformacion(string informacion){
    this->informacion = informacion;
};

string DTInfoEjercicio::getDescripcion(){
    return descripcion;
};

string DTInfoEjercicio::getInformacion(){
    return informacion;
};
