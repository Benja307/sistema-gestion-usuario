#ifndef DTNOTIFICACION
#define DTNOTIFICACION

#include <iostream>
#include <string>
using namespace std;

class DTNotificacion {
    private:
        string nombreCurso;
        string nombreIdioma;
    public:
        //setters
        void setNombreCurso(string nombreCurso);
        void setNombreIdioma(string nombreIdioma);

        //getters
        string getNombreCurso();
        string getNombreIdioma();

        //constructor y destructor 
        DTNotificacion(string nombreCurso, string nombreIdioma);
        virtual ~DTNotificacion();

        void mostrarNotificacion();
};

#endif