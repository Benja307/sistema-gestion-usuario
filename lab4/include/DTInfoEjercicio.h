#ifndef DTINFOEJERCICIO
#define DTINFOEJERCICIO

#include <string>
#include <iostream>

using namespace std;

class DTInfoEjercicio {
    private: 
        string descripcion;
        string informacion;
    public:
        /* setters */
        void setDescripcion(string descipcion);
        void setInformacion(string informacion);

        /* getters */ 
        string getDescripcion();
        string getInformacion();

        /* constructor y destructor */
        DTInfoEjercicio(string descripcion, string informacion);
        ~DTInfoEjercicio();      
};

#endif