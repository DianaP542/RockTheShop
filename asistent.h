#include "angajati.h"
#pragma once


class Asistent:public Angajati{
    const double coef= 0.75;
public:
    Asistent() =default;
    Asistent(string ,string ,string ,time_t );
    friend double Angajati::salariu(double);
    void afis();
};
