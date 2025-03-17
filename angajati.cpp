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
    if(CNP.length() != 13)
        return false;
    string aux= CNP.substr(0,1);
    //prima cifra
    int s= stoi(aux);
    if (s>8)
        return false;
    //anul
    aux=CNP.substr(1,2);
    int a= stoi(aux);
    if ((s>4 && s<7) && a>07)
        return false;
    //luna
    aux=CNP.substr(3,2);
    int l= stoi(aux);
    if(l>12)
        return false;
    //ziua
    aux=CNP.substr(5,2);
    s = stoi(aux);
    if(s>31)
    //judet
    aux=CNP.substr(7,2);
    s = stoi(aux);
    if((s>52)|| (s>46 && s<51))
        return false;
    return true;
}

bool Angajati::eSarbatorit(){
    string aux=CNP.substr(3,2);
    int l= stoi(aux); //l= luna de nastere din buletin
    time_t timp = time(NULL);
    struct tm *a = localtime(&timp);
    int luna = a->tm_mon + 1; //luna= luna actuala
    if(l == luna)
        return true;
    return false;
}
