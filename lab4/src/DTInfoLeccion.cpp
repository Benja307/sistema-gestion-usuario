#include "../include/DTInfoLeccion.h"

DTInfoLeccion::DTInfoLeccion(string tema, string objetivo){
    this->tema = tema;
    this->objetivo = objetivo;
};

DTInfoLeccion::~DTInfoLeccion(){};      

/* setters */
void DTInfoLeccion::setTema(string tema){
    this->tema = tema;
};

void DTInfoLeccion::setObjetivo(string objetivo){
    this->objetivo = objetivo;
};

void setEjercicios(set<DTInfoEjercicio>){};

/* getters */ 
string DTInfoLeccion::getTema(){
    return tema;
};

string DTInfoLeccion::getObjetivo(){
    return objetivo;
};
