#ifndef DTINFOPROFESOR
#define DTINFOPROFESOR

#include <string>
#include <iostream>
#include <set>
#include "DTInfoUsuario.h"
// using namespace std;

class DTInfoProfesor : public DTInfoUsuario {
    private: 
        string instituto;
        set<string> idiomasEspecializado;
    public:
        // setters ? verificar si deben estar
        void setInstituto(string instituto);
        // void setIdiomasEspecializado(set<string> idiomasEspecializado);

        // getters ? verificar si deben estar
        string getInstituto();

        // constructor y destructor 
        DTInfoProfesor(string nombre, string descripcion, string instituto, set<string> idiomasEspecializado);
        ~DTInfoProfesor();      

        void mostrarInfoProfesor();
};

#endif