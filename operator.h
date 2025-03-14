#include "manager.h"

class Operator:public Angajati{
    const double coef = 1;
public:
    Operator() =default;
    Operator(string ,string ,long long ,time_t );
    friend double Angajati::salariu(double);
    void afis();
};
