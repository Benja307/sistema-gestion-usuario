#include "../include/estudiante.h"
using namespace std;


Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string paisResidencia, DTFecha* fechaNacimiento) : Usuario(nickname, contrasenia, nombre, descripcion){
    this->paisResidencia = paisResidencia;
    this->fechaNacimiento = fechaNacimiento;
};

void Estudiante::setPaisResidencia(string paisResidencia){
    this->paisResidencia = paisResidencia;
};
        
void Estudiante::setFechaNacimiento(DTFecha* fechaNacimiento){
    this->fechaNacimiento = fechaNacimiento;
};

void Estudiante::eliminarInscripcion(Inscripcion i){};

map<string, Inscripcion*> Estudiante::getInscripciones()
{
    return inscripcionesEstudiante;
};



set<DTAvanceCurso*> Estudiante::obtenerEstadisticasEstudiante(){
    set<DTAvanceCurso*> estadisticasEstudiante;
    for(auto it = inscripcionesEstudiante.begin(); it != inscripcionesEstudiante.end(); ++it){
        Inscripcion* i = it->second;
        DTAvanceCurso* data = i->getDataAvance();
        estadisticasEstudiante.insert(data);
    }
    return estadisticasEstudiante;
};

DTInfoEstudiante* Estudiante::getDataEstudiante(){
    DTInfoEstudiante* infoE = new DTInfoEstudiante(this->getNombre(), this->getDescripcion(), this->paisResidencia, this->fechaNacimiento);
    return infoE;
};

bool Estudiante::estaInscripto(Curso* curso){
    string nombreCurso = curso->getNombreCurso();
    map<string,Inscripcion*>::iterator it = inscripcionesEstudiante.find(nombreCurso);
    return it != inscripcionesEstudiante.end();
}

bool Estudiante::estaAprobado(string nombreCurso){
    map<string,Inscripcion*>::iterator it = inscripcionesEstudiante.find(nombreCurso);
    if(it != inscripcionesEstudiante.end()){
        return it->second->getAprobado();
    }
    else{
        return false;
    } 
}

void Estudiante::agregarInscripcion(string nombreCurso, Inscripcion* inscripcion){
    inscripcionesEstudiante.insert(make_pair(nombreCurso,inscripcion));
}

set<string> Estudiante::listarCursosNoAprobados(){
    set<string> cursosNoAprobados;
    map<string,Inscripcion*>::iterator it;  
    for(it = inscripcionesEstudiante.begin(); it != inscripcionesEstudiante.end(); it++){
        Inscripcion* i = it->second;
        if(!i->getAprobado()){
            cursosNoAprobados.insert(it->first);
        }
    }
    return cursosNoAprobados;
};

Estudiante::~Estudiante(){};
