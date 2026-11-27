
#include <iostream>
#include <cstring>



using namespace std;




class Observator

{

private:
    int nrTelescoape;
    float inaltime;
    bool esteDeschis;
    char* locatie;



public:


    // constructor

    Observator()
    {
        nrTelescoape = 5;
        inaltime = 30.5;
        esteDeschis = true;
        locatie = new char[strlen("brasov") + 1];
        strcpy(locatie, "brasov");
    }


    // constructor cu parametri
    Observator(int n, float i, bool d, const char* l)
    {
        nrTelescoape = n;
        inaltime = i;
        esteDeschis = d;
        locatie = new char[strlen(l) + 1];
        strcpy(locatie, l);

    }


    // constructor de copiere
    Observator(const Observator& o)
    {
        nrTelescoape = o.nrTelescoape;
        inaltime = o.inaltime;
        esteDeschis = o.esteDeschis;
        locatie = new char[strlen(o.locatie) + 1];
        strcpy(locatie, o.locatie);

    }




    // destructor

    ~Observator()
    {
        delete[] locatie;
    }




    // getteri

    int getNrTelescoape() { return nrTelescoape; }
    float getInaltime() { return inaltime; }
    bool getEsteDeschis() { return esteDeschis; }
    char* getLocatie() { return locatie; }

    // setteri

    void setNrTelescoape(int n) { nrTelescoape = n; }
    void setInaltime(float i) { inaltime = i; }
    void setEsteDeschis(bool d) { esteDeschis = d; }



    void setLocatie(const char* l)

    {
        delete[] locatie;
        locatie = new char[strlen(l) + 1];
        strcpy(locatie, l);
    }


    // operator =

    Observator& operator=(const Observator& o)

    {
        if (this != &o) {
            nrTelescoape = o.nrTelescoape;
            inaltime = o.inaltime;
            esteDeschis = o.esteDeschis;
            delete[] locatie;
            locatie = new char[strlen(o.locatie) + 1];
            strcpy(locatie, o.locatie);
        }


        return *this;

    }


    // operator citire
    friend istream& operator>>(istream& in, Observator& o)

    {
        char aux[100];

        cout << "numar telescoape: ";
        in >> o.nrTelescoape;

        cout << "inaltime: ";
        in >> o.inaltime;

        cout << "este deschis (1-da, 0-nu): ";
        in >> o.esteDeschis;

        cout << "locatie: ";
        in >> aux;

        o.setLocatie(aux);

        return in;

    }



    // operator afisare

    friend ostream& operator<<(ostream& out, const Observator& o)
    {
        out << "numar telescoape: " << o.nrTelescoape << endl;
        out << "inaltime: " << o.inaltime << endl;
        out << "este deschis: " << o.esteDeschis << endl;
        out << "locatie: " << o.locatie << endl;

        return out;

    }

};





int main()

{

    Observator o1, o2;


    // citire de la tastatura
    cin >> o1;


    // afisare
    cout << o1;


    // constructor cu parametri
    Observator o3(8, 45.5, 1, "sibiu");


    // constructor de copiere
    Observator o4(o3);


    // operator egal
    o2 = o3;


    // verificare
    cout << o2;
    cout << o4;


    // verificare getteri si setteri
    o3.setNrTelescoape(10);
    cout << o3.getNrTelescoape() << endl;


    o3.setInaltime(50.5);
    cout << o3.getInaltime() << endl;



    o3.setEsteDeschis(false);
    cout << o3.getEsteDeschis() << endl;



    o3.setLocatie("cluj");
    cout << o3.getLocatie() << endl;


    return 0;

}



