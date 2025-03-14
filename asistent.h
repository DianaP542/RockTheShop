#include "operator.h"

class Asistent:public Angajati{
    const double coef= 0.75;
public:
    Asistent() =default;
    Asistent(string ,string ,long long ,time_t );
    friend double Angajati::salariu(double);
    void afis();
};
