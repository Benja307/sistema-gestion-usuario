#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "DTAvanceCurso.h"
#include "DTFecha.h"
#include "usuario.h"
#include "inscripcion.h"
#include "DTInfoEstudiante.h"
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class Estudiante : public Usuario {
    private:
        string paisResidencia;
        DTFecha* fechaNacimiento;
        map<string,Inscripcion*> inscripcionesEstudiante;        
    public:
        //setters
        void setPaisResidencia(string paisResidencia);
        void setFechaNacimiento(DTFecha* fechaNacimiento);

        //getters
        
        //otras operaciones
        void eliminarInscripcion(Inscripcion i);
        set<string> listarCursosNoAprobados();
        void incrementarCantEjAprobados(string nombreCurso);
        set<DTAvanceCurso*> obtenerEstadisticasEstudiante();
        DTInfoEstudiante* getDataEstudiante();
        bool estaInscripto(Curso* curso);
        bool estaAprobado(string nombreCurso);
        void agregarInscripcion(string nombreCurso, Inscripcion* inscripcion);
        
        map<string, Inscripcion*> getInscripciones();

        //constructor y destructor 
        Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string paisResidencia, DTFecha* fechaNacimiento);
        virtual ~Estudiante();
};

#endif
