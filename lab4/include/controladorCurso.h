#ifndef CONTROLADORCURSO
#define CONTROLADORCURSO

#include "ICurso.h"
#include "profesor.h"
#include "traduccion.h"
#include "completarPalabras.h"
#include "DificultadCurso.h"
#include "idioma.h"
#include "DTPromedioCurso.h"
#include "manejadorCurso.h"
#include "manejadorUsuario.h"
#include "manejadorIdioma.h"
#include "estudiante.h"
#include "DTInfoCurso.h"
#include "inscripcion.h"


#include <iostream>
#include <string>
#include <set>
#include <vector>

// using namespace std;

class ControladorCurso : public ICurso {
    private:
        Estudiante* memEstudiante;
        Profesor* memProfesor;
        string memNombreCurso;
        Curso* memCursoNoHabilitado;
        string memDescripcion;
        DificultadCurso memDificultad;
        Leccion* memLeccion;
        Idioma* memIdioma;
        set<Leccion*> leccionesRecordadas;
        set<Curso*> previasRecordadas;
        int memCantTotalEjercicios;
    public:
        //otras operaciones
        set<string> listarProfesores();
        void seleccionarProfesor(string nicknameProfesor);
        void ingresarDatosCurso(string nombreCurso, string descipcion, DificultadCurso dificultad);
        set<string> listarIdiomasEspecializadoProfesor();
        void seleccionarEspecializacion(string nombreIdioma);
        set<string> listarCursosHabilitados();
        bool agregarPrevia(string nombreCurso);
        void ingresarLeccion(string tema, string objetivo);
        void ingresarEjercicioTraduccion(string descripcion, string frase, string solucion);
        void ingresarEjercicioCompletarPalabras(string descripcion, string frase, string solucion);
        bool confirmarAltaCurso();
        void altaCurso();
        set<string> listarCursosNoHabilitados();
        void seleccionarCursoNoHabilitado(string nombreCurso);
        void confirmarAltaLeccion();
        set<int> listarLeccionesDefinidas(string nombreCurso);
        void seleccionarLeccion(int idLeccion);
        void confirmarAltaEjercicio();
        set<string> listarCursos();
        set<string> listarEstudiantes();
        set<DTAvanceCurso*> obtenerEstadisticasEstudiante(string nicknameEstudiante);
        DTPromedioCurso obtenerEstadisticasCurso(string nombreCurso);
        vector<DTPromedioCurso> obtenerEstadisticasProfesor(string nicknameProfesor);
        int habilitarCurso(string nombreCurso);
        //DTInfoCurso obtenerInfoCurso(string nombreCurso);
        set<string> inscripcionCurso(string nickname);
        bool confirmarInscripcion(string nombreCurso, int dia, int mes, int anio);
        bool altaIdioma(string nombreIdioma);
        bool eliminarCurso(string nombreCurso);
        void mostrarCurso(string nombreCurso);//
        bool existeCurso(string nombreCurso);//

        //constuctor y destructor
        ControladorCurso();
        ~ControladorCurso();
};

#endif