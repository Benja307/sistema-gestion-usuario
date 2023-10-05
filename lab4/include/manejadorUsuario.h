#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include "usuario.h"
#include "estudiante.h"
#include "profesor.h"
#include "DTInfoUsuario.h"

#include <map>
#include <set>

using namespace std;

class ManejadorUsuario{
    private:
        map<string, Usuario*> Usuarios;
        map<string, Estudiante*> Estudiantes;
        map<string, Profesor*> Profesores;
        static ManejadorUsuario* instancia;
    public:
        static ManejadorUsuario* getInstancia();
        bool existeUsuario(string nickname);
        
        void agregarUsuario(Usuario* u);
        void agregarEstudiante(Estudiante* e);
        void agregarProfesor(Profesor* p);
        
        Usuario* obtenerUsuario(string nickname);
        Estudiante* obtenerEstudiante(string nickname);
        Profesor* obtenerProfesor(string nickname); 
        set<string> listarProfesores();  
        set<string> listarEstudiantes();
        DTInfoUsuario obtenerDatosUsuario(string nickname);
        set<string> listarUsuarios(); 

        ManejadorUsuario();
        ~ManejadorUsuario();
                 
};

#endif
