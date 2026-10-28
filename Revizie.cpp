
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>
#include <vector>

#include <list>//

using namespace std;


//avem o aplicatie de gestionare a reviziilor auto
// clasa care retine denumirea si pretul unei operatii    
// neterminata 
class operatie
{

private:
    string denumire;
    double pret;

public:


      // constructor implicit
    operatie()
    {
        denumire = "operatie";
        pret = 0;
    }
      // constructor cu parametri
    operatie(string d, double p)
    {
        denumire = d;
        pret = p;
    }

     // constructor de copiere                
    operatie(const operatie& o)
    {
        denumire = o.denumire;
        pret = o.pret;
    }
                                  
     // returneaza pretul operatiei
        double getpret() const
        {
            return pret;
        }

       // returneaza denumirea operatiei                      
    string getdenumire() const
    {
        return denumire;

    }



    // copiaza datele unei operatii
    operatie& operator=(const operatie& o)                                                
    {
        if (this != &o)         
        {
            denumire = o.denumire;            
            pret = o.pret;
        }


        return *this;



    }

            // citeste o operatie de la tastatura  
    friend istream& operator>>(istream& in, operatie& o)

    {
        cout << "Denumire operatie: ";  
        in >> ws;   
        getline(in, o.denumire);   

        cout << "Pret: ";
        in >> o.pret;

        return in;


    }




     // afiseaza o operatie
    friend ostream& operator<<(ostream& out, const operatie& o)
    {     
        out << "Denumire: " << o.denumire << endl;         
        out << "Pret: " << o.pret << " lei" << endl;             

        return out;       


    }



};





// clasa care retine datele unei revizii auto
class revizie
{
protected:
    string numarauto;
    int numarrevizie;
    long numarkilometri;
    string data;
    vector<operatie> operatii;

public:
    // constructor implicit

    revizie()
    {
        numarauto = "TR01IDK";
        numarrevizie = 0;
        numarkilometri = 0;
        data = "01.01.2026";
    }



    // constructor cu o operatie

    revizie(string nr, int rev, long km, operatie o)
    {
        numarauto = nr;
        numarrevizie = rev;
        numarkilometri = km;
        data = "01.01.2026";
        operatii.push_back(o);
    }



    // constructor cu mai multe operatii
    revizie(string nr, vector<operatie> op, int n)
    {
        numarauto = nr;
        numarrevizie = 0;
        numarkilometri = 0;
        data = "01.01.2026";

        for (int i = 0; i < n && i < (int)op.size(); i++)
        {
            operatii.push_back(op[i]);
        }
    }

    // constructor fara operatii


    revizie(string nr, int rev, long km)
    {
        numarauto = nr;
        numarrevizie = rev;
        numarkilometri = km;
        data = "01.01.2026";
    }


      // destructor virtual asta e important pentru a nu aparea probleme la stergerea obiectelor
    // este default pentru ca nu avem nimic de facut in destructor
        //inseamna virtual pentru ca  revizie este mostenita de alte clase
    // destructorul trebuie sa fie virtual pentru a nu aparea probleme la stergerea obiectelor
    virtual ~revizie() = default;



    // modifica numarul de inmatriculare
    void setnumarauto(string nr)
    {
        numarauto = nr;
    }




    // calculeaza costul total al reviziei
    virtual double getcostrevizie() const
    {
        double suma = 0;

        for (const auto& o : operatii)
        {
            suma += o.getpret();
        }

        return suma;  


    }



    // adauga o operatie la revizie
    revizie& operator+=(const operatie& o)
    {
        operatii.push_back(o);
        return *this;
    }



    // sterge o operatie dupa denumire
    revizie& operator-=(string denumire)

    {
        for (auto i = operatii.begin(); i != operatii.end(); ++i)
        {
            if (i->getdenumire() == denumire)
            {
                operatii.erase(i);
                break;
            }



        }

        return *this;



    }



    // sterge o operatie folosind un obiect operatie
    revizie& operator-=(const operatie& o)
    {
        return *this -= o.getdenumire();
    }



    // transforma revizia in cost numeric
    operator double() const
    {
        return getcostrevizie();
    }



    // compara costurile a doua revizii
    bool operator<(const revizie& r) const
    {
        return getcostrevizie() < r.getcostrevizie();
    }



    bool operator>(const revizie& r) const
    {
        return getcostrevizie() > r.getcostrevizie();
    }



    bool operator==(const revizie& r) const
    {
        return getcostrevizie() == r.getcostrevizie();
    }




    // returneaza operatia de la pozitia indicata
    operatie operator[](int i) const
    {
        if (i >= 0 && i < (int)operatii.size())
        {
            return operatii[i];
        }

        cout << "Nu exista aceasta operatie!" << endl;
        return operatie();


    }



    // citeste o revizie de la tastatura
    friend istream& operator>>(istream& in, revizie& r)
    {
        cout << "Numar auto: ";
        in >> ws;
        getline(in, r.numarauto);
          
         
         
        cout << "Numar revizie: ";
        in >> r.numarrevizie;

        cout << "Numar kilometri: ";
        in >> r.numarkilometri;
         
         

        cout << "Data: ";
        in >> ws;
        getline(in, r.data);
         
         
        int n;
        cout << "Numar operatii: ";
        in >> n;

        r.operatii.clear();



        for (int i = 0; i < n; i++)
        {
            operatie o;

            cout << "Operatia " << i + 1 << endl;
            in >> o;

            r.operatii.push_back(o);
        }





        return in;





    }



    // afiseaza datele unei revizii
    friend ostream& operator<<(ostream& out, const revizie& r)
    {
        out << "Numar auto: " << r.numarauto << endl;
        out << "Numar revizie: " << r.numarrevizie << endl;
        out << "Kilometri: " << r.numarkilometri << endl;
        out << "Data: " << r.data << endl;
        out << "Operatii:" << endl;

        for (const auto& o : r.operatii)
        {
            out << o;
        }

        out << "Cost total: " << r.getcostrevizie() << " lei" << endl;

        return out;


    }



};
        

// clasa derivata care aplica o reducere
class reviziespeciala : public revizie

{
private:
    double reducere;



public:
    // constructor pentru revizia speciala
    reviziespeciala(string nr, int rev, long km, operatie o, double red)
        : revizie(nr, rev, km, o)
    {
        reducere = red;
    }
                 


    // calculeaza costul dupa reducere
    double getcostrevizie() const override
    {
        return revizie::getcostrevizie() * (1 - reducere);
    }
        
    // afiseaza revizia speciala     
    friend ostream& operator<<(ostream& out, const reviziespeciala& r)
    {
        out << static_cast<const revizie&>(r);
        out << "Reducere: " << r.reducere * 100 << "%" << endl;

        return out;
             
    }
            



};

               
int main() 
{ 

    // testam constructorul implicit
    revizie r1;

               


    // cream operatii
    operatie o1("schimbare ulei", 150);
    operatie o2("filtru aer", 99);
    operatie o3("filtru polen", 55);


                  

    // testam constructorul de copiere
    operatie o4(o1);
                     

    // testam constructorul cu mai multe operatii
    vector<operatie> lista = { o1, o2, o3, o4 };
    revizie r2("B99ABC", lista, 4);


                     

    // testam constructorul fara operatii
    revizie r3("B10XYZ", 2, 20000);


            

    // testam constructorul cu o operatie
    revizie r4("B20XYZ", 1, 10000, o1);
                            

    // citim o revizie de la tastatura
    cout << "Introduceti datele reviziei:" << endl;
    cin >> r1;




    // afisam reviziile
    cout << endl << "Reviziile introduse:" << endl;
    cout << r1 << r2 << r3 << r4;




                        
    // testam adaugarea operatiilor
    r3 += o1;
    r3 += o2;

    cout << endl << "Dupa adaugare:" << endl;
    cout << r3;




    // testam stergerea unei operatii
    r3 -= o1;

    cout << endl << "Dupa stergere:" << endl;
    cout << r3;



    // testam conversia la double
    cout << "Costul reviziei r2: " << (double)r2 << " lei" << endl;



    // testam compararea reviziilor                
    if (r2 > r3)
    {
        cout << "r2 este mai scumpa decat r3" << endl;                   
    }

                         

    if (r2 == r3)
    {
        cout << "Reviziile au acelasi cost" << endl;
    }

                   

    // testam operatorul de indexare
    cout << endl << "Prima operatie din r2:" << endl;          
    cout << r2[0];



    // testam revizia speciala cu reducere de 25 la suta
    reviziespeciala rs("B123KLM", 1, 25000, o1, 0.25);
    rs += o2;

    cout << endl << "Revizie speciala:" << endl;           
    cout << rs;

    cout << "Cost cu reducere: " << (double)rs << " lei" << endl;            



    // calculam incasarile totale
    list<revizie> revizii = { r1, r2, r3, r4, rs };                           

    double incasari = 0;                             

    for (const auto& r : revizii)

    {
        incasari += r.getcostrevizie();                           
    }

    cout << "Incasari totale: " << incasari << " lei" << endl;             

    return 0;                                      



}













