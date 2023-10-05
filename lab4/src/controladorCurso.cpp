#include "../include/controladorCurso.h"
using namespace std;


ControladorCurso::ControladorCurso(){};

ControladorCurso::~ControladorCurso(){};

set<string> ControladorCurso::listarProfesores(){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    return mu->listarProfesores();
};


void ControladorCurso::seleccionarProfesor(string nicknameProfesor){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Profesor* p = mu->obtenerProfesor(nicknameProfesor);
    this->memProfesor = p;
};

void ControladorCurso::ingresarDatosCurso(string nombreCurso, string descipcion, DificultadCurso dificultad){
    this->memNombreCurso = nombreCurso;
    this->memDescripcion = descipcion;
    this->memDificultad = dificultad;
    this->memCantTotalEjercicios = 0;
};

set<string> ControladorCurso::listarIdiomasEspecializadoProfesor(){
    set<string> idiomasEspecializadoProfesor = memProfesor->listarEspecializaciones();
    return idiomasEspecializadoProfesor;
};

void ControladorCurso::seleccionarEspecializacion(string nombreIdioma){
    ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
    Idioma* i = mi->obtenerIdioma(nombreIdioma);
    this->memIdioma = i;
};

set<string> ControladorCurso::listarCursosHabilitados(){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    set<string> cursosHabilitados = mc->listarCursosHabilitados();
    return cursosHabilitados;
};

bool ControladorCurso::agregarPrevia(string nombreCurso){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    Curso* p = mc->obtenerCurso(nombreCurso);
    if ((p->getIdioma()->getNombre() == memIdioma->getNombre()) && (p->getDificultad() < memDificultad)){
        previasRecordadas.insert(p);
        return true;
    } else 
        return false;
};

void ControladorCurso::ingresarLeccion(string tema, string objetivo){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    Leccion* l = new Leccion(leccionesRecordadas.size()+1, tema, objetivo);
    leccionesRecordadas.insert(l);
    this->memLeccion = l;
    l->setCantEjercicios(0);
};

void ControladorCurso::ingresarEjercicioTraduccion(string descripcion, string frase, string solucion){
    int id = memLeccion->getCantEjercicios();
    Traduccion* t = new Traduccion(id+1, descripcion, frase, solucion);
    memLeccion->ingresarALeccionTraduccion(t);
    memLeccion->incrementarCantEjercicios();
    memCantTotalEjercicios = memCantTotalEjercicios + 1;
};

void ControladorCurso::ingresarEjercicioCompletarPalabras(string descripcion, string frase, string solucion){
    int id = memLeccion->getCantEjercicios();
    CompletarPalabras* cp = new CompletarPalabras(id+1, descripcion, frase, solucion);
    memLeccion->ingresarALeccionCompletarPalabra(cp);
    memLeccion->incrementarCantEjercicios();
    memCantTotalEjercicios = memCantTotalEjercicios + 1;
};

bool ControladorCurso::confirmarAltaCurso(){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    bool existe = mc->existeCurso(memNombreCurso);
    if(!existe){
        altaCurso();
    }
    return !existe;
};

void ControladorCurso::altaCurso(){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    Curso* c = new Curso(memNombreCurso, memDescripcion, memDificultad, false, memCantTotalEjercicios, previasRecordadas, leccionesRecordadas, memProfesor, memIdioma);
    mc->agregarCurso(c);
    memProfesor->agregarCursoDictado(c);
    memIdioma->notificarNuevoCurso(memNombreCurso);
    c->setCantEjercicios(memCantTotalEjercicios);
    leccionesRecordadas.clear();
    previasRecordadas.clear();
    memCantTotalEjercicios = 0;
};

set<string> ControladorCurso::listarCursosNoHabilitados(){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    set<string> cursosNoHabilitados = mc->listarCursosNoHabilitados();
    return cursosNoHabilitados;
};

void ControladorCurso::seleccionarCursoNoHabilitado(string nombreCurso){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    Curso* c = mc->obtenerCurso(nombreCurso);
    this->memCursoNoHabilitado = c;
    set<Leccion*> lecciones = c->getLecciones();
    for(set<Leccion*>::iterator it=lecciones.begin(); it!=lecciones.end(); ++it){
        leccionesRecordadas.insert(*it);
    }
};

void ControladorCurso::confirmarAltaLeccion(){
    memCursoNoHabilitado->setLeccion(memLeccion);
    memCursoNoHabilitado->incrementarCantEjercicios(memCantTotalEjercicios);
    memCantTotalEjercicios = 0;
};

set<int> ControladorCurso::listarLeccionesDefinidas(string nombreCurso){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    Curso* c = mc->obtenerCurso(nombreCurso);
    set<int> lecciones = mc->listarLecciones(c);
    return lecciones;
};

void ControladorCurso::seleccionarLeccion(int idLeccion){
    Leccion* l = memCursoNoHabilitado->obtenerLeccion(idLeccion);
    this->memLeccion = l;
}

void ControladorCurso::confirmarAltaEjercicio(){
    memCursoNoHabilitado->incrementarCantEjercicios(memCantTotalEjercicios);
    memCantTotalEjercicios = 0;
};


set<string> ControladorCurso::listarCursos(){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    return mc->listarCursos();
}

set<string> ControladorCurso::listarEstudiantes(){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    return mu->listarEstudiantes();
}

set<DTAvanceCurso*> ControladorCurso::obtenerEstadisticasEstudiante(string nicknameEstudiante){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Estudiante* estudiante = mu->obtenerEstudiante(nicknameEstudiante);
    set<DTAvanceCurso*> estadisticasEst = estudiante->obtenerEstadisticasEstudiante();
    return estadisticasEst;
}

DTPromedioCurso ControladorCurso::obtenerEstadisticasCurso(string nombreCurso){
    ManejadorCurso* mu = ManejadorCurso::getInstancia();
    Curso* curso = mu->obtenerCurso(nombreCurso);
    return curso->obtenerEstadisticasCurso();
}

vector<DTPromedioCurso> ControladorCurso::obtenerEstadisticasProfesor(string nicknameProfesor){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Profesor* profesor = mu->obtenerProfesor(nicknameProfesor);
    return profesor->obtenerEstadisticasProfesor();
};

// idea: que devuelva un int para devolver en pantalla por qué no se puede habilitar
int ControladorCurso::habilitarCurso(string nombreCurso){
    int habilitado = -1;
    ManejadorCurso *mC = ManejadorCurso::getInstancia();
    Curso *cursoAHabilitar = mC->obtenerCurso(nombreCurso);
    if (cursoAHabilitar != NULL){        
    /* chequea si tiene al menos una lección y luego chequea que no haya ninguna sin ejercicios */
        bool cursoVacio = cursoAHabilitar->cursoSinLecciones();
        if (!cursoVacio) {
            set<Leccion *> lecciones = cursoAHabilitar->obtenerLecciones();
            set<Leccion *>::iterator it = lecciones.begin();
            while ((it != lecciones.end()) && (habilitado == -1)){
                Leccion *leccion = *it;
                if (leccion->getCantEjercicios() <= 0){
                    habilitado = 3;
                }
                it++;
            }
            if (habilitado == -1){
                habilitado = 1;
            }
        } else {
            habilitado = 2;
        }
    }
    if (habilitado == 1){
        cursoAHabilitar->setHabilitado(true);
    }
    return habilitado;
};

//DTInfoCurso ControladorCurso::obtenerInfoCurso(nombreCurso: string);

set<string> ControladorCurso::inscripcionCurso(string nickname){
    set<string> cursosDisponibles;
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    this->memEstudiante = mu->obtenerEstudiante(nickname);
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    map<string,Curso*> cursosNoInscripto = mc->obtenerCursosNoInscripto(this->memEstudiante);
    for(auto it = cursosNoInscripto.begin(); it != cursosNoInscripto.end(); ++it){
        bool apto = it->second->aproboPrevias(this->memEstudiante);
        if(apto){
            cursosDisponibles.insert(it->first);
        }
    }
    return cursosDisponibles;
};

bool ControladorCurso::confirmarInscripcion(string nombreCurso, int dia, int mes, int anio){
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    DTFecha* fecha = new DTFecha(dia,mes,anio);
    Curso* curso = mc->obtenerCurso(nombreCurso);
    Inscripcion* nuevaInscripcion = new Inscripcion(nombreCurso,fecha,false,0,this->memEstudiante,curso);
    this->memEstudiante->agregarInscripcion(nombreCurso,nuevaInscripcion);
    curso->agregarInscripcion(nuevaInscripcion);

    return true;
};

bool ControladorCurso::altaIdioma(string nombreIdioma){
    ManejadorIdioma* mi = ManejadorIdioma::getInstancia();
    bool existe = mi->existeIdioma(nombreIdioma);
    if(!existe){
        Idioma* i = new Idioma(nombreIdioma);
        mi->agregarIdioma(i);
        return true;
    }else 
        //liberar memoria?
        return false;
};

bool ControladorCurso::eliminarCurso(string nombreCurso){
    ManejadorCurso *mc = ManejadorCurso::getInstancia();
    Curso *cursoAEliminar = mc->obtenerCurso(nombreCurso);
    bool eliminado;
    if (cursoAEliminar != NULL){
        Profesor *p = cursoAEliminar->getProfesor();
        p->desasociarCurso(cursoAEliminar);
        cursoAEliminar->eliminarInscripciones();
        cursoAEliminar->eliminarLecciones();
        mc->eliminarCurso(cursoAEliminar);
    }
    return (!mc->existeCurso(nombreCurso));
};


void ControladorCurso::mostrarCurso(string nombreCurso) {
    ManejadorCurso *mC = ManejadorCurso::getInstancia();
    Curso *curso = mC->obtenerCurso(nombreCurso);
    DTInfoCurso *DTc = curso -> getDataCurso();
    DTc -> mostrarInfoCurso();          
}

bool ControladorCurso::existeCurso(string nombreCurso) {
    ManejadorCurso* mc = ManejadorCurso::getInstancia();
    bool existe = mc->existeCurso(nombreCurso);
    return existe;
};