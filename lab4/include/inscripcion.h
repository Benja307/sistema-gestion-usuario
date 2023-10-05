#ifndef INSCRIPCION
#define INSCRIPCION

#include "DTFecha.h"
#include "DTAvanceCurso.h"
#include <set>
using namespace std;

class Estudiante;
class Curso;

class Inscripcion{
    private:
        string nombreCurso;
        DTFecha *fechaInscripcion;
        bool aprobado;
        float cantEjAprobados;
        Estudiante *estudiante;
        Curso *curso;
    public:
        //getters y setters
        void setNombreCurso(string nombre);
        void setFechaInscripcion(DTFecha *fecha);
        void setAprobado(bool aprobado);
        void setCantEjAprobados(int cantEjAprobados);
        void setEstudiante(Estudiante *estudiante);
        void setCurso(Curso *curso);
        bool getAprobado();
        
        //otras operaciones
        void incrementarCantEjAprobados();
        DTAvanceCurso* getDataAvance();
        float calcularAvance(int cantEj);
        string getNombreCurso();
        Estudiante* getEstudiante();
        DTFecha* getFechaInscripcion();
        int getCantEjAprobados();
        set<string> listarCursosNoAprobados();

        //constructor y destructor
        Inscripcion(string nombreCurso, DTFecha *fecha, bool aprobado, int cantEjAprobados, Estudiante *estudiante, Curso *curso);
        virtual ~Inscripcion();
};

#include "estudiante.h"
#include "curso.h"
#endif