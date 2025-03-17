#include "interfata.h"
#include "artv.h"
#include "discV.h"
#include "manager.h"
#include "asistent.h"
#include "operator.h"

using namespace std;


int main()
{
    
    tm timp{};
    timp.tm_year = 2005-1900;
    timp.tm_mday = 115;
    time_t timpAng = mktime(&timp);

    time_t rel;
    time(&rel);

    string culoare="alb", marca="nirvana", nume="tricou";
    ArtVest h1(culoare, marca, nume, 10, 60);
    h1.afis();
    int p= h1.pret();
    cout<<p<<endl;

    string casa="DGC", trupa="nirvana", album="nevermind", nd="disc";
    Disc d1(casa, rel, trupa, album, nd, 30, 200);
    d1.afis();
    p=d1.pret();
    cout<<p<<endl;

    string stare="nou";
    DiscV d2(stare, 1, casa, rel, trupa, album, nd, 30, 200);
    d2.afis();
    p=d2.pret();
    cout<<p<<endl;

    string num="Ilie", pren="Popoiu";
    
    string cnp = "6050425375472";
    Manager m(num, pren, cnp, timpAng);
    m.afis();
    double sal= m.salariu(0);
    cout<<sal<<endl;
    
    /*
    tm timp{};
    timp.tm_year = 2005-1900;
    timp.tm_mday = 115;
    mktime(&timp);
    string num="Ilie", pren="Popoiu", num2="Andreea", pren2="Dan";

    Manager m(num, pren, 5060125375472, timp);
    m.afis();
    cout<<endl;

    Interfata magazin;
    magazin.addAngajat(m);


    Manager m2(num2, pren2, 6050425645472, timp);

    magazin.addAngajat(m2);

    Operator m3(num2, pren, 6050425005472, timp);

    magazin.addAngajat(m3);
    magazin.afisTotAng();
    cout<<endl;

    magazin.modifAng("O0001", "Porumb");
    magazin.afisTotAng();
    */

    /*
    Interfata i;
    int alegere;
    time_t data= time(NULL);
    bool ok=false;
    while(ok == false){
        cout<<"Rock the Shop:"<<endl;
        cout<<"1. Manageriere Angajati"<<endl;
        cout<<"2. Manageriere Inventar"<<endl;
        cout<<"3. Procesare comenzi"<<endl;
        cout<<"4. Rapoarte"<<endl;
        cout<<"5. Stop program"<<endl;
        try{
            cin>>alegere;
            if(alegere>5 || alegere <1)
                throw invalid_argument("Nu e o optiune >:(");
            else if(alegere == 1)
            {
                cout<<"1. Adauga Angajat"<<endl;
                cout<<"2. Sterge Angajat"<<endl;
                cout<<"3. Modifica Nume"<<endl;
                cout<<"4. Arata Angajat"<<endl;
                cout<<"5. Arata toti angajatii"<<endl;
                cout<<"6. Inapoi"<<endl;
                int aleg1;
                cin>>aleg1;
                if(aleg1>6 ||aleg1<1)
                    throw invalid_argument("Nu e o optiune >:(");
                else if(aleg1==1)
                {
                    cout<<"Ce fel de angajat?"<<endl;
                    cout<<"1. Manager"<<endl;
                    cout<<"2. Operator"<<endl;
                    cout<<"3. Asistent"<<endl;
                    int aleg11;
                    if(aleg11>3 || aleg11<1)
                        throw invalid_argument("Nu e o optiune >:(");
                    else if(aleg11 == 1)
                    {
                        string nume;
                        string prenume;
                        long long CNP;
                        cout<<"Nume si prenume:"<<endl;
                        cin>>nume>>prenume;
                        cout<<"CNP:"<<endl;
                        cin>>CNP;
                        Manager m(nume, prenume, CNP, data);
                        i.addAngajat(m);
                    }
                    else if(aleg11 == 2)
                    {
                        string nume;
                        string prenume;
                        long long CNP;
                        cout<<"Nume si prenume:"<<endl;
                        cin>>nume>>prenume;
                        cout<<"CNP:"<<endl;
                        cin>>CNP;
                        Operator o(nume, prenume, CNP, data);
                        i.addAngajat(o);
                    }
                    else if(aleg11 == 3)
                    {
                        string nume;
                        string prenume;
                        long long CNP;
                        cout<<"Nume si prenume:"<<endl;
                        cin>>nume>>prenume;
                        cout<<"CNP:"<<endl;
                        cin>>CNP;
                        Asistent a(nume, prenume, CNP, data);
                        i.addAngajat(a);
                    }
                }
                else if(aleg1 == 2)
                {
                    cout<<"ID angajat concediat:"<<endl;
                    string ID;
                    cin>>ID;
                    i.remvAngajat(ID);
                }
                else if(aleg1 == 3)
                {
                    string n;
                    string ID;
                    cout<<"Nume nou:"<<endl;
                    cin>>n;
                    cout<<"ID angajat:"<<endl;
                    cin>>ID;
                    i.modifAng(ID, n);
                }
                else if(aleg1 == 4)
                {
                    string ID;
                    cout<<"ID angajat:"<<endl;
                    cin>>ID;
                    i.afisAng(ID);
                }
                else if(aleg1 == 5)
                {
                    i.afisTotAng();
                }
            }
            else if(alegere == 2)
            {
                cout<<"1. Adauga Produs"<<endl;
                cout<<"2. Sterge Produs"<<endl;
                cout<<"3. Modifica nrStoc"<<endl;
                cout<<"4. Arata Produs"<<endl;
                cout<<"5. Arata toate produsele"<<endl;
                cout<<"6. Inapoi"<<endl;
                int aleg2;
                cin>>aleg2;
                if(aleg2>6 ||aleg2<1)
                    throw invalid_argument("Nu e o optiune >:(");
                else if(aleg2==1)
                {
                    cout<<"Ce fel de produs?"<<endl;
                    cout<<"1. Articol Vestimentar"<<endl;
                    cout<<"2. Disc"<<endl;
                    cout<<"3.Disc Vintage"<<endl;
                    int aleg21;
                    cin>>aleg21;
                    if(aleg21<1 ||aleg21 >3)
                        throw invalid_argument("Nu e o optiune >:(");
                    else if(aleg21 == 1)
                    {
                        string culoare;
                        string marca;
                        string nume;
                        int nrS;
                        double pretB;
                        cout<<"Culoare, marca, nume, numar pe stoc, pret de baza"<<endl;
                        cin>>culoare>>marca>>nume>>nrS>>pretB;
                        ArtVest av(culoare, marca, nume, nrS, pretB);
                        i.addProdus(av);
                    }
                    else if(aleg21 == 3)
                    {
                        string stare;
                        int coef;
                        string casa;
                        time_t rel;
                        string trupa;
                        string numeAlb;
                        string culoare;
                        string marca;
                        string nume;
                        int nrS;
                        double pretB;
                        cout<<"Stare, coeficient de raritate, casa, an, trupa, nume album, nume, numar in stoc, pret de baza"<<endl;
                        cin>>stare>>coef>>casa>>rel>>trupa>>numeAlb>>nume>>nrS>>pretB;
                        DiscV dv(stare, coef, casa, rel, trupa, numeAlb, nume, nrS, pretB);
                        i.addProdus(dv);
                    }
                    else if(aleg21 == 2)
                    {
                        string casa;
                        time_t rel;
                        string trupa;
                        string numeAlb;
                        string culoare;
                        string marca;
                        string nume;
                        int nrS;
                        double pretB;
                        cout<<"Casa, an, trupa, nume album, nume, numar in stoc, pret de baza"<<endl;
                        cin>>casa>>rel>>trupa>>numeAlb>>nume>>nrS>>pretB;
                        Disc d(casa, rel, trupa, numeAlb, nume, nrS, pretB);
                        i.addProdus(d);
                    }
                }
                else if(aleg2 == 2)
                {
                    cout<<"ID produs:"<<endl;
                    string ID;
                    cin>>ID;
                    i.remvProd(ID);
                }
                else if(aleg2 == 3)
                {
                    int nrStoc;
                    string ID;
                    cout<<"Stoc nou:"<<endl;
                    cin>>nrStoc;
                    cout<<"ID produs:"<<endl;
                    cin>>ID;
                    i.modifProd(ID, nrStoc);
                }
                else if(aleg2 == 4)
                {
                    string ID;
                    cout<<"ID produs:"<<endl;
                    cin>>ID;
                    i.afisProd(ID);
                }
                else if(aleg2 == 5)
                {
                    i.afisTotProd();
                }
            }
            else if(alegere == 3)
            {
                cout<<"1. Procesare Comanda noua"<<endl;
                cout<<"2. Comenzi in asteptare"<<endl;
                cout<<"3. Status Comanda"<<endl;
                int aleg3;
                cin>>aleg3;
                if(aleg3<1 || aleg3< 3)
                    throw invalid_argument("Nu e o optiune >:(");
                else if(aleg3 == 1)
                {
                    ok = true;
                }
            }
            else if(alegere == 5)
                ok=true;
            }catch(const exception& e){
                            cout<<e.what()<<endl;
                    }
    }
    */

    return 0;
}
