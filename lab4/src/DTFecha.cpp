#include "../include/DTFecha.h"
#include <iostream>

DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio; 
}

DTFecha::~DTFecha(){}

int DTFecha::getDia(){
    return dia;
}

int DTFecha::getMes(){
    return mes;
}

int DTFecha::getAnio(){
    return anio;
}

void DTFecha::mostrarFecha(){
    cout << this->dia << "/" << this->mes << "/" << this->anio << endl;
}