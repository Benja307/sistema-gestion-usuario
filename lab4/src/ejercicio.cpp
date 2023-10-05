#include "../include/ejercicio.h"
using namespace std;

Ejercicio::Ejercicio(int idEjercicio, string descripcion){
    this->idEjercicio = idEjercicio;
    this->descripcion = descripcion;
}

Ejercicio::~Ejercicio(){}

int Ejercicio::getIdEjercicio(){
    return idEjercicio;
};
    
string Ejercicio::getDescripcion(){
    return descripcion;
};

set<Estudiante *> Ejercicio::getEstudiantesAprobados(){
    return estudiantesAprobados;
};

set<string> Ejercicio::getNicknamesEstudiantesAprobados(){
    return nicknamesEstudiantesAprobados;
};

DTEjercicio* Ejercicio::obtenerDTEjercicio(){
    DTEjercicio *problema = new DTEjercicio(this->descripcion);
    return problema;
};

bool Ejercicio::ejercicioAprobado(string nicknameEstudiante){
    return nicknamesEstudiantesAprobados.find(nicknameEstudiante) != nicknamesEstudiantesAprobados.end();
};

// void Ejercicio::agregarNicknameEstudianteAprobado(string nicknameEstudiante){
//     nicknamesEstudiantesAprobados.insert(nicknameEstudiante);
// };

// void Ejercicio::agregarEstudianteAprobado(Estudiante *estudiante){
//     estudiantesAprobados.insert(estudiante);
// };

bool Ejercicio::compararSoluciones(string sol){
    CompletarPalabras *c = dynamic_cast<CompletarPalabras *>(this);
    Traduccion *t;
    bool iguales;
    if (c != NULL) {
        iguales = c->compararSoluciones(sol);
    }  else   {
        iguales = t->compararSoluciones(sol);
    }
    return iguales;
};

void Ejercicio::aprobarEjercicio(string nicknameEstudiante, Estudiante* estudiante){
    nicknamesEstudiantesAprobados.insert(nicknameEstudiante);
    estudiantesAprobados.insert(estudiante);
};
