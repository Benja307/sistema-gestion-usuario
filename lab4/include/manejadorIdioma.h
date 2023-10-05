#ifndef MANEJADORIDIOMA
#define MANEJADORIDIOMA
#include "idioma.h"
#include <map>
#include <set>
#include <string>

using namespace std;

class ManejadorIdioma {
    private:
        map<string, Idioma*> Idiomas;
        static ManejadorIdioma* instancia;
        ManejadorIdioma();
    public:
        static ManejadorIdioma* getInstancia();
        bool existeIdioma(string nombre);
        void agregarIdioma(Idioma* i);
        Idioma* obtenerIdioma(string nombre);
        set<string> listarIdiomas();  

        set<string> listarIdiomasDisponibles();
        set<string> listarIdiomasNoSuscripto(IObserver* o);
        set<string> listarIdiomasSuscripto(IObserver* o);
        ~ManejadorIdioma();         
};

#endif