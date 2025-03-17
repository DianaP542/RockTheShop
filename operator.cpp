#include "operator.h"

Operator::Operator( string nume, string prenume, string CNP, time_t data):Angajati("Operator", nume, prenume, CNP, data){}

void Operator::afis(){
    Angajati::afis();
    double s=salariu(coef);
    cout<<"Salariu: "<<s<<endl;
}
