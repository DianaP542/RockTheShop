#include "comanda.h"

Comanda::Comanda(const string &id){
    this->opID=id;
    timpCom = chrono::system_clock::now();
    procesare=0;
    val=0;
    gata = false;
}

void Comanda::addProdus(Produse prod){
    int nrH=0, nrD=0;
    for (Produse* p : produse)
    {
        if(p->getTip()== "Haina")
            nrH++;
        else if(p->getTip()=="Disc" || p->getTip()=="Vintage")
            nrD++;
    }
    if(nrD > 5 || nrH > 3)
        cout<<"Prea multe produse";
    produse.push_back(new Produse(move(prod)));
}

bool Comanda::validare(){
    double valFaraT= 0;
    for (Produse* p : produse)
    {
        valFaraT += p->getPret();
    }
    if(valFaraT <100)
        return false;
    return true;
}

double Comanda::valTotala(){
    double ValoareTot = 0;
    for (Produse *p : produse)
    {
        ValoareTot += p->pret();
    }
    return ValoareTot;
}

void Comanda::afis(){
    for(Produse *p)
}
