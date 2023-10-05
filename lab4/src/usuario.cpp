#include "../include/usuario.h"

Usuario::Usuario(string nickname, string contrasenia, string nombre, string descripcion){
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
}

Usuario::~Usuario(){}

void Usuario::setNickname(string nickname){
    this->nickname = nickname;
}

void Usuario::setContrasenia(string contrasenia){
    this->contrasenia = contrasenia;
}

void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}

void Usuario::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}


string Usuario::getNickname(){
    return nickname;
}

string Usuario::getNombre(){
    return nombre;
}

string Usuario::getContrasenia(){
    return contrasenia;
}

string Usuario::getDescripcion(){
    return descripcion;
}

set<DTNotificacion*> Usuario::getNotificaciones(){
    return this->notificaciones;
}

DTInfoUsuario* Usuario::getDataUsuario(){
    DTInfoUsuario* infoU = new DTInfoUsuario(this->nombre, this->descripcion);
    return infoU;
}


void Usuario::notificar(string nombreCurso, string nombreIdioma){
    DTNotificacion* notif = new DTNotificacion(nombreCurso, nombreIdioma);
    this->notificaciones.insert(notif);
}

void Usuario::vaciarNotificaciones(){
    this->notificaciones.clear();
}


