#include "interfata.h"

Interfata::~Interfata(){
    for (Angajati* ang : angajati)
        delete ang;
    angajati.clear();
    for(Produse* pro :produse)
        delete pro;
    produse.clear();
}

bool Interfata::areStoc()const{
    map<string, int> inv;
    for(Produse* prod :produse)
        inv[prod->getTip()]++;
    if(inv["Haina"] <2 || inv["Disc"] <2 || inv["Vintage"] <2)
        return false;
    return true;
}

bool Interfata::areAng()const{
    map<string, int> inv;
    for (Angajati* ang :angajati)
        inv[ang->getTip()]++;
    if(inv["Manager"]<1 || inv["Operator"]<3 || inv["Asistent"] <1)
        return false;
    return true;
}

Angajati* Interfata::valabil(){
    for(Angajati* ang :angajati)
        if(ang->getTip() == "Operator" && comAng[ang->getId()].size() < 3)
            return ang;
    return nullptr;
}

void Interfata::addAngajat(Angajati ang){
    try{
        if(ang.validare())
        {
            angajati.push_back(new Angajati(move(ang)));
            cout <<"Angajat adaugat cu succes"<<endl;
        }
        else
            throw invalid_argument("Angajat minor sau CNP fals");
    }catch (const exception& e){
        cout<<e.what()<<endl;
    }

}

void Interfata::remvAngajat(const string& ID){
    try{
        for(size_t i =0;i<angajati.size(); i++)
            if(angajati[i]->getId()== ID)
                angajati.erase(angajati.begin() + i);
        if(!areAng())
            throw runtime_error("Prea putini angajati!");
        } catch(const exception& e){
            cout<<e.what()<<endl;
        }

}

void Interfata::modifAng(const string& ID, const string& numeNou){
    for(size_t i =0;i<angajati.size(); i++)
        if(angajati[i]->getId()== ID)
            angajati[i]->schimb(numeNou);
}

void Interfata::afisAng(const string& ID)const{
    for(size_t i =0;i<angajati.size(); i++)
        if(angajati[i]->getId()== ID)
            angajati[i]->afis();
}

void Interfata::afisTotAng()const{
    for(size_t i =0; i<angajati.size(); i++)
    {
        cout<<angajati[i]->getNume();
        cout<<" ";
        cout<<angajati[i]->getTip()<<endl;
    }
}

void Interfata::addProdus(Produse prod){
    produse.push_back(new Produse(move(prod)));
}

void Interfata::remvProd(const string& ID){
    try{
        for(size_t i =0;i<produse.size(); i++)
        if(produse[i]->getId()== ID)
            produse.erase(produse.begin() + i);
        if(!areStoc())
            throw runtime_error("Prea putine produse!");
        }catch(const exception& e){
            cout<<e.what()<<endl;
        }

}
void Interfata::modifProd(const string& ID ,int stoc){
    for(size_t i =0;i<produse.size(); i++)
        if(produse[i]->getId()== ID)
            produse[i]->addStoc(stoc);
}
void Interfata::afisProd(const string& ID)const{
    for(size_t i =0;i<produse.size(); i++)
        if(produse[i]->getId()== ID)
            produse[i]->afis();
}
void Interfata::afisTotProd()const{
    for(size_t i =0; i<produse.size(); i++)
    {
        cout<<produse[i]->getNume();
        cout<<" ";
        cout<<produse[i]->getTip();
        cout<<" ";
        cout<<produse[i]->getId()<<endl;
    }
}
