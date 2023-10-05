#include "../include/DTInfoProfesor.h"

DTInfoProfesor::DTInfoProfesor(string nombre, string descripcion, string instituto ,set<string> idiomasEspecializado) : DTInfoUsuario(nombre, descripcion){
    this->instituto = instituto;
    this->idiomasEspecializado = idiomasEspecializado;
};

DTInfoProfesor::~DTInfoProfesor(){};    


void DTInfoProfesor::setInstituto(string instituto){
    this->instituto = instituto;
};

string DTInfoProfesor::getInstituto(){
    return instituto;
};


void DTInfoProfesor::mostrarInfoProfesor(){
    cout << "Nombre: " << this->getNombre() << endl;
    cout << "Descripcion: " << this->getDescripcion() << endl;
    cout << "Instituto donde trabaja: " << this->instituto << endl;
    cout << "Idiomas especializado: ";
    for (auto it = this->idiomasEspecializado.begin(); it != this->idiomasEspecializado.end(); ++it){
        cout << (*it) <<", ";
    }
    cout << "\n";
}
 