#include "manager.h"

Manager::Manager(string nume, string prenume, string CNP, time_t data):Angajati("Manager", nume, prenume, CNP, data){}

void Manager::afis(){
    Angajati::afis();
    double s=salariu(coef);
    cout<<"Salariu: "<<s<<endl;
}
