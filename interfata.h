#include "comanda.h"
#pragma once


class Interfata{
    vector<Angajati*> angajati;
    vector<Produse*> produse;
    queue<Comanda*> asteptare;
    map<string, vector<Comanda*>> comAng;
public:
    Interfata()=default;
    ~Interfata();

    bool areStoc()const;
    bool areAng()const;
    Angajati* valabil();

    void addAngajat(Angajati );
    void remvAngajat(const string& );
    void modifAng(const string& ,const string& );
    void afisAng(const string& )const;
    void afisTotAng()const;

    void addProdus(Produse );
    void remvProd(const string& );
    void modifProd(const string& ,int );
    void afisProd(const string& )const;
    void afisTotProd()const;
};

