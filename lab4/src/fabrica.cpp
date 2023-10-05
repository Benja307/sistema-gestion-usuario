#include "../include/fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){};

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
};

IUsuario* Fabrica::getIUsuario(){
    IUsuario* iu = new ControladorUsuario();
    return iu;
};

ICurso* Fabrica::getICurso(){
    ICurso* ic = new ControladorCurso();
    return ic;
};

//Fabrica::~Fabrica(){};