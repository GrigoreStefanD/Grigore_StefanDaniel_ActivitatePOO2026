#include <iostream>
#include <cstring>
using namespace std;



class Bazin 

{
private:
    int lungime;
    int latime;
    char* nume;


public:
    // constructor

    Bazin() 
{
        lungime = 50;
        latime = 25;
        nume = new char[strlen("olimpic") + 1];
        strcpy(nume, "olimpic");
    }


    // constructor cu parametri
    Bazin(int l, int la, const char* n) 
{
        lungime = l;
        latime = la;
        nume = new char[strlen(n) + 1];
        strcpy(nume, n);
    }


    // constructor de copiere
    Bazin(const Bazin& b) 
{
        lungime = b.lungime;
        latime = b.latime;
        nume = new char[strlen(b.nume) + 1];
        strcpy(nume, b.nume);
    }

    // destructor
    ~Bazin() {
        delete[] nume;
    }

    // getteri
    int getLungime() { return lungime; }
    int getLatime() { return latime; }
    char* getNume() { return nume; }

    // setteri
    void setLungime(int l) { lungime = l; }
    void setLatime(int l) { latime = l; }

    void setNume(const char* n) {
        delete[] nume;
        nume = new char[strlen(n) + 1];
        strcpy(nume, n);
    }

    // operator =
    Bazin& operator=(const Bazin& b) 
{
        if (this != &b) {
            lungime = b.lungime;
            latime = b.latime;
            delete[] nume;
            nume = new char[strlen(b.nume) + 1];
            strcpy(nume, b.nume);
        }

        return *this;

    }

    // operator citire
    friend istream& operator>>(istream& in, Bazin& b) 
{
        char aux[100];
        cout << "lungime: ";
        in >> b.lungime;
        cout << "latime: ";
        in >> b.latime;
        cout << "nume: ";
        in >> aux;
        b.setNume(aux);
        return in;
    }

    // operator afisare
    friend ostream& operator<<(ostream& out, const Bazin& b) 
{
        out << "lungime: " << b.lungime << endl;
        out << "latime: " << b.latime << endl;
        out << "nume: " << b.nume << endl;
        return out;
    }
};

int main() 
{
    Bazin b1, b2;

    // citire de la tastatura
    cin >> b1;

    // afisare
    cout << b1;

    // constructor cu parametri
    Bazin b2(" "); // verificare constructor mai jos
    Bazin b3(50, 25, "olimpic");

    // constructor de copiere
    Bazin b4(b3);

    // operator egal
    b2 = b3;

    // verificare
    cout << b2;
    cout << b4;

    // verificare getteri si setteri
    b3.setLungime(60);
    cout << b3.getLungime() << endl;

    return 0;
}