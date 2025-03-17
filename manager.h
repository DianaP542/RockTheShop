#include "angajati.h"
#pragma once


class Manager:public Angajati{
    const double coef = 1.25;
public:
    Manager() =default;
    Manager(string ,string ,string ,time_t );
    friend double Angajati::salariu(double );
    void afis();
};
