#include "angajati.h"
#pragma once


class Operator:public Angajati{
    const double coef = 1;
public:
    Operator() =default;
    Operator(string ,string ,string ,time_t );
    friend double Angajati::salariu(double);
    void afis();
};
