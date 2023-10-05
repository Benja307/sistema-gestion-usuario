#ifndef DTAVANCECURSO
#define DTAVANCECURSO

#include <string>
#include <iostream>
using namespace std;

class DTAvanceCurso {
    private: 
        string nombreCurso;
        float avance;
    public:
        //setters
        void setNombreCurso(string nombreCurso);
        void setAvance(float avance);

        //getters
        string getNombreCurso();
        float getAvance();

        //constructor y destructor 
        DTAvanceCurso(string nombreCurso,float avance);
        ~DTAvanceCurso();      
};

#endif