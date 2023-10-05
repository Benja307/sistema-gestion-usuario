#ifndef DTEJERCICIO
#define DTEJERCICIO

#include <string>
#include <iostream>
using namespace std;

class DTEjercicio {
    private:
        string descripcion;
    public:
        // setter
        void setDescripcion(string descripcion);

        // getter
        string getDescripcion();

        // constructor y destructor 
        DTEjercicio(string descripcion);
        ~DTEjercicio();      
};

#endif