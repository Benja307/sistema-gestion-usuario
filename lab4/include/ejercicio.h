#ifndef EJERCICIO
#define EJERCICIO

#include <string>
#include <set>
#include <iostream>
#include "DTEjercicio.h"
using namespace std;

class Estudiante; 

class Ejercicio{
    private:
        int idEjercicio;
        string descripcion;
        set<Estudiante*> estudiantesAprobados;
        set<string> nicknamesEstudiantesAprobados;
    public:

        // setters
        void setIdEjercicio(int idEjercicio);
        void setDescripcion(string descripcion);

        // getters
        int getIdEjercicio();
        string getDescripcion();
        set<Estudiante *> getEstudiantesAprobados();
        set<string> getNicknamesEstudiantesAprobados();

        // constructor y destructor
        Ejercicio(int idEjercicio, string descripcion);
        ~Ejercicio();

        // otras operaciones
        bool ejercicioAprobado(string nicknameEstudiante);
        DTEjercicio* obtenerDTEjercicio();
        virtual bool compararSoluciones(string sol);
        void aprobarEjercicio(string nicknameEstudiante, Estudiante* estudiante);
        void agregarEstudianteAprobado();
};

#include "completarPalabras.h"
#include "traduccion.h"
#endif