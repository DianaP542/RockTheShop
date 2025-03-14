#include "idgen.h"

string IdGenerator::puneNr(int n){
    string sir = to_string(n);
    while (sir.length()<4)
        sir = "0" +sir;
    return sir;
}

string IdGenerator::genereaza(string tip){
    string prefix;
    if(tip=="Haina")
        prefix = "H";
    else if(tip=="Disc")
        prefix = "D";
    else if(tip=="Vintage")
        prefix = "V";
    else if(tip=="Manager")
        prefix="M";
    else if(tip=="Operator")
        prefix="O";
    else if(tip=="Asistent")
        prefix="A";
    nr[prefix]++;
    return prefix + puneNr(nr[prefix]);
}

map<string, int> IdGenerator::nr;
