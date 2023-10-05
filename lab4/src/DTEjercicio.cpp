#include "../include/DTEjercicio.h"

DTEjercicio::DTEjercicio(string descripcion){
    this->descripcion = descripcion;
}

DTEjercicio::~DTEjercicio(){}

string DTEjercicio::getDescripcion(){
    return this->descripcion;
}