#include "../include/manejadorCurso.h"


ManejadorCurso::ManejadorCurso(){}

ManejadorCurso* ManejadorCurso::Instancia = NULL;


ManejadorCurso *ManejadorCurso::getInstancia() {
    if (Instancia == NULL)
        Instancia = new ManejadorCurso();
    return Instancia;
};

bool ManejadorCurso::existeCurso(string nombreCurso) {
    return (Cursos.find(nombreCurso) != Cursos.end());
}  

        
Curso* ManejadorCurso::obtenerCurso(string nombreCurso){
    auto itc = Cursos.find(nombreCurso);
    return (itc->second);
};        

void ManejadorCurso::agregarCurso(Curso* c){
    Cursos.insert({c->getNombreCurso(), c});
};          

set<string> ManejadorCurso::listarCursos(){
    set<string> cursos;
    map<string, Curso*>::iterator it;
    for(it=Cursos.begin(); it!=Cursos.end(); ++it){
        cursos.insert(it->first);
    }
    return cursos;
};
        
set<string> ManejadorCurso::listarCursosHabilitados(){
    set<string> cursosHabilitados;
    map<string, Curso*>::iterator it;
    for(it=Cursos.begin(); it!=Cursos.end(); ++it){
        Curso* c = it->second;
        if(c->getHabilitado()){
            cursosHabilitados.insert(c->getNombreCurso());
        }
    }
    return cursosHabilitados;
};  

set<string> ManejadorCurso::listarCursosNoHabilitados(){
    set<string> cursosNoHabilitados;
    map<string, Curso*>::iterator it;
    for(it=Cursos.begin(); it!=Cursos.end(); ++it){
        Curso* c = it->second;
        if(!(c->getHabilitado())){
            cursosNoHabilitados.insert(c->getNombreCurso());
        }
    }
    return cursosNoHabilitados;
}; 

set<int> ManejadorCurso::listarLecciones(Curso* curso){
    set<int> idLecciones;
    set<Leccion*> lecciones = curso->obtenerLecciones();
    set<Leccion*>::iterator it;
    for(it=lecciones.begin(); it!=lecciones.end(); ++it){
        Leccion* l = *it;
        idLecciones.insert(l->getId());
    }
    return idLecciones;
}

map<string,Curso*> ManejadorCurso::obtenerCursosNoInscripto(Estudiante* estudiante){
    map<string,Curso*> cursosNoInscripto;
    for(auto it = Cursos.begin(); it != Cursos.end(); ++it){
        if(it->second->getHabilitado()){
            bool inscripto = estudiante->estaInscripto(it->second);
            if(!inscripto){
                cursosNoInscripto.insert(*it);
            }
        }
    }
    return cursosNoInscripto;
}

void ManejadorCurso::eliminarCurso(Curso *curso){
    Curso* c = curso;
    Cursos.erase(curso->getNombreCurso());
    delete c;
    c = NULL;
};