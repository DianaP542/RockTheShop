#include "disc.h"

Disc::Disc(string casa, time_t rel, string trupa, string numeAlb, string nume, int nrS, double pretB):Produse("Disc", nume, nrS, pretB){
    this->casaDiscuri=casa;
    lansare = rel;
    this->trupa=trupa;
    this->numeAlbum=numeAlb;
}

double Disc::pret(){
    double p=Produse::pret();
    return p+liv;
}

void Disc::afis(){
    Produse::afis();
    cout<<"Casa discuri: "<<casaDiscuri<<endl;
    cout<<"Data lansare: "<<ctime(&lansare);
    cout<<"Trupa: "<<trupa<<endl;
    cout<<"Nume album: "<<numeAlbum<<endl;
    double p=pret();
    cout<<"Pret cu taxe livrare: "<<p<<endl;
}
