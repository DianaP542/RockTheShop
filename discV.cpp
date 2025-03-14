#include "discV.h"

DiscV::DiscV(string stare, int coef, string casa, time_t rel, string trupa, string numeAlb, string nume, int nrS, double pretB):Disc(casa, rel, trupa, numeAlb, nume, nrS, pretB){
    this->stare=stare;
    this->coef=coef;
}

double DiscV::pret(){
    double p=Disc::pret();
    return p+ (coef * Raritate);
}

void DiscV::afis(){
    Disc::afis();
    cout<<"Stare: "<<stare<<endl;
    cout<<"Coeficient de raritate: "<<coef<<endl;
    double p=pret();
    cout<<"Pret cu taxa raritate: "<<p<<endl;
}
