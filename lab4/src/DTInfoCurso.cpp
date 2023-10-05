#include "../include/DTInfoCurso.h"

DTInfoCurso::DTInfoCurso(string nombreCurso, string descripcion, DificultadCurso dificultad, int cantEj, bool habilitado, string idioma, string nombreProfesor, set<Leccion*> lecciones, set<Inscripcion*> inscripciones){
    this->nombreCurso = nombreCurso;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->habilitado = habilitado;
    this->cantEj = cantEj;
    this->idioma = idioma;
    this->nombreProfesor = nombreProfesor;
    this->lecciones = lecciones;
    this->inscripciones = inscripciones;
};

DTInfoCurso::~DTInfoCurso(){};

void DTInfoCurso::setNombreCurso(string nombreCurso){
    this->nombreCurso = nombreCurso;
};

void DTInfoCurso::setDescripcion(string descipcion){
    this->descripcion = descipcion;
};

void DTInfoCurso::setDificultad(DificultadCurso dificultad){
    this->dificultad = dificultad;
};

void DTInfoCurso::setHabilitado(bool habilitado){
    this->habilitado = habilitado;
};

void DTInfoCurso::setIdioma(string idioma){
    this->idioma = idioma;
};

void DTInfoCurso::setNombreProfesor(string nombreProfesor){
    this->nombreProfesor = nombreProfesor;
};

void DTInfoCurso::setLecciones(set<Leccion*> lecciones){
    this->lecciones = lecciones;
};


/* getters */
string DTInfoCurso::getNombreCurso(){
    return nombreCurso;
};

string DTInfoCurso::getDescripcion(){
    return descripcion;
};

int DTInfoCurso::getCantEjercicios(){
    return cantEj;
};

DificultadCurso DTInfoCurso::getDificultad(){
    return dificultad;
};

bool DTInfoCurso::getHabilitado(){
    return habilitado;
};

string DTInfoCurso::getIdioma(){
    return idioma;
};

string DTInfoCurso::getProfesor(){
    return nombreProfesor;
};


set<Inscripcion*> DTInfoCurso::getInscripciones(){
    return inscripciones;
}

set<Leccion*> DTInfoCurso::getLecciones(){
    return lecciones;
}


void DTInfoCurso::mostrarInfoCurso(){
    cout << "Nombre: " << this->getNombreCurso() << endl;
    cout << "Descripcion: " << this->getDescripcion() << endl;
    cout << "Idioma: " << this->getIdioma() << endl;
    cout << "Docente a cargo: " << this->getProfesor() << endl;
    bool h = this->getHabilitado();
    string habilitado;
    if (h)
        habilitado = "Si";
    else 
        habilitado = "No";
    cout << "Curso habilitado: " << habilitado << endl;
    DificultadCurso d = this->getDificultad();
    string dificultad;
    switch (d)
    {
    case 0:
        dificultad = "Principiante";
        break;
    case 1:
        dificultad = "Medio";
        break;
    case 2:
        dificultad = "Avanzado";
        break;
    }
    cout << "Dificultad Curso: " << dificultad << endl;
    cout << "Cantidad de ejercicios: " << this->getCantEjercicios() << endl;
    cout << "\nLecciones en Curso: \n";
    set<Leccion*> l =  this -> getLecciones();
    for(set<Leccion*>::iterator it=l.begin(); it!=l.end(); ++it){
        cout << "Leccion " << ((*it)->getId()) << ":\n";
        cout<< "Tema: " << ((*it) -> getTema()) << endl;
        cout<< "Objetivo: " << ((*it) -> getObjetivo()) << endl;
        if (((*it) -> getCantEjercicios()) > 0) {
            set<Ejercicio*> e = (*it) -> getEjercicios();
            for(set<Ejercicio*> :: iterator it1 = e.begin(); it1!=e.end(); ++it1){
                cout << "Ejercicio " << ((*it1)->getIdEjercicio()) << ":\n";
                cout << "Descripcion: " << ((*it1) -> getDescripcion()) << endl;
                Ejercicio* eje = (*it1);
                CompletarPalabras* completar = dynamic_cast<CompletarPalabras*>(eje);
                if(completar != NULL) {
                    cout << "Frase a Completar: " << (completar -> getFraseACompletar()) << endl;
                }
                else {
                    Traduccion* traducir = dynamic_cast<Traduccion*>(eje);
                    string t = traducir -> getFraseATraducir();
                    cout << "Frase a Traducir: " << t << endl;
                }
            }
        }
        cout << "\n";
    }
    cout << "Estudiantes inscriptos:\n";
    set<Inscripcion*> ins = this -> getInscripciones();
    for(set<Inscripcion*>::iterator it2=ins.begin(); it2!=ins.end(); ++it2){
        Estudiante* e = (*it2) -> getEstudiante();
        cout << "Nombre Estudiante: " << e -> getNombre() << endl;
        DTFecha * fechaI = (*it2) -> getFechaInscripcion();
        cout << "Fecha de inscripción: ";
        fechaI->mostrarFecha();
        cout << "\n";
    }       
}