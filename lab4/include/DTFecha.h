#ifndef DTFECHA
#define DTFECHA

#include <string>
#include <iostream>
using namespace std;

class DTFecha {
    private: 
        int dia;
        int mes;
        int anio;
    public:
        //setters
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        //getters
        int getDia();
        int getMes();
        int getAnio();
        
        //constructor y destructor 
        DTFecha(int dia, int mes, int anio);
        ~DTFecha();      

        void mostrarFecha();
};

#endif