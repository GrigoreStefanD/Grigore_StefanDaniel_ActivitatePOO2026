 

       
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>     
#include <string>        
#include <exception>

using namespace std; 

enum TipDrona { CIVILA = 1, MILITARA = 2 };


class DronaCartografiere
{
private:
    const int id; 
    TipDrona tip;
    string denumire;
    float buget;      
    int nrSenzori;
    float* preciziiSenzori;    
    int autonomieZbor;
      

              
public:

    static int nrDrone;



    // Constructor implicit           
    DronaCartografiere() : id(++nrDrone)             
    {
        this->denumire = "Drona generala";
        this->buget = 0;
        this->tip = CIVILA;            
        this->nrSenzori = 0;
        this->preciziiSenzori = nullptr;           
        this->autonomieZbor = 30;
            
    }


    // Constructor cu parametri               
    DronaCartografiere(int id, string denumire, float buget,  int nrSenzori, float* preciziiSenzori,  TipDrona tip, int autonomieZbor)  : id(id)
    {
        nrDrone++;        



        this->denumire = denumire;   
        this->buget = buget;
        this->tip = tip;          
        this->autonomieZbor = autonomieZbor;          

        if (nrSenzori > 0 && preciziiSenzori != nullptr)
        {
            this->nrSenzori = nrSenzori;           
            this->preciziiSenzori = new float[nrSenzori];


            for (int i = 0; i < nrSenzori; i++)             
            {
                this->preciziiSenzori[i] = preciziiSenzori[i];
            }

        }  

           
        else
        {
            this->nrSenzori = 0;
            this->preciziiSenzori = nullptr;
        }

    }




    // Constructor de copiere
    DronaCartografiere(const DronaCartografiere& copie) : id(++nrDrone)   
    { 
        this->denumire = copie.denumire;      
        this->buget = copie.buget;         
        this->tip = copie.tip;        
        this->nrSenzori = copie.nrSenzori;
        this->autonomieZbor = copie.autonomieZbor;
   

        if (copie.preciziiSenzori != nullptr)
        {
            this->preciziiSenzori = new float[this->nrSenzori];


            for (int i = 0; i < this->nrSenzori; i++)
            {
                this->preciziiSenzori[i] =
                    copie.preciziiSenzori[i];
            } 
 


        }


        else
        {
            this->preciziiSenzori = nullptr;
        }


    }




    // Operator =
    DronaCartografiere& operator=(const DronaCartografiere& copie)
    {
        if (this != &copie)
        {
            this->denumire = copie.denumire;
            this->buget = copie.buget;
            this->tip = copie.tip;
            this->autonomieZbor = copie.autonomieZbor;

            float* vectorNou = nullptr;

            if (copie.preciziiSenzori != nullptr)
            {
                vectorNou = new float[copie.nrSenzori];


                for (int i = 0; i < copie.nrSenzori; i++)
                {
                    vectorNou[i] = copie.preciziiSenzori[i];
                }


            }


            delete[] this->preciziiSenzori;

            this->preciziiSenzori = vectorNou;
            this->nrSenzori = copie.nrSenzori;
        }

        return *this;


    }




    // Getter pentru nrSenzori
    int getNrSenzori()
    {
        return this->nrSenzori;
    }




    // Setter pentru nrSenzori
    void setNrSenzori(int valoareNoua)
    {
        if (valoareNoua < 0)
        {
            throw exception();
        }



        float* vectorNou = nullptr;

        if (valoareNoua > 0)
        {
            vectorNou = new float[valoareNoua]();

            int limita = valoareNoua < this->nrSenzori
                ? valoareNoua : this->nrSenzori;

            for (int i = 0; i < limita; i++)
            {
                vectorNou[i] = this->preciziiSenzori[i];
            }

        }


        delete[] this->preciziiSenzori;                      

        this->preciziiSenzori = vectorNou;                      
        this->nrSenzori = valoareNoua;

    }
         



                                                         
    // Getter pentru preciziiSenzori
    float* getPreciziiSenzori()                                                                  
    {                      
        if (this->preciziiSenzori == nullptr)
        {                      
            return nullptr;
        }                      

        float* copie = new float[this->nrSenzori];

        for (int i = 0; i < this->nrSenzori; i++)
        {                                                           
            copie[i] = this->preciziiSenzori[i];
        }

        return copie;

    }




    // Setter pentru preciziiSenzori
    void setPreciziiSenzori(float* valori, int dim)
    {
        if (dim < 0 || (dim > 0 && valori == nullptr))
        {
            throw exception();
        }

        float* copie = nullptr;

        if (dim > 0)
        {
            copie = new float[dim];

            for (int i = 0; i < dim; i++)
            {
                copie[i] = valori[i];
            }


        }
                      
        delete[] this->preciziiSenzori;                      
                      
        this->preciziiSenzori = copie;                      
        this->nrSenzori = dim; 

                     
    }                                            



    // Getter pentru autonomieZbor                      
    int getAutonomieZbor()                      
    {                                            
        return this->autonomieZbor;
    }                      



    // Setter pentru autonomieZbor                      
    void setAutonomieZbor(int valoareNoua)                      
    {
        if (valoareNoua >= 0)                      
        {
            this->autonomieZbor = valoareNoua;                      
        }

        else
        {
            throw exception();
        }


    }



    // Metoda de afisare
    void afisare()
    {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Buget: " << this->buget;

        cout << endl << "Tip drona: ";

        if (this->tip == CIVILA)
        {
            cout << "CIVILA";
        }

        else

        {
            cout << "MILITARA";
        }

        cout << endl << "Numar senzori: " << this->nrSenzori;

        if (this->nrSenzori > 0 &&
            this->preciziiSenzori != nullptr)

        {
            cout << endl << "Precizii senzori: ";

            for (int i = 0; i < this->nrSenzori; i++)
            {
                cout << this->preciziiSenzori[i] << " ";
            }


        }

        cout << endl << "Autonomie zbor: "
            << this->autonomieZbor << " minute";

        cout << endl;


    }




    // Operator <
    bool operator<(const DronaCartografiere& d)
    {
        return this->nrSenzori < d.nrSenzori;
    }




    // Destructor
    ~DronaCartografiere()
    {
        cout << endl << "S-a apelat destructorul DronaCartografiere!";
        delete[] this->preciziiSenzori;
    }



    // Operator +=
    void operator+=(float bugetDeAdaugat)                      
    {                      
        this->buget += bugetDeAdaugat;                      
    }
      

                
    // Operator negatie                      
    bool operator!()                      
    {                      
        return this->buget <= 0;                      
    }
     

                 
    // Operator functie                      
    float operator()(float valoareDeAdaugat)                      
    {                      
        return this->buget + valoareDeAdaugat;                      
    }
     

                                                             
    // Operator index                      
    float& operator[](int index)                      
    {                                            
        if (index >= 0 && index < this->nrSenzori &&
            this->preciziiSenzori != nullptr)                      
        {                                                                  
            return this->preciziiSenzori[index];
        }                                            
        else                      
        {                      
            throw exception();                      
        }

    }



    // Operator <<
    friend ostream& operator<<(ostream& out,                      
        const DronaCartografiere& d)
    {
        out << endl << "Operator de afisare:";                      
        out << endl << "Id: " << d.id;                                            
        out << endl << "Denumire: " << d.denumire;                      
        out << endl << "Buget: " << d.buget;                      
                      
        out << endl << "Tip drona: ";
          
            
        if (d.tip == CIVILA)
        {
            out << "CIVILA";
        }   

                   
        else

        {
            out << "MILITARA";
        }
                      
        out << endl << "Numar senzori: " << d.nrSenzori;

        if (d.preciziiSenzori != nullptr && d.nrSenzori > 0)
        {
            out << endl << "Precizii senzori: ";

            for (int i = 0; i < d.nrSenzori; i++)
            {
                out << d.preciziiSenzori[i] << " ";                      
            }

        }



        out << endl << "Autonomie zbor: "
            << d.autonomieZbor << " minute";

        out << endl;

        return out;

                                                                                        
    }








    // Operator >>
    friend istream& operator>>(istream& in,
        DronaCartografiere& d);

    // Postincrementare
    DronaCartografiere operator++(int)
    {
        DronaCartografiere copie = *this;

        this->buget++;

        return copie;
    }




    // 
//Preincrementare
    DronaCartografiere operator++()
    {
        this->buget++;

        return *this;
    }




    // Cast explicit la int
    explicit operator int()
    {
        return this->nrSenzori;
    }

};





// Operator >>

istream& operator>>(istream& in, DronaCartografiere& d)
{
    cout << endl << "Denumire: ";
    in >> d.denumire;

    cout << "Buget: ";
    in >> d.buget;

    cout << "Tip (1-CIVILA, 2-MILITARA): ";

    int tip;                      
    in >> tip;

    if (!in || (tip != 1 && tip != 2))
    {
        in.setstate(ios::failbit);
        return in;
    }
                      
    d.tip = (TipDrona)tip;

    cout << "Autonomie zbor (minute): ";
    int autonomie;
    in >> autonomie;


    if (!in || autonomie < 0)
    {                      
        in.setstate(ios::failbit);
        return in;
    }

    d.setAutonomieZbor(autonomie);

    cout << "Numar senzori: ";                      

    int nr;
    in >> nr;


    if (!in || nr < 0)
    {
        in.setstate(ios::failbit);
        return in;
    }


    float* precizii = nullptr;

    if (nr > 0)
    {
        precizii = new float[nr];

        for (int i = 0; i < nr; i++)
        {
            cout << "Precizia senzorului " << i << ": ";
            in >> precizii[i];

            if (!in)
            {
                delete[] precizii;
                return in;
            }

        }

    }



    d.setPreciziiSenzori(precizii, nr);

    delete[] precizii;



    return in;


}





// Initializare atribut static
int DronaCartografiere::nrDrone = 0;







// Functia main
int main()
{
    cout << "\n===== CONSTRUCTOR IMPLICIT =====";

    DronaCartografiere dronaGenerala;

    dronaGenerala.afisare();

    cout << "\n===== OPERATOR ! =====";

    if (!dronaGenerala)
    {
        cout << "\nDrona nu are buget disponibil!";
    }
    else
    {
        cout << "\nDrona are buget disponibil!";
    }



    cout << "\n===== OPERATOR () =====";

    cout << "\nBuget dupa adaugare: "                                                                  
        << dronaGenerala(500);
                      
    cout << "\n===== CONSTRUCTOR CU PARAMETRI =====";                      
                      
    float* precizii = new float[3] {95.5, 87.3, 99.2};                                                                  




    DronaCartografiere* dronaMapare = new DronaCartografiere                                                                  
    (
        7,
        "AeroMapperX",                                                                  
        25000,                      
        3,
        precizii,
        CIVILA,                      
        45                      
    );                      

    delete[] precizii;                                            
                                            
    dronaMapare->afisare();

    cout << "\n===== OPERATOR += =====";                                            

    (*dronaMapare) += 3000;
                      
    dronaMapare->afisare();                      

    cout << "\n===== OPERATOR < =====";                                            
      

                
    if (dronaGenerala < *dronaMapare)                      
    {
        cout << "\nDrona generala are mai putini senzori!";
    }
    else                      
    {                                                                  
        cout << "\nDrona generala are acelasi numar sau mai multi senzori!";                                                                  
    }                                            

    cout << "\n===== OPERATOR [] =====";                                                                  




    (*dronaMapare)[0] = 96.8;
                      
    cout << "\nPrecizia primului senzor: "                      
        << (*dronaMapare)[0];                      
                      
    cout << "\n===== OPERATOR << =====";

    cout << *dronaMapare;
                                            
    cout << "\n===== CONSTRUCTOR DE COPIERE =====";                      



    DronaCartografiere dronaCopie = *dronaMapare;
                      
    cout << dronaCopie;

    cout << "\n===== OPERATOR = =====";
                                                                                                              
    DronaCartografiere dronaNoua;
                                                                  
    dronaNoua = *dronaMapare;
                                                                                        
    cout << dronaNoua;

    cout << "\n===== GETTER NR SENZORI =====";
                                                                                                                                                                                                                                                                                                                                                                
    cout << "\nNumar senzori: "
        << dronaMapare->getNrSenzori();

    cout << "\n===== SETTER NR SENZORI =====";

    dronaNoua.setNrSenzori(3);                                                                  



    cout << "\nNumar senzori modificat: "
        << dronaNoua.getNrSenzori();

    cout << "\n===== GETTER PRECIZII =====";        
                                                                                            
    float* preciziiCopiate = dronaMapare->getPreciziiSenzori();        


    for (int i = 0; i < dronaMapare->getNrSenzori(); i++)                                                    
    {                                                                                                              
        cout << preciziiCopiate[i] << " ";           
    }

    delete[] preciziiCopiate;                                                                               

    cout << "\n===== SETTER PRECIZII =====";                                                                          
         
    float preciziiNoi[3] = {91.5, 94.2, 98.7};

    dronaNoua.setPreciziiSenzori(preciziiNoi, 3);                                                                                 


    dronaNoua.afisare();

    cout << "\n===== GETTER AUTONOMIE =====";                                                                                        

    cout << "\nAutonomie zbor: "                                                                  
        << dronaMapare->getAutonomieZbor()
        << " minute";

    cout << "\n===== SETTER AUTONOMIE =====";

    dronaNoua.setAutonomieZbor(60);                                            



    cout << "\nAutonomie modificata: "
        << dronaNoua.getAutonomieZbor()
        << " minute";

    cout << "\n===== POSTINCREMENTARE =====";




    DronaCartografiere dronaPost = (*dronaMapare)++;                                                                  

    cout << "\nValoarea copiei:";
    cout << dronaPost;

    cout << "\nValoarea originalului:";
    cout << *dronaMapare;

    cout << "\n===== PREINCREMENTARE =====";

    DronaCartografiere dronaPre = ++(*dronaMapare);

    cout << "\nValoarea copiei:";                                                                                                              
    cout << dronaPre;

    cout << "\nValoarea originalului:";
    cout << *dronaMapare;

    cout << "\n===== CAST EXPLICIT LA INT =====";

    cout << "\nNumar senzori convertit la int: "
        << int(*dronaMapare);

    cout << "\n===== OPERATOR >> =====";




    DronaCartografiere dronaCitita;
//
    // Pentru testarea citirii de la tastatura:
    //
    // cin >> dronaCitita;
    // cout << dronaCitita;
///
//


    cout << "\n===== NUMAR DRONE =====";


    cout << "\nNumar drone create: "
        << DronaCartografiere::nrDrone;



    cout << "\n===== DEALOCARE MEMORIE =====";

    delete dronaMapare;


    cout << "\n===== SFARSIT PROGRAM =====";

                       
    return 0;

   
}


      


              
