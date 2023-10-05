#include "../include/DTInfoUsuario.h"


// constructor
DTInfoUsuario::DTInfoUsuario(string nombre, string descripcion){
    this->nombre = nombre;
    this->descripcion = descripcion;
};

// setters
void DTInfoUsuario::setNombre(string nombre){
    this->nombre = nombre;
};

void DTInfoUsuario::setDescripcion(string descripcion){
    this->descripcion = descripcion;
};

// getters
string DTInfoUsuario::getNombre(){
    return nombre;
};
string DTInfoUsuario::getDescripcion(){
    return descripcion;
};

// destructor 
DTInfoUsuario::~DTInfoUsuario(){};     