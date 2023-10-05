#ifndef IUSUARIO
#define IUSUARIO

//#include "fabrica.h"
#include "DTEjercicio.h"
#include "DTNotificacion.h"
#include "idioma.h"
#include "usuario.h"
#include <string>
#include <set>

class IUsuario{
    public:
        virtual void ingresarDatosUsuario(string nickname, string contrasenia, string nombre, string descripcion) = 0;
        virtual void ingresarDatosEstudiante(string nombrePais, int dia, int mes, int anio) = 0;
        virtual bool confirmarAltaEstudiante() = 0;
        virtual void ingresarInstituto(string nombreInstituto) = 0;
        virtual set<string> listarIdiomasDisponibles() = 0; 
        virtual void ingresarEspecializacion(string nombreIdioma) = 0;
        virtual bool confirmarAltaProfesor() = 0;
        //virtual set<string> listarCursosNoAprobados(string nickname) = 0;
        //virtual set<int> listarEjerciciosNoAprobados(string nombreCurso) = 0;
        //virtual DTEjercicio presentarProblema(int id) = 0;
        //virtual bool ingresarSolucion(string sol) = 0;
        virtual set<string> suscribirNotificaciones(string nickname) = 0;
        virtual void confirmarSuscripcion(string nickname, string nombreIdioma) = 0;
        virtual set<DTNotificacion*> consultarNotificaciones(string nickname) = 0;
        virtual void eliminarNotificaciones(string nickname) = 0;
        virtual set<string> cancelarSuscripciones(string nickname) = 0;
        virtual void eliminarSuscripcion(string nickname, string nombreIdioma) = 0;
        virtual set<string> listarUsuariosSistema() = 0;
        virtual Usuario* obtenerUsuarioSistema(string nickname) = 0;
        virtual Idioma* obtenerIdiomaSistema(string nombre) = 0;
        virtual void consultarUsuario(string nickname) = 0;
        virtual set<string> listarEstudiantesSistema() = 0;
        virtual set<string> listarCursosNoAprobados(string nickname) = 0;
        virtual set<int> listarEjerciciosNoAprobados(string nombreCurso) = 0;
        virtual void consultarInfoEjercicio(int idEjercicio) = 0;
        virtual bool compararSoluciones(string sol) = 0;
        virtual void cargarEjerciciosAprobados(string nicknameEstudiante, string nombreCurso, int idEjercicio) = 0;

        virtual ~IUsuario();
};

#endif 