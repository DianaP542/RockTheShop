#include "produse.h"

class ArtVest:public Produse{
    string culoare;
    string marca;
    const double impLiv= 20;
public:
    ArtVest() =default;
    ArtVest( string, string, string, int, double);
    double pret();
    void afis();
};
