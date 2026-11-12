#define _CRT_SECURE_NO_WARNINGS            
#include <iostream> 
#include <string>      
#include <vector>
   

using namespace std;


enum ZonaHotel { CENTRALA = 1, PERIFERICA = 2 };             


class Hotel 
{
          

private:
    const int id;
    ZonaHotel zona;
    string denumire; 
    float incasariTotale;
    int nrCamere;   
    float* preturiCamere;

public:
    static int nrHoteluri;

    // Constructor implicit        
    Hotel() : id(++nrHoteluri)           

    {          

        this->denumire = "Hotel general";   
        this->incasariTotale = 0;          

        this->zona = PERIFERICA;     
        this->nrCamere = 0; 
        this->preturiCamere = nullptr;    
    }

    // Constructor cu parametri    
    Hotel(int id, string denumire, float incasariTotale, int nrCamere, float* preturiCamere, ZonaHotel zona)
        : id(id) 
    
    {
        nrHoteluri++;     

        this->denumire = denumire;     
        this->incasariTotale = incasariTotale;     
        this->zona = zona;
        this->nrCamere = nrCamere;

        if (nrCamere > 0 && preturiCamere != nullptr) 
        
        
        {  
            this->preturiCamere = new float[nrCamere];

            for (int i = 0; i < nrCamere; i++)          
            {
                this->preturiCamere[i] = preturiCamere[i];    
            }     
        }

        else                
        {
            this->nrCamere = 0;     
            this->preturiCamere = nullptr;     
        }
    }

    // Constructor de copiere    
    Hotel(const Hotel& copie) : id(++nrHoteluri) 
    
    {
        this->denumire = copie.denumire;
        this->incasariTotale = copie.incasariTotale;       
        this->zona = copie.zona;
        this->nrCamere = copie.nrCamere;           



        if (copie.preturiCamere != nullptr) 
        
        {     
            this->preturiCamere = new float[this->nrCamere];
               
            for (int i = 0; i < this->nrCamere; i++) 
            {
                this->preturiCamere[i] = copie.preturiCamere[i];
            }
        }
        else 
        {
            this->preturiCamere = nullptr;
        }
    }

    // Operator =    
    Hotel& operator=(const Hotel& copie) 
    {
        if (this != &copie) {
            this->denumire = copie.denumire;
            this->incasariTotale = copie.incasariTotale;
            this->zona = copie.zona;
            this->nrCamere = copie.nrCamere;

            delete[] this->preturiCamere;
            this->preturiCamere = nullptr;

            if (copie.preturiCamere != nullptr) 
            {
                this->preturiCamere = new float[this->nrCamere];

                for (int i = 0; i < this->nrCamere; i++) 
                {
                    this->preturiCamere[i] = copie.preturiCamere[i];     
                }


            }


        }

        return *this;

    }
     
    // Getter si setter pentru nrCamere    
    int getNrCamere() 
    {     
        return this->nrCamere;
    }
     


    void setNrCamere(int valoareNoua) 
    {
        if (valoareNoua >= 0)
        {
            this->nrCamere = valoareNoua;
        }
        else 
        {
            throw exception();
        }

    }



    // Getter pentru preturiCamere    
    float* getPreturiCamere()
    {
        if (this->preturiCamere == nullptr)
        {
            return nullptr;
        }

        float* copie = new float[this->nrCamere];

        for (int i = 0; i < this->nrCamere; i++)
        {
            copie[i] = this->preturiCamere[i];
        }

        return copie;


    }



    // Setter pentru preturiCamere    
    void setPreturiCamere(float* preturi, int dim)          
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

        delete[] this->preturiCamere;
        this->preturiCamere = copie;
        this->nrCamere = dim;
    }     
     



    // Metoda de afisare    
    void afisare() 
    
    {
        cout << endl << "Id: " << this->id;     
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Incasari totale: " << this->incasariTotale;     

        cout << endl << "Zona: ";


        if (this->zona == CENTRALA) 
        {
            cout << "CENTRALA";
        }


        else      
        {
            cout << "PERIFERICA";
        }


        cout << endl << "Numar camere: " << this->nrCamere;     
          

        if (this->nrCamere > 0 && this->preturiCamere != nullptr)      
        {          
            cout << endl << "Preturi camere: ";
     
     
            for (int i = 0; i < this->nrCamere; i++)      
            {
                cout << this->preturiCamere[i] << " lei ";
            }


        }
     
        cout << endl;          


    }                              
     


    // Operator <    
    bool operator<(const Hotel& h)                     
    
    {
        return this->nrCamere < h.nrCamere;
    }     


          
    // Destructor         
    ~Hotel()      
    {
        cout << endl << "S-a apelat destructorul Hotel!";
        delete[] this->preturiCamere;
    }     



    // Operator +=    
    void operator+=(float incasariDeAdaugat) 
    
    {
        this->incasariTotale += incasariDeAdaugat;
    }     



    // Operator negatie    
    bool operator!() 
    
    {
        return this->incasariTotale > 0;
    }



    // Operator functie    
    float operator()(float valoareDeAdaugat) 
    
    {     
        return this->incasariTotale + valoareDeAdaugat;
    }



    // Operator index    
    float& operator[](int index) 
    {
        if (index >= 0 && index < this->nrCamere
            && this->preturiCamere != nullptr)      
        {
            return this->preturiCamere[index];
        }
        else 
        {
            throw exception();
        }

     
    }



    // Operator <<    
    friend ostream& operator<<(ostream& out, const Hotel& h)
    
    {
        out << endl << "Operator de afisare:";
        out << endl << "Id: " << h.id;
        out << endl << "Denumire: " << h.denumire;
        out << endl << "Incasari totale: " << h.incasariTotale;

        out << endl << "Zona: ";

        if (h.zona == CENTRALA)      
        {
            out << "CENTRALA";
        }     



        else 
        
        {
            out << "PERIFERICA";
        }


        out << endl << "Numar camere: " << h.nrCamere;

        if (h.preturiCamere != nullptr && h.nrCamere > 0) 
        
        {     
            out << endl << "Preturi camere: ";

            for (int i = 0; i < h.nrCamere; i++)
            {
                out << h.preturiCamere[i] << " lei ";
            }


        }



        out << endl;


        return out;

     
    }


    // Operator >>    
    friend istream& operator>>(istream& in, Hotel& h);




    // Postincrementare    
    Hotel operator++(int) 
    {
        Hotel copie = *this;
        this->incasariTotale++;

        return copie;                                                                                                              
    }



    // Preincrementare    
    Hotel operator++()
    {
        this->incasariTotale++;
                                                                      
        return *this;
    }


                                                                                

    // Cast explicit la int    
    explicit operator int() 
    {
        return this->nrCamere;
    }


};


// Operator >>    
istream& operator>>(istream& in, Hotel& h) 
                                                  
{
    cout << endl << "Denumire: ";
    in >> h.denumire;

    cout << "Incasari totale: ";     
    in >> h.incasariTotale;

    cout << "Zona (1-CENTRALA, 2-PERIFERICA): ";                                             
     
    int zona;
    in >> zona;
                                                                      
    if (zona == 1)          
    {
        h.zona = CENTRALA;
    }


    else 
    {
        h.zona = PERIFERICA;                                                                           
    }

    cout << "Numar camere: ";

    int nr;     
    in >> nr;


    if (!in || nr < 0) 
                                                           
    {
        in.setstate(ios::failbit);
        return in;     
    }
     
                                                                                          

    float* preturi = nullptr;
                         

    if (nr > 0) {     
        preturi = new float[nr];

     

        for (int i = 0; i < nr; i++) {
            cout << "Pret camera " << i << ": ";
            in >> preturi[i];
        }                                                                                     


    }



    h.setPreturiCamere(preturi, nr);
     
    delete[] preturi;
     
    return in;                                                                 
     
                              

}
     
     


// Initializare atribut static    
int Hotel::nrHoteluri = 0;





// Functia main    
int main() 

{                                                                                                                                                                

    cout << "\n===== CONSTRUCTOR IMPLICIT =====";
                                                                      

    Hotel hotelGeneral;
    hotelGeneral.afisare();

    cout << "\n===== OPERATOR ! =====";

    if (!hotelGeneral) 
    
    {
        cout << "\nHotelul are incasari pozitive!";
    }
    else 
    {
        cout << "\nHotelul nu are incasari pozitive!";
    }


    cout << "\n===== OPERATOR () =====";                                                                      

    cout << "\nIncasari dupa adaugare: " << hotelGeneral(500);

    cout << "\n===== CONSTRUCTOR CU PARAMETRI =====";

    float* preturi = new float[3] {250, 350, 450};

                                                                                     

    Hotel* hotelBucuresti = new Hotel               
    (
        7,
        "HotelBucuresti",
        97000,
        3,
        preturi,                                                                                          
        CENTRALA
    );



                                        
    delete[] preturi;

    hotelBucuresti->afisare();


    cout << "\n===== OPERATOR += =====";                                                                                

    (*hotelBucuresti) += 1000;

    hotelBucuresti->afisare();
                                                                                                    




    cout << "\n===== OPERATOR < =====";


    if (hotelGeneral < *hotelBucuresti)
    {
        cout << "\nHotelul general are mai putine camere!";
    }
    else 
    {
        cout << "\nHotelul Bucuresti are mai multe sau acelasi numar de camere!";
    }


    cout << "\n===== OPERATOR [] =====";

    (*hotelBucuresti)[0] = 300;

    cout << "\nPretul primei camere: " << (*hotelBucuresti)[0];
     
    cout << "\n===== OPERATOR << =====";

    cout << *hotelBucuresti;

    cout << "\n===== CONSTRUCTOR DE COPIERE =====";     

    Hotel hotelCopie = *hotelBucuresti;

    cout << hotelCopie;

    cout << "\n===== OPERATOR = =====";
                                                                                               
     

    Hotel hotelNou;

    hotelNou = *hotelBucuresti;


     
    cout << hotelNou;     

    cout << "\n===== GETTER =====";     
     
    cout << "\nNumar camere: " << hotelBucuresti->getNrCamere();

    cout << "\n===== SETTER =====";     
     
    hotelNou.setNrCamere(3);

     
    cout << "\nNumar camere modificat: " << hotelNou.getNrCamere();
     
    cout << "\n===== GETTER PRETURI =====";

     

    float* preturiCopiate = hotelBucuresti->getPreturiCamere();
     
    for (int i = 0; i < hotelBucuresti->getNrCamere(); i++) 
    {
        cout << preturiCopiate[i] << " ";
    }



    delete[] preturiCopiate;

    cout << "\n===== SETTER PRETURI =====";     
               
    float preturiNoi[3] = { 400, 500, 600 };     

    hotelNou.setPreturiCamere(preturiNoi, 3);

    hotelNou.afisare();

          

    cout << "\n===== POSTINCREMENTARE =====";     


    Hotel hotelPost = (*hotelBucuresti)++;


    cout << "\nValoarea copiei:";
    cout << hotelPost;
     

     
    cout << "\nValoarea originalului:";
    cout << *hotelBucuresti;



    cout << "\n===== PREINCREMENTARE =====";
     
     
    Hotel hotelPre = ++(*hotelBucuresti);


    cout << "\nValoarea copiei:";     
    cout << hotelPre;     



    cout << "\nValoarea originalului:";
    cout << *hotelBucuresti;
     

    cout << "\n===== CAST EXPLICIT LA INT =====";


    cout << "\nNumar camere convertit la int: " << int(*hotelBucuresti);


    cout << "\n===== OPERATOR >> =====";

     
    Hotel hotelCitit;

     


    // Pentru testarea citirii de la tastatura:     
    // 
    // cin >> hotelCitit;
    // cout << hotelCitit;                                                                                          



    cout << "\n===== NUMAR HOTELURI =====";
     
    cout << "\nNumar hoteluri create: " << Hotel::nrHoteluri;     
          
    cout << "\n===== DEALOCARE MEMORIE =====";     

    delete hotelBucuresti;



    cout << "\n===== SFARSIT PROGRAM =====";


    return 0;

}






