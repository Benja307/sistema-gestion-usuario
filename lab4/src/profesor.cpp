#include "../include/profesor.h"
// using namespace std;


Profesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto) : Usuario(nickname, contrasenia, nombre, descripcion){
    this->instituto = instituto;
};

Profesor::~Profesor(){};

void Profesor::setInstituto(string instituto){
    this->instituto = instituto;
};

string Profesor::getInstituto(){
    return instituto;
};

void Profesor::agregarEspecializacion(Idioma* i){
    this->idiomasEspecializado.insert(i);
};

void Profesor::agregarCursoDictado(Curso* c){
    this->cursosDictados.insert(c);
};

set<string> Profesor::listarEspecializaciones(){
    set<string> esp;
    for(auto it = idiomasEspecializado.begin(); it != idiomasEspecializado.end(); ++it){
        esp.insert((*it)->getNombre());
    }
    return esp;

};

void Profesor::desasociarCurso(Curso *c){
    set<Curso*> cursosDictados = this->cursosDictados;
    for(auto it = cursosDictados.begin(); it != cursosDictados.end(); ++it){
        if(*it == c){
            cursosDictados.erase(it);
            break;
        }
    }
    this->cursosDictados = cursosDictados;
};

vector<DTPromedioCurso> Profesor::obtenerEstadisticasProfesor(){
    vector<DTPromedioCurso> listaPromedios;
    for(auto it = cursosDictados.begin(); it != cursosDictados.end(); it++){
        Curso* curso = *it;
        listaPromedios.push_back(curso->obtenerEstadisticasCurso());
    }
    return listaPromedios;
};
        

DTInfoProfesor* Profesor::getDataProfesor(){
    set<string> especializaciones = this->listarEspecializaciones();
    DTInfoProfesor* infoP = new DTInfoProfesor(this->getNombre(), this->getDescripcion(), this->instituto, especializaciones);
    return infoP;
}

