#include "../include/leccion.h"
#include <iostream>
using namespace std;

Leccion::Leccion(int id, string tema, string objetivo){
    this->id = id;
    this->tema = tema;
    this->objetivo = objetivo;
}

Leccion::~Leccion(){}

// setters
void Leccion::setId(int id){
    this->id = id;
};

void Leccion::setTema(string tema){
    this->tema = tema;
};

void Leccion::setObjetivo(string objetivo){
    this->objetivo = objetivo;
};

void Leccion::setCantEjercicios(int cantEj){
    this->cantEjercicios = cantEj;
};

// getters
int Leccion::getId(){
    return id;
};

string Leccion::getTema(){
    return tema;
};

string Leccion::getObjetivo(){
    return objetivo;
};

int Leccion::getCantEjercicios(){
    return cantEjercicios;
};

set<Ejercicio *> Leccion::getEjercicios(){
    return ejercicios;
};

void Leccion::ingresarALeccionTraduccion(Traduccion* t){
    this->ejercicios.insert(t);
};

void Leccion::ingresarALeccionCompletarPalabra(CompletarPalabras* cp){
    this->ejercicios.insert(cp);
};

void Leccion::incrementarCantEjercicios(){
    this->cantEjercicios++;
};

void Leccion::eliminarEjercicios(){
    set<Ejercicio *> ejercicios = this->getEjercicios();
    set<Ejercicio *>::iterator ite;
    for (ite = ejercicios.begin(); ite != ejercicios.end(); ite++){
        Ejercicio *e = *ite;
        CompletarPalabras *cp = dynamic_cast<CompletarPalabras *>(e);
        if (cp != NULL) {
            CompletarPalabras *aux = dynamic_cast<CompletarPalabras *>(e);
            this->ejercicios.erase(*ite);
            delete aux;
            aux = NULL;
        }
        else{
            Traduccion *aux = dynamic_cast<Traduccion *>(e);
            this->ejercicios.erase(*ite);
            delete aux;
            aux = NULL;
        }
    }
    this->ejercicios.clear();
};


set<int> Leccion::obtenerIdEjerciciosNoAprobados(string nicknameEstudiante){
    set<Ejercicio*> ejercicios = this->getEjercicios();
    set<Ejercicio*>::iterator ite;
    set<int> idEjerciciosNA;
    for (ite = ejercicios.begin(); ite != ejercicios.end(); ite++){
        if (!(*ite)->ejercicioAprobado(nicknameEstudiante)) {
            idEjerciciosNA.insert((*ite)->getIdEjercicio());
        }
    }
    return idEjerciciosNA;
};

bool Leccion::leccionAprobada(string nickname){
    set<int> idEjerciciosNA = this->obtenerIdEjerciciosNoAprobados(nickname);
    if (idEjerciciosNA.size() == 0) {
        return true;
    } else {
        return false;
    }
};

Ejercicio* Leccion::obtenerProblema(int id){
    set<Ejercicio*> ejercicios = this->getEjercicios();
    set<Ejercicio*>::iterator ite;
    Ejercicio* e = NULL;
    int idEjercicio = -1;
    for (ite = ejercicios.begin(); ite != ejercicios.end(); ite++){
        idEjercicio = (*ite)->getIdEjercicio();
        if (idEjercicio == id) {
            e = *ite;
        }
    }
    return e;
};

Ejercicio* Leccion::obtenerEjercicio(int idEjercicio){
    set<Ejercicio*> ejercicios = this->getEjercicios();
    set<Ejercicio*>::iterator ite;
    Ejercicio* e = NULL;
    for (ite = ejercicios.begin(); ite != ejercicios.end(); ite++){
        if ((*ite)->getIdEjercicio() == idEjercicio) {
            e = *ite;
        }
    }
    return e;
};
