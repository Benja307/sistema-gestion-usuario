#include "../include/traduccion.h"
using namespace std;

Traduccion::Traduccion(int idEjercicio, string descripcion, string fraseATraducir, string solucion) : Ejercicio(idEjercicio, descripcion){
    this->fraseATraducir = fraseATraducir;
    this->solucion = solucion;
}

string Traduccion::getFraseATraducir(){
    return fraseATraducir;
};

void Traduccion::setFraseATraducir(string fraseATraducir) {
    this->fraseATraducir = fraseATraducir; 
};

string Traduccion::getSolucion(){
    return solucion;
};

bool Traduccion::compararSoluciones(string sol){
    string solucion = this->getSolucion();
    return (sol == solucion);
};

Traduccion::~Traduccion(){}

DTTraduccion *Traduccion::getDTTraduccion(){
    DTTraduccion *DTt = new DTTraduccion(this->getFraseATraducir(), this->getDescripcion());
    return DTt;
};
