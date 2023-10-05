#include <string>
#include <iostream>
#include "../include/completarPalabras.h"
using namespace std;


CompletarPalabras :: CompletarPalabras(int idEjercicio, string descripcion, string fraseACompletar, string solucion) : Ejercicio(idEjercicio, descripcion){
    this->fraseACompletar = fraseACompletar;
    this->solucion = solucion;
}

void CompletarPalabras::setFraseACompletar(string fraseACompletar){
    this->fraseACompletar = fraseACompletar;
}

void CompletarPalabras::setSolucion(string solucion){
    this->solucion = solucion;
}

string CompletarPalabras::getFraseACompletar(){
    return fraseACompletar;
};

string CompletarPalabras::getSolucion(){
    return solucion;
}

DTCompletarPalabras* CompletarPalabras::getDTCompletarPalabras(){
    DTCompletarPalabras* DTc = new DTCompletarPalabras(this->getFraseACompletar(), this->getDescripcion());
    return DTc;
};

bool CompletarPalabras::compararSoluciones(string sol){
    string solucion = this->getSolucion();
    return (sol == solucion);
};


CompletarPalabras::~CompletarPalabras(){}