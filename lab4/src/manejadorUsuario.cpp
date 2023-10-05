#include "../include/manejadorUsuario.h"
#include <iostream>
using namespace std;

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorUsuario();
    return instancia;
}
        
bool ManejadorUsuario::existeUsuario(string nickname){
    return (Usuarios.find(nickname) != Usuarios.end());
}

void ManejadorUsuario::agregarUsuario(Usuario* u){
    Usuarios.insert({u->getNickname(), u});
}

void ManejadorUsuario::agregarEstudiante(Estudiante* e){
    Estudiantes.insert({e->getNickname(), e});
}

void ManejadorUsuario::agregarProfesor(Profesor* p){
    Profesores.insert({p->getNickname(), p});
}
        
Usuario* ManejadorUsuario::obtenerUsuario(string nickname){
    auto it = Usuarios.find(nickname);
    return (it->second);
}

Estudiante* ManejadorUsuario::obtenerEstudiante(string nicknameEstudiante){
    auto it = Estudiantes.find(nicknameEstudiante);
    return (it->second);
}

Profesor* ManejadorUsuario::obtenerProfesor(string nickname){
    auto it = Profesores.find(nickname);
    return (it->second);
}
        
set<string> ManejadorUsuario::listarProfesores(){
    set<string> nicknameProfesores;
    map<string, Profesor*>::iterator it;
    for(it=Profesores.begin(); it!=Profesores.end(); ++it){
        nicknameProfesores.insert(it->first);
    }
    return nicknameProfesores;
}  

set<string> ManejadorUsuario::listarEstudiantes(){
    set<string> nicknameEstudiantes;
    map<string, Estudiante*>::iterator it;
    for(it=Estudiantes.begin(); it!=Estudiantes.end(); ++it){
        nicknameEstudiantes.insert(it->first);
    }
    return nicknameEstudiantes;
}

set<string> ManejadorUsuario::listarUsuarios(){
    set<string> nicknameUsuarios;
    for(auto it=Usuarios.begin(); it!=Usuarios.end(); ++it){
        nicknameUsuarios.insert(it->first);
    }
    return nicknameUsuarios;
}

      
