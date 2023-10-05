#include <string>
#include <iostream>
#include "../include/DTPromedioCurso.h"

DTPromedioCurso :: ~DTPromedioCurso(){}

DTPromedioCurso :: DTPromedioCurso(string infoCurso, float promedio) {
    this -> infoCurso = infoCurso;
    this -> promedio = promedio;
}

void DTPromedioCurso :: setInfoCurso(string infoCurso){
    this -> infoCurso = infoCurso;
}

void DTPromedioCurso :: setPromedio(float promedio) {
    this -> promedio = promedio;
}

string DTPromedioCurso :: getInfoCurso() {
    return infoCurso;
}

float DTPromedioCurso :: getPromedio() {
    return promedio;
}

void DTPromedioCurso ::mostrarDT(){
    // cout << "INFO CURSO: " << this->infoCurso << endl;
    // cout << "PROMEDIO: " << this->promedio << endl;
}
