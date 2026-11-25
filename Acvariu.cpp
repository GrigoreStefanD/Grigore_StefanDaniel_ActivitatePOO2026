#define	_CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>
using namespace std;

class Acvariu


{
private:
    int adancime;
    float temperatura;
    bool apaSarata;
    char* specie;

public:


    // constructor

    Acvariu()

    {
        adancime = 100;
        temperatura = 25.5;
        apaSarata = false;
        specie = new char[strlen("carasi") + 1];
        strcpy(specie, "carasi");
    }




    // constructor cu parametri
    Acvariu(int a, float t, bool s, const char* sp)
    {
        adancime = a;
        temperatura = t;
        apaSarata = s;
        specie = new char[strlen(sp) + 1];
        strcpy(specie, sp);

    }





    // constructor de copiere
    Acvariu(const Acvariu& a)

    {
        adancime = a.adancime;
        temperatura = a.temperatura;
        apaSarata = a.apaSarata;
        specie = new char[strlen(a.specie) + 1];
        strcpy(specie, a.specie);
    }


    // destructor
    ~Acvariu()
    {
        delete[] specie;
    }



    // getteri


    int getAdancime() { return adancime; }
    float getTemperatura() { return temperatura; }
    bool getApaSarata() { return apaSarata; }
    char* getSpecie() { return specie; }

    // setteri

    void setAdancime(int a) { adancime = a; }
    void setTemperatura(float t) { temperatura = t; }
    void setApaSarata(bool s) { apaSarata = s; }



    void setSpecie(const char* sp)
    {
        delete[] specie;
        specie = new char[strlen(sp) + 1];
        strcpy(specie, sp);
    }



    // operator =
    Acvariu& operator=(const Acvariu& a)
    {
        if (this != &a) {
            adancime = a.adancime;
            temperatura = a.temperatura;
            apaSarata = a.apaSarata;
            delete[] specie;
            specie = new char[strlen(a.specie) + 1];
            strcpy(specie, a.specie);
        }

        return *this;
    }



    // operator citire
    friend istream& operator>>(istream& in, Acvariu& a)
    {
        char aux[100];

        cout << "adancime: ";
        in >> a.adancime;

        cout << "temperatura: ";
        in >> a.temperatura;

        cout << "apa sarata (1-da, 0-nu): ";
        in >> a.apaSarata;

        cout << "specie: ";
        in >> aux;

        a.setSpecie(aux);

        return in;
    }



    // operator afisare
    friend ostream& operator<<(ostream& out, const Acvariu& a)
    {
        out << "adancime: " << a.adancime << endl;
        out << "temperatura: " << a.temperatura << endl;
        out << "apa sarata: " << a.apaSarata << endl;
        out << "specie: " << a.specie << endl;

        return out;


    }


};




int main()
{

    Acvariu a1, a2;

    // citire de la tastatura
    cin >> a1;

    // afisare
    cout << a1;



    // constructor cu parametri
    Acvariu a3(120, 26.5, 1, "scalari");



    // constructor de copiere
    Acvariu a4(a3);


    // operator egal
    a2 = a3;



    // verificare
    cout << a2;
    cout << a4;




    // verificare getteri si setteri
    a3.setAdancime(150);
    cout << a3.getAdancime() << endl;


    a3.setTemperatura(27.5);
    cout << a3.getTemperatura() << endl;



    a3.setApaSarata(true);
    cout << a3.getApaSarata() << endl;


    a3.setSpecie("guppy");
    cout << a3.getSpecie() << endl;


    return 0;


}
