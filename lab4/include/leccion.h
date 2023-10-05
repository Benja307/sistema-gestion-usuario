#ifndef LECCION
#define LECCION

// #include "estudiante.h"
#include "ejercicio.h"
#include "traduccion.h"
#include "completarPalabras.h"
#include <string>
#include <set>
using namespace std;

class Estudiante;

class Leccion{
    private:
        int id;
        string tema;
        string objetivo;
        int cantEjercicios;
        set<Ejercicio*> ejercicios;
    public:
        // setters
        void setId(int id);
        void setTema(string tema);  
        void setObjetivo(string objetivo);
        void setCantEjercicios(int cantEj);

        // getters
        int getId();
        string getTema();
        string getObjetivo();
        int getCantEjercicios();
        set<Ejercicio*> getEjercicios();

        // otras operaciones
        void ingresarALeccionTraduccion(Traduccion* t);
        void ingresarALeccionCompletarPalabra(CompletarPalabras* cp);
        // Ejercicio* obtenerEjercicio(int idEjercicio);
        bool leccionAprobada(string nickname);
        set<int> obtenerIdEjerciciosNoAprobados(string nicknameEstudiante);
        Ejercicio* obtenerProblema(int id);
        void incrementarCantEjercicios();
        void eliminarEjercicios();
        Ejercicio* obtenerEjercicio(int idEjercicio);
        Leccion(int id, string tema, string objetivo);
        virtual ~Leccion();
};

#endif