      
#include <iostream>
#include <cstring>        
using namespace std;   
 

  
class Planetariu

{      

private: 
    int capacitate;
    float diametru; 
    bool areProiector; 
    char* denumire;

 
public:

    // constructor
    Planetariu()

    { 
        capacitate = 100;   
        diametru = 15.5;
        areProiector = true;
        denumire = new char[strlen("cosmos") + 1];   
        strcpy(denumire, "cosmos");
    }
  
 
 

    // constructor cu parametri 
    Planetariu(int c, float d, bool p, const char* n)
    { 
        capacitate = c; 
        diametru = d; 
        areProiector = p; 
        denumire = new char[strlen(n) + 1];
        strcpy(denumire, n);
    } 

 

    // constructor de copiere
    Planetariu(const Planetariu& p)
    {
        capacitate = p.capacitate;  
        diametru = p.diametru;   
        areProiector = p.areProiector;
        denumire = new char[strlen(p.denumire) + 1];
        strcpy(denumire, p.denumire);  
    }
  

 
    // destructor 
    ~Planetariu()
    { 
        delete[] denumire;
    } 


 
    // getteri
    int getCapacitate() { return capacitate; }
    float getDiametru() { return diametru; }
    bool getAreProiector() { return areProiector; }
    char* getDenumire() { return denumire; }

 
 
    // setteri  
    void setCapacitate(int c) { capacitate = c; } 
    void setDiametru(float d) { diametru = d; }  
    void setAreProiector(bool p) { areProiector = p; }
  
 
 
    void setDenumire(const char* n) 
    {
        delete[] denumire;  
        denumire = new char[strlen(n) + 1];
        strcpy(denumire, n);  
    }




    // operator =
    Planetariu& operator=(const Planetariu& p)
    {
        if (this != &p) {  
            capacitate = p.capacitate;   
            diametru = p.diametru;  
            areProiector = p.areProiector;  
            delete[] denumire; 
            denumire = new char[strlen(p.denumire) + 1];
            strcpy(denumire, p.denumire);  
        }   

    

        return *this;

    
    }

                       

         
    // operator citire

    friend istream& operator>>(istream& in, Planetariu& p)
    {
        char aux[100];

        cout << "capacitate: ";
        in >> p.capacitate;

        cout << "diametru: ";
        in >> p.diametru;

        cout << "are proiector (1-da, 0-nu): ";
        in >> p.areProiector;

        cout << "denumire: ";
        in >> aux;

        p.setDenumire(aux);


        return in;

    }



    // operator afisare

    friend ostream& operator<<(ostream& out, const Planetariu& p)
    {
        out << "capacitate: " << p.capacitate << endl;
        out << "diametru: " << p.diametru << endl;
        out << "are proiector: " << p.areProiector << endl;
        out << "denumire: " << p.denumire << endl;
                           
        return out;        
          

    }         
         

};
           

int main()
         

{

         
    Planetariu p1, p2;

    // citire de la tastatura
    cin >> p1;

    // afisare
    cout << p1;
        

      
    // constructor cu parametri
    Planetariu p3(150, 20.5, 1, "galaxy");



    // constructor de copiere
    Planetariu p4(p3);             

    // operator egal         
    p2 = p3;

    // verificare          
    cout << p2;
    cout << p4;






    // verificare getteri si setteri                   
    p3.setCapacitate(200);
    cout << p3.getCapacitate() << endl;

                             



    p3.setDiametru(25.5);
    cout << p3.getDiametru() << endl;               


    p3.setAreProiector(false);
    cout << p3.getAreProiector() << endl;


    p3.setDenumire("univers");
    cout << p3.getDenumire() << endl;






    return 0;



}
