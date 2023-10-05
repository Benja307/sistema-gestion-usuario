#ifndef IDIOMA
#define IDIOMA

#include "IObserver.h"
#include "DTNotificacion.h"
#include <iostream>
#include <string>
using namespace std;


class Idioma {
    private:
        string nombreIdioma;
        set<IObserver*> suscriptos;
    public:
        // setter y getter
        void setNombre(string nombreIdioma);
        string getNombre();

        // otras operaciones
        void agregarObs(IObserver* o);
        void removerObs(IObserver* o);
        void notificarNuevoCurso(string nombreCurso);
        bool estaSuscripto(IObserver* o);

        //constructor y destructor
        Idioma(string nombreIdioma);
        ~Idioma();
};

#endif