#include "idgen.h"
#pragma once


class Produse{
    string tip;
    string nume;
    int nrS;
    double pretB;
    string cod;
public:
    Produse()= default;
    Produse(string ,string , int, double);
    virtual void afis();
    virtual double pret();
    string getNume();
    string getTip();
    double getPret();
    string getId();
    void addStoc(int );
    virtual ~Produse()=default;
};
