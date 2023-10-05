#ifndef USUARIO
#define USUARIO

#include "DTInfoUsuario.h"
#include "DTNotificacion.h"
#include "IObserver.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;

class Usuario : public IObserver{
    private:
        string nickname;
        string contrasenia;
        string nombre;
        string descripcion;
        set<DTNotificacion*> notificaciones;        
               
    public:
        // setters
        void setNickname(string nickname);
        void setContrasenia(string contrasenia);
        void setNombre(string nombre);
        void setDescripcion(string descripcion);

        // getters
        string getNickname();
        string getContrasenia();
        string getNombre();
        string getDescripcion();
        set<DTNotificacion*> getNotificaciones();

        // otras operaciones
        DTInfoUsuario* getDataUsuario();
        virtual void notificar(string nombreCurso, string nombreIdioma);
        void vaciarNotificaciones();
        
        // constructor y destructor 
        Usuario(string nickname, string contrasenia, string nombre, string descripcion);
        virtual ~Usuario();
};

#endif