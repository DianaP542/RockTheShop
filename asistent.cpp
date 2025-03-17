#include "asistent.h"

Asistent::Asistent( string nume, string prenume, string CNP, time_t data):Angajati("Asistent", nume, prenume, CNP, data){}

void Asistent::afis(){
    Angajati::afis();
    double s=salariu(coef);
    cout<<"Salariu: "<<s<<endl;
}

