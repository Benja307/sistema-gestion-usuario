#include "../include/inscripcion.h"
using namespace std;

bool Inscripcion::getAprobado(){
    return this->aprobado;
}

string Inscripcion::getNombreCurso(){
    return this->nombreCurso;
};

DTAvanceCurso* Inscripcion::getDataAvance(){
    string nombreCurso = this->nombreCurso;
    int cantEj = this->curso->getCantEjercicios();
    float gradoAvance = (this->cantEjAprobados)/cantEj;
    DTAvanceCurso* data = new DTAvanceCurso(nombreCurso, gradoAvance);
    return data;
};

float Inscripcion::calcularAvance(int cantEj){
    return (this->cantEjAprobados)/cantEj;
}

Inscripcion::Inscripcion(string nombreCurso, DTFecha *fechaInscripcion, bool aprobado, int cantEjAprobados, Estudiante *estudiante, Curso *curso){
    this->nombreCurso = nombreCurso;
    this->fechaInscripcion = fechaInscripcion;
    this->aprobado = aprobado;
    this->cantEjAprobados = cantEjAprobados;
    this->estudiante = estudiante;
    this->curso = curso;
}


void Inscripcion::setEstudiante(Estudiante* estudiante){
    this->estudiante = estudiante;
}

void Inscripcion::setFechaInscripcion(DTFecha *fecha) {
    this->fechaInscripcion = fechaInscripcion;
}

void Inscripcion::setAprobado(bool aprobado){
    this->aprobado = aprobado;
}

DTFecha* Inscripcion::getFechaInscripcion(){
    return fechaInscripcion;
}

int Inscripcion::getCantEjAprobados(){
    return cantEjAprobados;
}

Estudiante* Inscripcion::getEstudiante(){
    return estudiante;
}

void Inscripcion::incrementarCantEjAprobados(){
    this->cantEjAprobados++;
}

Inscripcion::~Inscripcion(){}