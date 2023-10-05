#ifndef DTINFOCURSO
#define DTINFOCURSO

#include <string>
#include <set>
#include <iostream>
#include "DificultadCurso.h"
#include "DTInfoLeccion.h"
#include "DTInfoInscripcion.h"
#include "leccion.h"
#include "completarPalabras.h"
#include "traduccion.h"


using namespace std;

class Inscripcion;

class DTInfoCurso {
        string nombreCurso;
        string descripcion;
        DificultadCurso dificultad;
        bool habilitado;
        string idioma;
        int cantEj;
        string nombreProfesor;
        set<Leccion*> lecciones;
        set<Inscripcion*> inscripciones;
    public:
        /* setters */
        void setNombreCurso(string nombreCurso);
        void setDescripcion(string descripcion);
        void setDificultad(DificultadCurso dificultad);
        void setHabilitado(bool habilitado);
        void setIdioma(string idioma);
        // void setCantEjercicios(int cantEj);
        void setNombreProfesor(string nombreProfesor);
        // set lecciones, inscripciones?
        void setLecciones(set<Leccion*> lecciones);
        void setInscripciones(set<Inscripcion*> inscripciones);

        /* getters */
        string getNombreCurso();
        string getDescripcion();
        DificultadCurso getDificultad();
        bool getHabilitado();
        int getCantEjercicios();
        string getIdioma();
        string getProfesor();
        set<Leccion*> getLecciones(); //
        set<Inscripcion*> getInscripciones(); //
        

        void mostrarInfoCurso(); //


        /* constructor y destructor */
        DTInfoCurso(string nombreCurso, string descripcion, DificultadCurso dificultad, int cantEj, bool habilitado, string idioma, string nombreProfesor, set<Leccion*> lecciones, set<Inscripcion*> inscripciones);
        ~DTInfoCurso();

};

#include "inscripcion.h"

#endif