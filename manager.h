#include "angajati.h"

class Manager:public Angajati{
    const double coef = 1.25;
public:
    Manager() =default;
    Manager(string ,string ,long long ,time_t );
    friend double Angajati::salariu(double );
    void afis();
};
