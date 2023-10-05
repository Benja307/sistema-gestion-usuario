#ifndef DTINFOESTUDIANTE
#define DTINFOESTUDIANTE

#include <string>
#include <iostream>
#include "DTFecha.h"
#include "DTInfoUsuario.h"
using namespace std;

class DTInfoEstudiante : public DTInfoUsuario {
    private: 
        string paisResidencia;
        DTFecha* fechaNacimiento;
    public:
        // setters que va, que no va revisar
        void setPaisResidencia(string paisResidencia);
        void setFechaNacimiento(DTFecha* fechaNacimiento);

        // getters ? va, no va?
        string getPaisResidencia();
        DTFecha* getFechaNacimiento();

        // constructor y destructor 
        DTInfoEstudiante(string nombre, string descripcion, string paisResidencia, DTFecha* fechaNacimiento);
        ~DTInfoEstudiante();

        void mostrarInfoEstudiante();
};

#endif