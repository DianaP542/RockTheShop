#include "artv.h"

ArtVest::ArtVest(string culoare, string marca, string nume, int nrS, double pretB):Produse("Haina", nume, nrS, pretB){
    this->culoare=culoare;
    this->marca=marca;
}

double ArtVest::pret(){
    double p=Produse::pret();
    return p + impLiv;
}

void ArtVest::afis(){
    Produse::afis();
    cout<<"Culoare: "<<culoare<<endl;
    cout<<"Marca: "<<marca<<endl;
    double p=pret();
    cout<<"Pret cu taxe impachetare si livrare: "<<p<<endl;
}
