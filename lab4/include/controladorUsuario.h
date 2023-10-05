#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include <iostream>
#include "IUsuario.h"
#include "usuario.h"
#include "estudiante.h"
#include "inscripcion.h"
#include "profesor.h"
#include "idioma.h"
#include "ejercicio.h"
#include "completarPalabras.h"
#include "traduccion.h"
#include "manejadorCurso.h"
#include "manejadorUsuario.h"
#include "manejadorIdioma.h"
#include "DTNotificacion.h"
#include "DTInfoUsuario.h"
#include "DTInfoEstudiante.h"
#include "DTInfoProfesor.h"

#include <set>
#include <string>
using namespace std;

class ControladorUsuario : public IUsuario {
    private:
        string memNickname;
        string memContrasenia;
        string memNombre;
        string memDescripcion;
        string memPais;
        string memCurso;
        DTFecha* memFechaNacimiento;
        string memInstituto;
        Estudiante* memEstudiante;
        Leccion* memLeccion;
        Ejercicio* memEjercicio;
        set<Idioma*> idiomasRecordados;

    public:
        //otras operaciones
        void ingresarDatosUsuario(string nickname, string contrasenia, string nombre, string descripcion);
        void ingresarDatosEstudiante(string nombrePais, int dia, int mes, int anio);
        bool confirmarAltaEstudiante();
        void ingresarInstituto(string nombreInstituto);
        set<string> listarIdiomasDisponibles(); 
        void ingresarEspecializacion(string nombreIdioma);
        bool confirmarAltaProfesor();

        void consultarUsuario(string nickname);
        void consultarInfoEjercicio(int idEjercicio);
        set<string> suscribirNotificaciones(string nickname);
        void confirmarSuscripcion(string nickname, string nombreIdioma);
        set<DTNotificacion*> consultarNotificaciones(string nickname);
        void eliminarNotificaciones(string nickname);
        set<string> cancelarSuscripciones(string nickname);
        void eliminarSuscripcion(string nickname, string nombreIdioma);
        set<string> listarUsuariosSistema();
        Usuario* obtenerUsuarioSistema(string nickname);
        Estudiante* obtenerEstudianteSistema(string nicknameEstudiante);
        Idioma *obtenerIdiomaSistema(string nombre);
        set<int> listarEjerciciosNoAprobados(string nombreCurso);
        set<string> listarEstudiantesSistema();
        bool compararSoluciones(string sol);
        void cargarEjerciciosAprobados(string nicknameEstudiante, string nombreCurso, int idEjercicio);

        // constructor y destructor
        ControladorUsuario();
        ~ControladorUsuario();

        /* Realizar ejercicio */
        set<string> listarCursosNoAprobados(string nickname);
        // DTEjercicio *presentarProblema(int id);
        bool ingresarSolucion(string sol);
        };

#endif
