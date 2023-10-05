#ifndef ICURSO
#define ICURSO

#include <string>
#include <set>
#include <vector>
#include "DificultadCurso.h"
#include "DTPromedioCurso.h"
#include "DTAvanceCurso.h"
#include "DTFecha.h"
#include "inscripcion.h"

class ICurso{
    public:
        virtual set<string> listarProfesores() = 0;
        virtual void seleccionarProfesor(string nicknameProfesor) = 0;
        virtual void ingresarDatosCurso(string nombreCurso, string descipcion, DificultadCurso dificultad) = 0;
        virtual set<string> listarIdiomasEspecializadoProfesor() = 0;
        virtual void seleccionarEspecializacion(string nombreIdioma) = 0;
        virtual set<string> listarCursosHabilitados() = 0;
        virtual bool agregarPrevia(string nombreCurso) = 0;
        virtual void ingresarLeccion(string tema, string objetivo) = 0;
        virtual void ingresarEjercicioTraduccion(string descripcion, string frase, string solucion) = 0;
        virtual void ingresarEjercicioCompletarPalabras(string descripcion, string frase, string solucion) = 0;
        virtual bool confirmarAltaCurso() = 0;
        virtual void altaCurso() = 0;
        virtual set<string> listarCursosNoHabilitados() = 0;
        virtual void seleccionarCursoNoHabilitado(string nombreCurso) = 0;
        virtual void confirmarAltaLeccion() = 0;
        virtual set<int> listarLeccionesDefinidas(string nombreCurso) = 0;
        virtual void seleccionarLeccion(int idLeccion) = 0;
        virtual void confirmarAltaEjercicio() = 0;
        virtual set<string> listarCursos() = 0;
        virtual bool eliminarCurso(string nombreCurso) = 0;
        virtual set<string> listarEstudiantes() = 0;
        virtual set<DTAvanceCurso*> obtenerEstadisticasEstudiante(string nicknameEstudiante) = 0;
        virtual DTPromedioCurso obtenerEstadisticasCurso(string nombreCurso) = 0;
        virtual vector<DTPromedioCurso> obtenerEstadisticasProfesor(string nicknameProfesor) = 0;
        virtual int habilitarCurso(string nombreCurso) = 0;
        //virtual DTInfoCurso obtenerInfoCurso(string nombreCurso) = 0;
        virtual set<string> inscripcionCurso(string nickname) = 0;
        virtual bool confirmarInscripcion(string nombreCurso, int dia, int mes, int anio) = 0;
        virtual bool altaIdioma(string nombreIdioma) = 0;
        virtual void mostrarCurso(string nombreCurso) = 0;
        virtual bool existeCurso(string nombreCurso) = 0;

        virtual ~ICurso();
};

#endif