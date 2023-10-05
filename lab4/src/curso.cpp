#include "../include/curso.h"


// constructor

Curso::Curso(string nombreCurso, string descripcion, DificultadCurso dificultad, bool habilitado, int cantEj, set<Curso*> Previas, set<Leccion*> Lecciones, Profesor* profesor, Idioma* idioma) {
    this->nombreCurso = nombreCurso;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->habilitado = habilitado;
    this->cantEj = cantEj;
    this->Previas = Previas;
    this->Lecciones = Lecciones;
    this->profesor = profesor;
    this->idioma = idioma;
};

// destructor

Curso::~Curso() {};

// setters
void Curso::setNombreCurso(string nombreCurso){
    this->nombreCurso = nombreCurso;
}

void Curso::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

void Curso::setDificultad(DificultadCurso dificultad){
    this->dificultad = dificultad;
}

void Curso::setHabilitado(bool habilitado){
    this->habilitado = habilitado;
}

void Curso::setCantEjercicios(int cantEj){
    this->cantEj = cantEj;
}

void Curso::setPrevia(Curso* p){
    Previas.insert(p);
}

void Curso::setLeccion(Leccion* l){
    Lecciones.insert(l);
}

void Curso::setIdioma(Idioma* idioma){
    this->idioma = idioma;
}

// getters 
string Curso::getNombreCurso() {
    return nombreCurso;
}

string Curso::getDescripcion(){
    return descripcion;
}
    
DificultadCurso Curso::getDificultad(){
    return dificultad;
}

bool Curso::getHabilitado(){
    return habilitado;
}

// string Curso::getNicknameProfesor(){
//     return nicknameProfesor;
// }

set<Leccion *> Curso::getLecciones(){
    return Lecciones;
};

set<Inscripcion *> Curso::getInscripciones(){
    return inscripcionesCurso;
};

Idioma* Curso::getIdioma(){
    return idioma;
};

bool Curso::cursoSinLecciones(){
    return (Lecciones.size() == 0);
};

DTPromedioCurso Curso::obtenerEstadisticasCurso(){
    string nombreCurso = this->nombreCurso;
    float prom = calcularPromedio();
    DTPromedioCurso promedio = DTPromedioCurso(nombreCurso,prom);
    promedio.mostrarDT();
    return promedio;
};

float Curso::calcularPromedio(){
    if (this->habilitado) {
        int nroInscripciones = 0;
        float sumaAvances = 0;
        for(auto it = inscripcionesCurso.begin(); it != inscripcionesCurso.end(); it++){
            ++nroInscripciones;
            Inscripcion* inscripcion = *it;
            float avanceEstudiante = inscripcion->calcularAvance(this->cantEj);
            sumaAvances += avanceEstudiante;   
        }
        return (sumaAvances/nroInscripciones);
    } else {
        return 0;
    }

};

int Curso::getCantEjercicios(){
    return cantEj;
}


Profesor* Curso::getProfesor(){
    return profesor;
};


set<Leccion*> Curso::obtenerLecciones(){
    return this->Lecciones;
}

Leccion* Curso::obtenerLeccion(int idLeccion){
    set<Leccion*>::iterator it = Lecciones.begin();
    Leccion* l = *it;
    while(l->getId() != idLeccion){
        ++it;
        l = *it;
    }
    return l;
};

void Curso::incrementarCantEjercicios(int cantidadNueva){
    this->cantEj = cantEj + cantidadNueva;
}

bool Curso::aproboPrevias(Estudiante* estudiante){
    set<Curso*>::iterator it = Previas.begin();
    bool apto = true;
    while(it != Previas.end() && apto){
        string prev = (*it)->getNombreCurso();
        apto = estudiante->estaAprobado(prev);
        ++it;
    }

    return apto;
}

void Curso::agregarInscripcion(Inscripcion* inscripcion){
    inscripcionesCurso.insert(inscripcion);
}

void Curso::eliminarInscripcion(Inscripcion *inscripcion){
    Inscripcion* aux = inscripcion;
    if (inscripcion->getDataAvance() != NULL){
        delete inscripcion->getDataAvance();
    }
    delete inscripcion->getFechaInscripcion();
    (this->inscripcionesCurso).erase(inscripcion);
    delete aux;
};


Leccion* Curso::obtenerLeccionActual(string nickname){
    set<Leccion*> lecciones = this->getLecciones();
    set<Leccion*>::iterator itl;
    Leccion* l = NULL;
    int minID = 1000;
    for (itl = lecciones.begin(); itl != lecciones.end(); ++itl){
        int id = (*itl)->getId();
        if ((!(*itl)->leccionAprobada(nickname)) && (id < minID)){
            l = *itl;
            minID = id;
        }
    }
    return l;
};

void Curso::eliminarLecciones(){
    set<Leccion*> lecciones = this->getLecciones();
    set<Leccion*>::iterator itl;
    for (itl = lecciones.begin(); itl != lecciones.end(); itl++){
        (*itl)->eliminarEjercicios();
        delete *itl;
    }
    this->Lecciones.clear();
};

void Curso::eliminarInscripciones(){
    set<Inscripcion*> inscripciones = this->getInscripciones();
    set<Inscripcion*>::iterator iti;
    for (iti = inscripciones.begin(); iti != inscripciones.end(); iti++){
        delete *iti;
    }
    this->inscripcionesCurso.clear();
};



DTInfoCurso* Curso::getDataCurso(){
    string p = getProfesor() -> getNombre();
    string i = getIdioma() -> getNombre();
    DTInfoCurso* infoC = new DTInfoCurso(this->getNombreCurso(), this->getDescripcion(),this->getDificultad(), this->getCantEjercicios(),this->getHabilitado(),i,p,this->getLecciones(),this->getInscripciones());
    return infoC;
}