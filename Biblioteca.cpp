



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>


using namespace std;


enum TipBiblioteca { PUBLICA = 1, PRIVATA = 2 };                        



class Biblioteca
{                                                                                                                         
private:
    const int id;
    TipBiblioteca tip;
    string denumire;                      
    float bugetTotal;
    int nrCarti;                                            
    float* preturiCarti;


public:
    static int nrBiblioteci;




    // Constructor implicit
    Biblioteca() : id(++nrBiblioteci)
    {
        this->denumire = "Biblioteca generala";
        this->bugetTotal = 0;                                                       
        this->tip = PUBLICA;
        this->nrCarti = 0;
        this->preturiCarti = nullptr;   

        
    }



    // Constructor cu parametri
    Biblioteca(int id, string denumire, float bugetTotal,
        int nrCarti, float* preturiCarti, TipBiblioteca tip)                                            
        : id(id)                      
    {           
        nrBiblioteci++;                                                                  

        this->denumire = denumire;
        this->bugetTotal = bugetTotal;           
        this->tip = tip;
        this->nrCarti = nrCarti;           

        if (nrCarti > 0 && preturiCarti != nullptr)
        {           
            this->preturiCarti = new float[nrCarti];
           
            for (int i = 0; i < nrCarti; i++)
            {           
                this->preturiCarti[i] = preturiCarti[i];
            }
        }           
        else
        {
            this->nrCarti = 0;           
            this->preturiCarti = nullptr;           
        }

    }



    // Constructor de copiere
    Biblioteca(const Biblioteca& copie) : id(++nrBiblioteci)
    {
        this->denumire = copie.denumire;
        this->bugetTotal = copie.bugetTotal;
        this->tip = copie.tip;
        this->nrCarti = copie.nrCarti;

        if (copie.preturiCarti != nullptr)
        {
            this->preturiCarti = new float[this->nrCarti];

            for (int i = 0; i < this->nrCarti; i++)
            {
                this->preturiCarti[i] = copie.preturiCarti[i];
            }
        }
        else
        {
            this->preturiCarti = nullptr;
        }


    }



    // Operator =
    Biblioteca& operator=(const Biblioteca& copie)
    {
        if (this != &copie)
        {
            this->denumire = copie.denumire;
            this->bugetTotal = copie.bugetTotal;
            this->tip = copie.tip;
            this->nrCarti = copie.nrCarti;

            delete[] this->preturiCarti;
            this->preturiCarti = nullptr;

            if (copie.preturiCarti != nullptr)
            {
                this->preturiCarti = new float[this->nrCarti];

                for (int i = 0; i < this->nrCarti; i++)
                {
                    this->preturiCarti[i] = copie.preturiCarti[i];
                }
            }
        }

        return *this;


    }





    // Getter si setter pentru nrCarti
    int getNrCarti()
    {
        return this->nrCarti;                                            
    }

    void setNrCarti(int valoareNoua)
    {                                                       
        if (valoareNoua >= 0)
        {
            this->nrCarti = valoareNoua;
        }           
        else
        {           
            throw exception();
        }
    }
           
    // Getter pentru preturiCarti           
    float* getPreturiCarti()
    {
        if (this->preturiCarti == nullptr)           
        {           
            return nullptr;
        }           

        float* copie = new float[this->nrCarti];

        for (int i = 0; i < this->nrCarti; i++)
        {
            copie[i] = this->preturiCarti[i];
        }
           
        return copie;           
    }           



    // Setter pentru preturiCarti           
    void setPreturiCarti(float* preturi, int dim)
    {
        if (dim < 0)                                            
        {
            throw exception();
        }

        float* copie = nullptr;

        if (preturi != nullptr && dim > 0)
        {
            copie = new float[dim];

            for (int i = 0; i < dim; i++)
            {
                copie[i] = preturi[i];
            }
        }

        delete[] this->preturiCarti;
        this->preturiCarti = copie;
        this->nrCarti = dim;
    }



    // Metoda de afisare
    void afisare()
    {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Buget total: " << this->bugetTotal;

        cout << endl << "Tip biblioteca: ";           

        if (this->tip == PUBLICA)
        {
            cout << "PUBLICA";
        }           
        else
        {
            cout << "PRIVATA";
        }           

        cout << endl << "Numar carti: " << this->nrCarti;

        if (this->nrCarti > 0 && this->preturiCarti != nullptr)
        {
            cout << endl << "Preturi carti: ";

            for (int i = 0; i < this->nrCarti; i++)           
            {
                cout << this->preturiCarti[i] << " lei ";
            }
        }           

        cout << endl;
    }
         


  
    // Operator <
    bool operator<(const Biblioteca& b)
    {
        return this->nrCarti < b.nrCarti;
    }
           
    // Destructor
    ~Biblioteca()
    {           
        cout << endl << "S-a apelat destructorul Biblioteca!";
        delete[] this->preturiCarti;
    }

    // Operator +=
    void operator+=(float bugetDeAdaugat)
    {
        this->bugetTotal += bugetDeAdaugat;
    }

    // Operator negatie
    bool operator!()
    {
        return this->bugetTotal > 0;
    }

    // Operator functie
    float operator()(float valoareDeAdaugat)
    {
        return this->bugetTotal + valoareDeAdaugat;
    }

    // Operator index
    float& operator[](int index)
    {
        if (index >= 0 && index < this->nrCarti
            && this->preturiCarti != nullptr)
        {
            return this->preturiCarti[index];
        }           
        else                                            
        {           
            throw exception();
        }                      
    }           
         


  
    // Operator <<
    friend ostream& operator<<(ostream& out, const Biblioteca& b)
    {                                 
        out << endl << "Operator de afisare:";
        out << endl << "Id: " << b.id;
        out << endl << "Denumire: " << b.denumire;           
        out << endl << "Buget total: " << b.bugetTotal;           

        out << endl << "Tip biblioteca: ";           
           
        if (b.tip == PUBLICA)
        {
            out << "PUBLICA";
        }
        else           
        {           
            out << "PRIVATA";           
        }           

        out << endl << "Numar carti: " << b.nrCarti;

        if (b.preturiCarti != nullptr && b.nrCarti > 0)
        {           
            out << endl << "Preturi carti: ";

            for (int i = 0; i < b.nrCarti; i++)
            {
                out << b.preturiCarti[i] << " lei ";
            }           
        }

        out << endl;

        return out;           
    }           



    // Operator >>
    friend istream& operator>>(istream& in, Biblioteca& b);           
      

                           
    // Postincrementare
    Biblioteca operator++(int)
    {
        Biblioteca copie = *this;
        this->bugetTotal++;
           
        return copie;
    }


    // Preincrementare
    Biblioteca operator++()
    {
        this->bugetTotal++;

        return *this;
    }


    // Cast explicit la int
    explicit operator int()
    {
        return this->nrCarti;
    }


};




// Operator >>  

                                          
istream& operator>>(istream& in, Biblioteca& b)
{           
    cout << endl << "Denumire: ";
    in >> b.denumire;
                                 
    cout << "Buget total: ";
    in >> b.bugetTotal;

    cout << "Tip (1-PUBLICA, 2-PRIVATA): ";           

    int tip;
    in >> tip;                                 

    if (tip == 1)
    {
        b.tip = PUBLICA;
    }
    else
    {
        b.tip = PRIVATA;
    }

    cout << "Numar carti: ";

    int nr;
    in >> nr;

    if (!in || nr < 0)
    {
        in.setstate(ios::failbit);
        return in;
    }

    float* preturi = nullptr;

    if (nr > 0)
    {
        preturi = new float[nr];

        for (int i = 0; i < nr; i++)
        {
            cout << "Pret carte " << i << ": ";
            in >> preturi[i];
        }
    }

    if (in)
    {
        b.setPreturiCarti(preturi, nr);
    }

    delete[] preturi;

    return in;
}

// Initializare atribut static
int Biblioteca::nrBiblioteci = 0;

// Functia main
int main()
{
    cout << "\n===== CONSTRUCTOR IMPLICIT =====";

    Biblioteca bibliotecaGenerala;                      
    bibliotecaGenerala.afisare();                      
                      
    cout << "\n===== OPERATOR ! =====";           
                                                       
    if (!bibliotecaGenerala)
    {
        cout << "\nBiblioteca are buget pozitiv!";                                            
    }           
    else
    {
        cout << "\nBiblioteca nu are buget pozitiv!";
    }           

    cout << "\n===== OPERATOR () =====";

    cout << "\nBuget dupa adaugare: "
        << bibliotecaGenerala(500);

    cout << "\n===== CONSTRUCTOR CU PARAMETRI =====";                      
           
    float* preturi = new float[3] {50, 80, 120};

    Biblioteca* bibliotecaBucuresti = new Biblioteca           
    (
        7,           
        "BibliotecaBucuresti",
        97000,           
        3,
        preturi,                      
        PUBLICA
    );



    delete[] preturi;

    bibliotecaBucuresti->afisare();



    cout << "\n===== OPERATOR += =====";
           
    (*bibliotecaBucuresti) += 1000;

    bibliotecaBucuresti->afisare();                      

  

  cout << "\n===== OPERATOR < =====";

    if (bibliotecaGenerala < *bibliotecaBucuresti)           
    {
        cout << "\nBiblioteca generala are mai putine carti!";
    }
    else           
    {
        cout << "\nBiblioteca Bucuresti are mai putine sau acelasi numar de carti!";
    }

    cout << "\n===== OPERATOR [] =====";           





    (*bibliotecaBucuresti)[0] = 60;

    cout << "\nPretul primei carti: "           
        << (*bibliotecaBucuresti)[0];                                 

    cout << "\n===== OPERATOR << =====";                                 
           
  

  cout << *bibliotecaBucuresti;                                 

    cout << "\n===== CONSTRUCTOR DE COPIERE =====";                                 



    Biblioteca bibliotecaCopie = *bibliotecaBucuresti;           

  

  cout << bibliotecaCopie;

    cout << "\n===== OPERATOR = =====";
                                                                  
    Biblioteca bibliotecaNoua;
                      
    bibliotecaNoua = *bibliotecaBucuresti;                      

    cout << bibliotecaNoua;
       
    
    cout << "\n===== GETTER =====";



    cout << "\nNumar carti: "
        << bibliotecaBucuresti->getNrCarti();

    cout << "\n===== SETTER =====";

    bibliotecaNoua.setNrCarti(3);



    cout << "\nNumar carti modificat: "    << bibliotecaNoua.getNrCarti();

    cout << "\n===== GETTER PRETURI =====";
                      
    float* preturiCopiate = bibliotecaBucuresti->getPreturiCarti();



    for (int i = 0; i < bibliotecaBucuresti->getNrCarti(); i++)                                 
    {
        cout << preturiCopiate[i] << " ";
    }           
           
  

  delete[] preturiCopiate;                                                       

    cout << "\n===== SETTER PRETURI =====";

    float preturiNoi[3] = {140, 160, 180};

    bibliotecaNoua.setPreturiCarti(preturiNoi, 3);

    bibliotecaNoua.afisare();

    cout << "\n===== POSTINCREMENTARE =====";

   

 Biblioteca bibliotecaPost = (*bibliotecaBucuresti)++;

    cout << "\nValoarea copiei:";                                                       
    cout << bibliotecaPost;
                      
    cout << "\nValoarea originalului:";           
    cout << *bibliotecaBucuresti;

    cout << "\n===== PREINCREMENTARE =====";           

    Biblioteca bibliotecaPre = ++(*bibliotecaBucuresti);

    cout << "\nValoarea copiei:";                                                       
    cout << bibliotecaPre;                                 
                                 
    cout << "\nValoarea originalului:";                                            
    cout << *bibliotecaBucuresti;                                 
                                 
    cout << "\n===== CAST EXPLICIT LA INT =====";                                 
                      
    cout << "\nNumar carti convertit la int: "                                                       
        << int(*bibliotecaBucuresti);                                                                  
                      
    cout << "\n===== OPERATOR >> =====";           
           
   

 Biblioteca bibliotecaCitita;                      
                                 
    // Pentru testarea citirii de la tastatura:                                 
    //           
    // cin >> bibliotecaCitita;                                 
    // cout << bibliotecaCitita;           
           
    cout << "\n===== NUMAR BIBLIOTECI =====";                                 
           
    cout << "\nNumar biblioteci create: "                                 
        << Biblioteca::nrBiblioteci;                                 
                                 
    cout << "\n===== DEALOCARE MEMORIE =====";           
                      
  


  delete bibliotecaBucuresti;                                            
                      
   
 cout << "\n===== SFARSIT PROGRAM =====";           

   

 return 0;

}        


              
