#include "produse.h"

Produse::Produse(string tip,string nume, int nrS, double pretB):cod(IdGenerator::genereaza(tip)){
    this->nume=nume;
    this->nrS=nrS;
    this->pretB=pretB;
    this->cod=cod;
}

void Produse::afis()
{
    cout<<endl;
    cout<<"Nume produs: "<<nume<<endl;
    cout<<"Cate produse la fel in stoc: "<<nrS<<endl;
    cout<<"Pret fara taxe: "<<pretB<<endl;
    cout<<"Cod unic: "<<cod<<endl;
}

double Produse::pret(){
    return pretB;
}

string Produse::getTip(){
    return tip;
}

double Produse::getPret(){
    return pretB;
}

string Produse::getId(){
    return cod;
}

void Produse::addStoc(int stoc){
    nrS=stoc;
}

string Produse::getNume(){
    return nume;
}
