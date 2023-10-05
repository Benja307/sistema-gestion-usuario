#include <string>
#include <iostream>
#include "../include/DTAvanceCurso.h"

DTAvanceCurso::~DTAvanceCurso(){}

DTAvanceCurso::DTAvanceCurso(string nombreCurso, float avance){
    this->nombreCurso = nombreCurso;
    this->avance = avance;
}

void DTAvanceCurso :: setNombreCurso(string nombreCurso) {
    this->nombreCurso = nombreCurso;
}


void DTAvanceCurso :: setAvance(float avance) {
    this->avance = avance;
}


string DTAvanceCurso :: getNombreCurso(){
    return this->nombreCurso;
}

float DTAvanceCurso :: getAvance(){
    return this->avance;
}


