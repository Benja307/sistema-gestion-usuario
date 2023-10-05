#include "../include/DTNotificacion.h"
#include <iostream>

DTNotificacion :: DTNotificacion(string nombreCurso, string nombreIdioma){
    this -> nombreCurso = nombreCurso;
    this -> nombreIdioma = nombreIdioma;
}

DTNotificacion :: ~DTNotificacion(){}

void DTNotificacion::setNombreCurso(string nombreCurso){
    this -> nombreCurso = nombreCurso;
}

void DTNotificacion::setNombreIdioma(string nombreIdioma){
    this -> nombreIdioma = nombreIdioma;
}

string DTNotificacion::getNombreCurso(){
    return nombreCurso;
}

string DTNotificacion::getNombreIdioma(){
    return nombreIdioma;
}

void DTNotificacion::mostrarNotificacion(){
    cout << "-Se creó un nuevo curso " << this->nombreCurso << " del idioma " << this->nombreIdioma << endl;
}