#ifndef FABRICA
#define FABRICA

#include "IUsuario.h"
#include "ICurso.h"
#include "controladorUsuario.h"
#include "controladorCurso.h"
using namespace std;

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        IUsuario* getIUsuario();
        ICurso* getICurso();
        static Fabrica* getInstancia();
};

#endif