#include "../include/idioma.h"
#include "../include/usuario.h"
#include "../include/DTNotificacion.h"
#include <string>
#include <iostream>

// constructores
//Idioma::Idioma(){}  // este constructor se puso porque en el constructor de controlador curso lo invoca sin parámetro, revisar

Idioma::Idioma(string nombreIdioma){
    this->nombreIdioma = nombreIdioma;
}

// destructor 
Idioma::~Idioma(){}

void Idioma::setNombre(string nombreIdioma){
    this->nombreIdioma = nombreIdioma;
}

string Idioma::getNombre(){
    return nombreIdioma;
}

void Idioma::notificarNuevoCurso(string nombreCurso){
    for(auto it = this->suscriptos.begin(); it != this->suscriptos.end(); ++it){
        (*it)->notificar(nombreCurso, this->nombreIdioma);
    }
}


bool Idioma::estaSuscripto(IObserver* o){
    return (this->suscriptos.find(o) != this->suscriptos.end());
}

void Idioma::agregarObs(IObserver* o){
    this->suscriptos.insert(o);
}

void Idioma::removerObs(IObserver* o){
    this->suscriptos.erase(o);
}
