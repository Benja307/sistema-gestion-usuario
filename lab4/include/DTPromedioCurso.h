#ifndef DTPROMEDIOCURSO
#define DTPROMEDIOCURSO

#include <string>
#include <iostream>
using namespace std;

class DTPromedioCurso {
    private: 
        string infoCurso;
        float promedio;
    public:
        //setters
        void setInfoCurso(string infoCurso);
        void setPromedio(float promedio);

        //getters
        string getInfoCurso();
        float getPromedio();
        void mostrarDT();

        //constructor y destructor 
        DTPromedioCurso(string infoCurso, float promedio);
        ~DTPromedioCurso();      
};
#endif