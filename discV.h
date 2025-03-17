#include "disc.h"
#pragma once


class DiscV:public Disc{
    string stare;
    int coef;
    const double Raritate= 15;
public:
    DiscV()=default;
    DiscV(string ,int , string , time_t ,string ,string ,string , int , double );
    double pret();
    void afis();
};
