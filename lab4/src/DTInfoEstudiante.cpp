#include "../include/DTInfoEstudiante.h"

DTInfoEstudiante::DTInfoEstudiante(string nombre, string descripcion, string paisResidencia, DTFecha* fechaNacimiento) : DTInfoUsuario(nombre, descripcion){
    this->paisResidencia = paisResidencia;
    this->fechaNacimiento = fechaNacimiento;
};

DTInfoEstudiante::~DTInfoEstudiante(){};

// setters revisar si van
void DTInfoEstudiante::setPaisResidencia(string paisResidencia){
    this->paisResidencia = paisResidencia;
};

void DTInfoEstudiante::setFechaNacimiento(DTFecha* fechaNacimiento){
    this->fechaNacimiento = fechaNacimiento;
};

// getters revisar si van
string DTInfoEstudiante::getPaisResidencia(){
    return paisResidencia;
};
DTFecha* DTInfoEstudiante::getFechaNacimiento(){
    return fechaNacimiento;
};

void DTInfoEstudiante::mostrarInfoEstudiante(){
    cout << "Nombre: " << this->getNombre() << endl;
    cout << "Descripcion: " << this->getDescripcion() << endl;
    cout << "Pais de residencia: " << this->paisResidencia << endl;
    cout << "Fecha de nacimiento: ";
    this->getFechaNacimiento()->mostrarFecha();
    cout << "\n";
};



