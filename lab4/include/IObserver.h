#ifndef IOBSERVER
#define IOBSERVER

#include <set>
#include <string>
using namespace std;

class IObserver{
    public:
        virtual void notificar(string nombreCurso, string nombreIdioma) = 0;
        //virtual ~IObserver(); //virtual?
};

#endif