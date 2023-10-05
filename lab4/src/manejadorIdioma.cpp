#include "../include/manejadorIdioma.h"

using namespace std;

ManejadorIdioma* ManejadorIdioma::instancia = NULL;

ManejadorIdioma::ManejadorIdioma(){}

//ManejadorIdioma::~ManejadorIdioma(){}

ManejadorIdioma* ManejadorIdioma::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorIdioma();
    return instancia;
}
        
bool ManejadorIdioma::existeIdioma(string nombre){
    return (Idiomas.find(nombre) != Idiomas.end());
}
        
void ManejadorIdioma::agregarIdioma(Idioma* i){
    Idiomas.insert({i->getNombre(), i});
}
        
Idioma* ManejadorIdioma::obtenerIdioma(string nombre){
    auto it = Idiomas.find(nombre);
    return (it->second);
}
        
set<string> ManejadorIdioma::listarIdiomas(){
    set<string> nombreIdiomas;
    map<string, Idioma*>::iterator it;
    for(it=Idiomas.begin(); it!=Idiomas.end(); ++it){
        nombreIdiomas.insert(it->first);
    }
    return nombreIdiomas;
} 

set<string> ManejadorIdioma::listarIdiomasNoSuscripto(IObserver* o){
    set<string> idiomasNoSuscrito;
    for(auto it = Idiomas.begin(); it != Idiomas.end(); ++it){
        if (!it->second->estaSuscripto(o))
            idiomasNoSuscrito.insert(it->first);
    }
    return idiomasNoSuscrito;
}

set<string> ManejadorIdioma::listarIdiomasSuscripto(IObserver* o){
    set<string> idiomasSuscrito;
    for(auto it = Idiomas.begin(); it != Idiomas.end(); ++it){
        if (it->second->estaSuscripto(o))
            idiomasSuscrito.insert(it->first);
    }
    return idiomasSuscrito;
}