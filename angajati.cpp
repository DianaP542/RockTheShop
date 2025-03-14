#include "angajati.h"

Angajati::Angajati(string tip, string nume, string prenume, string CNP, time_t data):ID(IdGenerator::genereaza(tip)){
    this->ID=ID;
    this->nume=nume;
    this->prenume=prenume;
    this->CNP=CNP;
    this->data=data;
}

double Angajati::salariu(double coef){
    auto a =chrono::system_clock::now();
    time_t time= chrono::system_clock::to_time_t(a);
    tm *acum = localtime(&time);
    tm *angajare = localtime(&data);
    int ani = (acum->tm_year-1900) - angajare->tm_year + 1900;
    double total= salariuB +(bonus *ani) +((salariuB+ (bonus*ani)) * coef)/100;
    if(eSarbatorit())
        total= total+100;
    return total;
}

void Angajati::afis(){
    cout<<endl;
    cout<<"ID: "<<ID<<endl;
    cout<<"Nume: "<<nume<<endl;
    cout<<"Prenume: "<<prenume<<endl;
    cout<<"CNP: "<<CNP<<endl;
    cout<<"Data angajare: "<<ctime(&data)<<endl;
}

string Angajati::getId(){
    return ID;
}

void Angajati::schimb(const string& numeNou){
    prenume= numeNou;
}

string Angajati::getNume(){
    string numeC = nume;
    numeC= numeC + " ";
    numeC= numeC + prenume;
    return numeC;
}

string Angajati::getTip(){
    return tip;
}

bool Angajati::validare(){
    /*
    string aux =to_string(CNP);
    if(aux.length() != 13)
        return false;
    long long s=CNP;
    while (s>9)
        s= s/10;
    if (s>8)
        return false;
    long long a=CNP;
    while(a>999)
        a=a/10;
    a= a%100;
    if (s>5 && a>07)
        return false;
    long long l=CNP;
    while (l > 99999)
        l=l/10;
    l=l%100;
    if(l>12)
        return false;
    l=CNP;
    while (l > 9999999)
        l=l/10;
    l=l%100;
    if(l>31)
    l=CNP;
    for(int i=0; i<3;i++)
        l=l/10;
    l=l%100;
    if((l>52)|| (l>46 && l<51))
        return false;
    */
    if (CNP.length() != 13)
        return false;
    return true;
}

bool Angajati::eSarbatorit(){
    long long l=CNP; //de schimbat
    while (l > 99999)
        l=l/10;
    l=l%100;
    time_t timp = time(NULL);
    struct tm *a = localtime(&timp);
    int luna = a->tm_mon + 1;
    if(l == luna)
        return true;
    return false;
}
