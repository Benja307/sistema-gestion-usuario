#include "../include/controladorUsuario.h"
#include <iostream>
using namespace std;

ControladorUsuario :: ControladorUsuario(){};

ControladorUsuario :: ~ControladorUsuario(){};

void ControladorUsuario::ingresarDatosUsuario(string nickname, string contrasenia, string nombre, string descripcion){
    this->memNickname = nickname;
    this->memContrasenia = contrasenia;
    this->memNombre = nombre;
    this->memDescripcion = descripcion;
}

void ControladorUsuario::ingresarDatosEstudiante(string nombrePais, int dia, int mes, int anio){
    this->memPais = nombrePais;
    this->memFechaNacimiento = new DTFecha(dia, mes, anio);
};

bool ControladorUsuario::confirmarAltaEstudiante(){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    bool existe = mu->existeUsuario(this->memNickname);
    if(!existe){
        Estudiante* e = new Estudiante(this->memNickname,this->memContrasenia, this->memNombre, this->memDescripcion, this->memPais, this->memFechaNacimiento);
        mu->agregarUsuario(e);
        mu->agregarEstudiante(e);
        return true;
    } else 
        //liberar memoria?
        return false;
};
        
void ControladorUsuario::ingresarInstituto(string nombreInstituto){
    this->memInstituto = nombreInstituto;
};

set<string> ControladorUsuario::listarIdiomasDisponibles(){
    ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
    set<string> idiomasDisponibles = mi->listarIdiomas();
    return idiomasDisponibles; 
}; 

void ControladorUsuario::ingresarEspecializacion(string nombreIdioma){
    ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
    Idioma* i = mi->obtenerIdioma(nombreIdioma);
    idiomasRecordados.insert(i);
};
        
bool ControladorUsuario::confirmarAltaProfesor(){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    bool existe = mu->existeUsuario(this->memNickname);
    if(!existe){
        Profesor* p = new Profesor(this->memNickname,this->memContrasenia, this->memNombre, this->memDescripcion, this->memInstituto);
        set<Idioma*>::iterator it;
        for(it = idiomasRecordados.begin(); it != idiomasRecordados.end(); ++it){
            p->agregarEspecializacion(*it);
        }
        set<Idioma*>::iterator it2;
        idiomasRecordados.clear();
        mu->agregarUsuario(p);
        mu->agregarProfesor(p);
        return true;
    } else{
        idiomasRecordados.clear();
        return false;
    }        
}

void ControladorUsuario::consultarUsuario(string nickname){
    Usuario* u = this->obtenerUsuarioSistema(nickname);
    Estudiante* e = dynamic_cast<Estudiante*>(u);
    if (e != NULL){
        DTInfoEstudiante* DTe = e->getDataEstudiante();
        DTe->mostrarInfoEstudiante();
    } else {
        Profesor* p = dynamic_cast<Profesor*>(u);
        DTInfoProfesor* DTp = p->getDataProfesor();
        DTp->mostrarInfoProfesor();
    }
}

void ControladorUsuario::consultarInfoEjercicio(int idEjercicio){
    Ejercicio* e = (this->memLeccion)->obtenerProblema(idEjercicio);
    this->memEjercicio = e;
    CompletarPalabras *c = dynamic_cast<CompletarPalabras *>(e);
    if (c != NULL){
        DTCompletarPalabras *DTc = c->getDTCompletarPalabras();
        DTc->mostrarDTCompletarPalabras(); 
    }
    else
    {
        Traduccion *t = dynamic_cast<Traduccion *>(e);
        DTTraduccion *DTt = t->getDTTraduccion();
        DTt->mostrarDTTraduccion();
    }
};

set<string> ControladorUsuario::suscribirNotificaciones(string nickname){
    ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
    Usuario* u = obtenerUsuarioSistema(nickname);
    set<string> idiomasNoSuscrito = mi->listarIdiomasNoSuscripto(u);
    return idiomasNoSuscrito;
}

void ControladorUsuario::confirmarSuscripcion(string nickname, string nombreIdioma){
    Usuario* u = obtenerUsuarioSistema(nickname);
    Idioma* i = obtenerIdiomaSistema(nombreIdioma);
    i->agregarObs(u);
}

set<DTNotificacion*> ControladorUsuario::consultarNotificaciones(string nickname){
    Usuario* u = obtenerUsuarioSistema(nickname);
    return u->getNotificaciones();
}

void ControladorUsuario::eliminarNotificaciones(string nickname){
    Usuario* u = obtenerUsuarioSistema(nickname);
    u->vaciarNotificaciones();
};

set<string> ControladorUsuario::cancelarSuscripciones(string nickname){
    ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
    Usuario* u = obtenerUsuarioSistema(nickname);
    set<string> idiomasSuscrito = mi->listarIdiomasSuscripto(u);
    return idiomasSuscrito;
}

void ControladorUsuario::eliminarSuscripcion(string nickname, string nombreIdioma){
    Usuario* u = obtenerUsuarioSistema(nickname);
    Idioma* i = obtenerIdiomaSistema(nombreIdioma);
    i->removerObs(u);
}

set<string> ControladorUsuario::listarUsuariosSistema(){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    set<string> nicknameUsuarios = mu->listarUsuarios();
    return nicknameUsuarios;
};

set<string> ControladorUsuario::listarEstudiantesSistema(){
    ManejadorUsuario *mu = ManejadorUsuario::getInstancia();
    set<string> nicknameEstudiantes = mu->listarEstudiantes();
    return nicknameEstudiantes;
};

Estudiante* ControladorUsuario::obtenerEstudianteSistema(string nicknameEstudiante){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    return mu->obtenerEstudiante(nicknameEstudiante);
};

Usuario *ControladorUsuario::obtenerUsuarioSistema(string nickname)
{
    ManejadorUsuario *mu = ManejadorUsuario::getInstancia();
    return mu->obtenerUsuario(nickname);
};


Idioma* ControladorUsuario::obtenerIdiomaSistema(string nombre){
    ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
    return mi->obtenerIdioma(nombre);
};

set<string> ControladorUsuario::listarCursosNoAprobados(string nickname){
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    this->memNickname = nickname; 
    Estudiante* estudiante = mU->obtenerEstudiante(nickname);
    this->memEstudiante = estudiante;
    set<string> cursosNA = estudiante->listarCursosNoAprobados();
    return cursosNA;
};

set<int> ControladorUsuario::listarEjerciciosNoAprobados(string nombreCurso){
    ManejadorCurso *mC = ManejadorCurso::getInstancia();
    Curso* curso = mC->obtenerCurso(nombreCurso);
    this->memCurso = nombreCurso;
    Leccion* leccion = curso->obtenerLeccionActual(this->memNickname);
    this->memLeccion = leccion;
    set<int> ejerciciosNA = leccion->obtenerIdEjerciciosNoAprobados(this->memNickname);
    return ejerciciosNA;
}; 

bool ControladorUsuario::compararSoluciones(string sol){
    bool iguales = this->memEjercicio->compararSoluciones(sol);
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Estudiante *es = mu->obtenerEstudiante(memNickname);    
    ManejadorCurso *mC = ManejadorCurso::getInstancia();
    Curso* curso = mC->obtenerCurso(memCurso);
    if (iguales) {
        map<string,Inscripcion*> inscripciones = es->getInscripciones(); 
        map<string,Inscripcion*>::iterator iti;
        for(iti = inscripciones.begin(); iti != inscripciones.end(); iti++){
            if (iti->first == this->memCurso) {
                iti->second->incrementarCantEjAprobados();
                if (iti->second->getCantEjAprobados() == curso->getCantEjercicios()){
                    iti->second->setAprobado(true);
                }
            }
        }
        memEjercicio->aprobarEjercicio(memNickname, es);
        // memEjercicio->agregarEstudianteAprobado(es);
        // memEjercicio->agregarNicknameEstudianteAprobado(memNickname);
    }
    return iguales;
};

void ControladorUsuario::cargarEjerciciosAprobados(string nicknameEstudiante, string nombreCurso, int idEjercicio){
// ej 1 l1
    // cout <<"entra a cargar\n";
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Estudiante *es = mu->obtenerEstudiante(nicknameEstudiante);    
    ManejadorCurso *mC = ManejadorCurso::getInstancia();
    Curso* curso = mC->obtenerCurso(nombreCurso);
    map<string,Inscripcion*> inscripciones = es->getInscripciones(); 
    map<string,Inscripcion*>::iterator iti;
    for(iti = inscripciones.begin(); iti != inscripciones.end(); iti++){
        // cout <<"entra a inscripciones\n";
        if (iti->first == nombreCurso) {
            iti->second->incrementarCantEjAprobados();
            if (iti->second->getCantEjAprobados() == curso->getCantEjercicios()){
                iti->second->setAprobado(true);
                // cout <<"entra a setear inscripcion\n";
            }
        }
    }
    Leccion* leccion = curso->obtenerLeccionActual(nicknameEstudiante);
    Ejercicio* ejercicio = leccion->obtenerEjercicio(idEjercicio);
    ejercicio->aprobarEjercicio(nicknameEstudiante, es);
};


