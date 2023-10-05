#include <string>
#include <iostream>
// #include "../include/DTEjercicio.h"
#include "../include/DTCompletarPalabras.h"
using namespace std;

DTCompletarPalabras::~DTCompletarPalabras(){};

DTCompletarPalabras::DTCompletarPalabras(string fraseACompletar, string descripcion) : DTEjercicio(descripcion){
    this->fraseACompletar = fraseACompletar;
};

string DTCompletarPalabras::getFraseACompletar(){
    return fraseACompletar;
};

void DTCompletarPalabras::setFraseACompletar(string fraseACompletar){
    this->fraseACompletar = fraseACompletar;
};


void DTCompletarPalabras::mostrarDTCompletarPalabras(){
    cout << "Descripcion: " << this->getDescripcion() << endl;
    cout << "Frase a completar: " << this->getFraseACompletar() << endl;
}
