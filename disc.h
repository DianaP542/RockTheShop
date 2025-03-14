#include "artv.h"

class Disc:public Produse{
    string casaDiscuri;
    time_t lansare;
    string trupa;
    string numeAlbum;
    const double liv= 5;
public:
    Disc()=default;
    Disc(string , time_t ,string ,string ,string , int , double );
    virtual double pret();
    virtual void afis();
    virtual ~Disc()=default;
};

