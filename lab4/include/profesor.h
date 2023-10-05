#ifndef PROFESOR
#define PROFESOR


#include "DTPromedioCurso.h"
#include "DTInfoProfesor.h"
#include "usuario.h"
#include "idioma.h"
#include <vector>
#include <string>
using namespace std;

class Curso;

class Profesor : public Usuario {
    private:
        string instituto;
        set<Idioma *> idiomasEspecializado;
        set<Curso *> cursosDictados;
    public:
        // getters y setters
        void setInstituto(string instituto);
        string getInstituto();

        // otras operaciones
        void agregarEspecializacion(Idioma *i);
        void agregarCursoDictado(Curso *c);
        set<string> listarEspecializaciones();
        void desasociarCurso(Curso *c);
        vector<DTPromedioCurso> obtenerEstadisticasProfesor();
        DTInfoProfesor *getDataProfesor();

        // constructor y destructor
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
        virtual ~Profesor();
};

#include "curso.h"
#endif