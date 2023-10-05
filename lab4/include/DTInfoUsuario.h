#ifndef DTINFOUSUARIO
#define DTINFOUSUARIO

#include <string>
#include <iostream>
using namespace std;

class DTInfoUsuario {
    private: 
        string nombre;
        string descripcion;
    public:
        // setters
        void setNombre(string descripcion);
        void setDescripcion(string descripcion);

        // getters
        string getNombre();
        string getDescripcion();

        // constructor y destructor 
        DTInfoUsuario(string nombre, string descripcion);
        ~DTInfoUsuario();      
};

#endif