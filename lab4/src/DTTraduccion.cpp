// #include "../include/DTEjercicio.h"
// #include <string>
// #include <iostream>
#include "../include/DTTraduccion.h"
#include <iostream>
using namespace std;

// using namespace std;

DTTraduccion::~DTTraduccion(){};

DTTraduccion::DTTraduccion(string fraseATraducir, string descripcion) : DTEjercicio(descripcion)
{
    this->fraseATraducir = fraseATraducir;
};

string DTTraduccion::getFraseATraducir(){
    return fraseATraducir;
};

void DTTraduccion::setFraseATraducir(string fraseATraducir){
    this->fraseATraducir = fraseATraducir;
};

void DTTraduccion::mostrarDTTraduccion(){
    cout << "Descripcion: " << this->getDescripcion() << endl;
    cout << "Frase a traducir: " << this->getFraseATraducir() << endl;
};
