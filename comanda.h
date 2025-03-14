#include "asistent.h"

class Comanda{
    string comID;
    vector<Produse*> produse;
    chrono::system_clock::time_point timpCom;
    int procesare;
    double val;
    string opID;
    bool gata;
public:
    Comanda()=default;
    Comanda(const string& );
    void addProdus(Produse );
    bool validare();
    double valTotala();
    void afis();
};
