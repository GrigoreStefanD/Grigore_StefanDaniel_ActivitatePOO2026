// model dupa curs 
 // dezactivam anumite avertismente de securitate in compilatoarele compatibile
#define _CRT_SECURE_NO_WARNINGS_GLOBALS
// includem biblioteca pentru citire si afisare
#include <iostream>
// includem biblioteca pentru lucrul cu siruri de caractere
#include <string>
// includem biblioteca pentru tratarea exceptiilor
#include <stdexcept>
// permitem folosirea elementelor din spatiul standard fara prefixul std::
using namespace std;
//
// definim tipurile de locatie ale parcului auto
enum Locatie
{
    URBANA = 1,
    EXTRAURBANA = 2
};
//
class ParcAuto
{
private:
    // identificator constant al parcului
    const int id;


    // locatia parcului auto
    Locatie locatie;


    // denumirea parcului
    string denumire;

    // numarul de vehicule
    int nrVehicule;

    // lista dinamica de preturi
    float* preturi;


public:
    // numaram obiectele create
    static int nrParcuri;



    // constructor implicit
    ParcAuto() : id(++nrParcuri)
    {
        denumire = "parc auto general";
        locatie = URBANA;
        nrVehicule = 0;
        preturi = nullptr;
    }


    // constructor cu parametri
    ParcAuto(int id, string denumire, int nrVehicule,
             const float* preturi, Locatie locatie) : id(id)
    {
         
        if (nrVehicule < 0)
            throw invalid_argument("numarul de vehicule nu poate fi negativ");         

                                              
      
        if (nrVehicule > 0 && preturi == nullptr)
            throw invalid_argument("lista de preturi nu poate fi vida");          

        nrParcuri++;
      
        this->denumire = denumire;           
        this->locatie = locatie;          
        this->nrVehicule = nrVehicule;         
        this->preturi = nullptr;

        // copiem preturile in memoria proprie a obiectului
        if (nrVehicule > 0)
        {             
            this->preturi = new float[nrVehicule];

            for (int i = 0; i < nrVehicule; i++)           
                this->preturi[i] = preturi[i];                
        }

      
    }


    // constructor de copiere
    ParcAuto(const ParcAuto& copie) : id(++nrParcuri)
    {
        denumire = copie.denumire;
        locatie = copie.locatie;
        nrVehicule = copie.nrVehicule;
        preturi = nullptr;

        // cream o copie independenta a listei de preturi
        if (copie.preturi != nullptr && nrVehicule > 0)
        {
            preturi = new float[nrVehicule];

            for (int i = 0; i < nrVehicule; i++)
                preturi[i] = copie.preturi[i];
        }
    }


    // operator de atribuire
    ParcAuto& operator=(const ParcAuto& copie)
    {
        // evitam atribuirea obiectului catre el insusi
        if (this != &copie)
        {
            denumire = copie.denumire;
            locatie = copie.locatie;

            delete[] preturi;
            preturi = nullptr;
            nrVehicule = copie.nrVehicule;

            // copiem lista de preturi in memoria noului obiect
            if (copie.preturi != nullptr && nrVehicule > 0)
            {
                preturi = new float[nrVehicule];

                for (int i = 0; i < nrVehicule; i++)
                    preturi[i] = copie.preturi[i];
            }        
        }           

        return *this;           
    }            
           
                          
    // getter pentru numarul de vehicule
    int getNrVehicule() const
    {
        return nrVehicule;                                       
    }

    // setter pentru numarul de vehicule             
    void setNrVehicule(int valoareNoua)
    {
        if (valoareNoua < 0)
            throw invalid_argument("numarul de vehicule nu poate fi negativ");             
             
        if (valoareNoua != nrVehicule)
            throw invalid_argument("folositi setPreturi pentru a modifica lista");

        nrVehicule = valoareNoua;
    }                    

             
    // getter care returneaza o copie a preturilor
    float* getPreturi() const
    {             
        if (nrVehicule == 0 || preturi == nullptr)
            return nullptr;

      
        float* copiePreturi = new float[nrVehicule];

      
        for (int i = 0; i < nrVehicule; i++)
            copiePreturi[i] = preturi[i];

        return copiePreturi;
    }


    // setter pentru lista de preturi
    void setPreturi(const float* valori, int dimensiune)
    {
        if (dimensiune < 0)
            throw invalid_argument("dimensiunea nu poate fi negativa");

        if (dimensiune > 0 && valori == nullptr)
            throw invalid_argument("lista de preturi nu poate fi vida");                                       


                   
        // copiem datele inainte de a elibera vechea lista
        float* copieNoua = nullptr;
                                       
      
        if (dimensiune > 0)
        {
            copieNoua = new float[dimensiune];

          
            for (int i = 0; i < dimensiune; i++)
                copieNoua[i] = valori[i];
        }


      
        delete[] preturi;
        preturi = copieNoua;
        nrVehicule = dimensiune;
    }

    // afisam informatiile despre parc
    void afisare() const

    {
        cout << endl << "id: " << id;
        cout << endl << "denumire: " << denumire;                                                                 
        cout << endl << "locatie: ";             
             
        if (locatie == URBANA)                                                    
            cout << "urbana";
        else
            cout << "extraurbana";             
             
        cout << endl << "numar vehicule: " << nrVehicule;                                       

        if (nrVehicule > 0 && preturi != nullptr)                          
        {
            cout << endl << "preturi vehicule: ";                                                    

            // parcurgem lista pentru a afisa fiecare pret
            for (int i = 0; i < nrVehicule; i++)
            {
                cout << preturi[i] << " lei";

                if (i < nrVehicule - 1)
                    cout << ", ";
            }             
        }                          
             
        cout << endl << "-----------------------------" << endl;
    }

    // comparam parcurile dupa numarul de vehicule
    bool operator<(const ParcAuto& altParc) const                                                    
    {
        return nrVehicule < altParc.nrVehicule;
    }

    // destructorul elibereaza memoria alocata dinamic
    ~ParcAuto()
    {
        delete[] preturi;
        cout << "destructor apelat pentru parcul cu id " << id << endl;
    }                          
};
                                                    
// initializam atributul static                          
int ParcAuto::nrParcuri = 0;                          

int main()
{                                       
    try                                                    
    {
        // cream un parc cu valori implicite
        ParcAuto parcGeneral;             
        cout << "parc general" << endl;                                       
        parcGeneral.afisare();

        // cream un parc cu trei vehicule             
        float preturi[] = { 15000, 22000, 18500 };             

      
        ParcAuto parcCentral(             
            10,                                                    
            "parc auto central",                                                    
            3,             
            preturi,
            URBANA
        );


      
        cout << endl << "parc central" << endl;
        parcCentral.afisare();

        // testam constructorul de copiere
        ParcAuto parcCopie(parcCentral);
        cout << endl << "copie parc central" << endl;
        parcCopie.afisare();                                                    


      
        // testam operatorul de atribuire
        parcGeneral = parcCentral;
        cout << endl << "parc general dupa atribuire" << endl;
        parcGeneral.afisare();

        // cream un parc cu doua vehicule
        ParcAuto parcNou;
        float preturiNoi[] = { 9000, 12000 };
        parcNou.setPreturi(preturiNoi, 2);
                                                                 
        cout << endl << "parc nou" << endl;
        parcNou.afisare();


      
        // comparam numarul de vehicule din cele doua parcuri
        if (parcNou < parcCentral)
            cout << "parcul nou are mai putine vehicule decat parcul central" << endl;
        else
            cout << "parcul nou nu are mai putine vehicule decat parcul central" << endl;
                                                                 
        // obtinem o copie a listei de preturi
        float* listaPreturi = parcCentral.getPreturi();

        cout << endl << "preturi copiate: ";

                   
        for (int i = 0; i < parcCentral.getNrVehicule(); i++)
            cout << listaPreturi[i] << " lei ";

        cout << endl;

      
        // eliberam memoria returnata de getter
        delete[] listaPreturi;             

        // testam tratarea unei valori invalide
        try
                                                 
        {
            parcNou.setNrVehicule(-3);
        }                                       

          
        catch (const exception& e)
        {
            cout << "eroare: " << e.what() << endl;             
        }

      
        cout << endl << "numar parcuri create: "             
             << ParcAuto::nrParcuri << endl;
    }

      
    catch (const exception& e)
    {
      
        cout << "eroare in program: " << e.what() << endl;
        return 1;
    }                                       
  

    return 0;

  
}
