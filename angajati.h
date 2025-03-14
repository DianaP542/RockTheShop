#include "discV.h"

class Angajati{
    string tip;
    string ID;
    string nume;
    string prenume;
    string CNP;
    time_t data;
    const double salariuB= 3500;
    const int bonus =100;
    const double coef=0;
public:
    Angajati() =default;
    Angajati(string ,string ,string ,string ,time_t );
    double salariu(double coef);
    virtual void afis();
    virtual ~Angajati()=default;
    string getId();
    void schimb(const string& );
    string getNume();
    string getTip();
    bool validare();
    bool eSarbatorit();
};
