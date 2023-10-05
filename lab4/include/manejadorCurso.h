#ifndef MANEJADORCURSO
#define MANEJADORCURSO

#include "curso.h"
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class ManejadorCurso {
    private:
        map<string, Curso*> Cursos;
        static ManejadorCurso* Instancia;
    public:
        static ManejadorCurso * getInstancia();
        bool existeCurso(string nombreCurso);        
        void agregarCurso(Curso* c);        
        Curso* obtenerCurso(string nombreCurso);    
        set<string> listarCursosHabilitados();  
        set<string> listarCursos();
        set<string> listarCursosNoHabilitados();
        set<int> listarLecciones(Curso* curso); 
        map<string,Curso*> obtenerCursosNoInscripto(Estudiante* estudiante);
        void eliminarCurso(Curso* curso);

        ManejadorCurso();
        ~ManejadorCurso();
        
};

#endif