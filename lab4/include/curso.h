#ifndef CURSO
#define CURSO


#include "inscripcion.h"
#include "DificultadCurso.h"
#include "estudiante.h"
#include "leccion.h"
#include "DTPromedioCurso.h"
#include "idioma.h"
#include "DTInfoCurso.h"
#include <string>
using namespace std;

class Profesor;

class Curso {
    private:
        string nombreCurso;
        string descripcion;
        DificultadCurso dificultad;
        bool habilitado;
        int cantEj;
        set<Inscripcion*> inscripcionesCurso; 
        set<Curso*> Previas;
        set<Leccion*> Lecciones;
        Profesor* profesor;
        Idioma* idioma;
    public:
        // setters
        void setNombreCurso(string nombreCurso);
        void setDescripcion(string descripcion);
        void setDificultad(DificultadCurso dificultad);
        void setHabilitado(bool habilitado);
        void setCantEjercicios(int cantEj);
        void setInscripcionesCurso(set<Inscripcion*> inscripcionesCurso);
        void setPrevia(Curso* p);
        void setLeccion(Leccion* l);
        void setProfesor(Profesor* p);
        void setIdioma(Idioma* idioma);

        // getters
        string getNombreCurso();
        string getDescripcion();
        DificultadCurso getDificultad();
        bool getHabilitado();
        int getCantEjercicios();
        set<Inscripcion*> getInscripciones();
        set<Curso*> getPrevias();
        set<Leccion*> getLecciones();
        Profesor* getProfesor();
        Idioma* getIdioma();

        // constructor y destructor 
        Curso(string nombreCurso, string descripcion, DificultadCurso dificultad, bool habilitado, int cantEj, set<Curso*> Previas, set<Leccion*> Leccion, Profesor* profesor, Idioma* idioma);
        ~Curso();

        // otras operaciones
        bool cursoSinLecciones();
        Leccion* obtenerLeccionActual(string nickname);
        set<Leccion*> obtenerLecciones();
        Leccion* obtenerLeccion(int idLeccion);
        DTPromedioCurso obtenerEstadisticasCurso();

        float calcularPromedio();  
        void incrementarCantEjercicios(int cantidadNueva);
        bool aproboPrevias(Estudiante* estudiante);
        void agregarInscripcion(Inscripcion* inscripcion);   
        void eliminarInscripcion(Inscripcion* inscripcion);
        void eliminarLecciones();
        void eliminarInscripciones();
        DTInfoCurso* getDataCurso();
};

#include "profesor.h"
#endif

