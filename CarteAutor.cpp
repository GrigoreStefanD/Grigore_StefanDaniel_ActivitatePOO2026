#define _CRT_SECURE_NO_WARNINGS                                                                      
                    


#include <iostream>   
#include <string>                                 
#include <cstring>   
using namespace std;                          



class Carte
{ 


private:
 
    // Atribute simple          
    int cod; 
    int nrPagini;                                              
    float rating; 
    double pret;                                          
    char editie;                                              
    bool disponibila;  
    string titlu; 
    string autor;          

    // Vector static             
    int capitole[5];     
     
    // Sir static     
    char editura[30];

    // Vector dinamic
    float* preturiVechi;
    int nrPreturi;                                                  
                                        
    // Sir dinamic
    char* gen;

    // Atribut constant                                                            
    const int anCatalogare;

    // Atribut static                                   
    static int nrCarti;

public:


                                                                                               
    // Constructor fara parametri

   Carte() : anCatalogare(2026)
    {                                                            
        this->cod = 0;
        this->nrPagini = 0;                                                            
        this->rating = 0;                                                                                               
        this->pret = 0;                                                            
        this->editie = 'A';
        this->disponibila = true;                                             
        this->titlu = "Necunoscut";                                                            
        this->autor = "Necunoscut";                                                       

        for (int i = 0; i < 5; i++)                                   
            this->capitole[i] = 0;

        strcpy(this->editura, "Necunoscuta");
                                                  
        this->preturiVechi = nullptr;                                                                 
        this->nrPreturi = 0;

        this->gen = new char[1];
        this->gen[0] = '\0';                                                                                                    

        nrCarti++;


    }




                                   
    // Constructor cu parametri
    Carte(int cod, int nrPagini, float rating, double pret, char editie, bool disponibila, string titlu, string autor, int capitole[], const char* editura,float preturi[], int nrPreturi,const char* gen)   : anCatalogare(2026)
    {
        this->cod = cod > 0 ? cod : 0;
        this->nrPagini = nrPagini > 0 ? nrPagini : 0;
        this->rating = rating >= 0 && rating <= 10 ? rating : 0;                                             
        this->pret = pret >= 0 ? pret : 0;
        this->editie = editie;     
        this->disponibila = disponibila;

        this->titlu = titlu.empty() ? "Necunoscut" : titlu;                                   
        this->autor = autor.empty() ? "Necunoscut" : autor;


        // Copiem vectorul static                                                  
        for (int i = 0; i < 5; i++)
        {     
            this->capitole[i] = capitole != nullptr
                ? capitole[i] : 0;                                                       
        }
     


        // Copiem editura
        if (editura != nullptr)
        {
            strncpy(this->editura, editura, 29);
            this->editura[29] = '\0';
        }

        else
                                                  
            strcpy(this->editura, "Necunoscuta");                                                  


        // Alocam vectorul dinamic                                   
        this->nrPreturi =
            (nrPreturi > 0 && preturi != nullptr) ? nrPreturi : 0;
                                                                 
        if (this->nrPreturi > 0)

        {                                                       
            this->preturiVechi = new float[this->nrPreturi];

            for (int i = 0; i < this->nrPreturi; i++)
                this->preturiVechi[i] = preturi[i];
        }

        else
            this->preturiVechi = nullptr;




        // Alocam sirul dinamic
        if (gen != nullptr)
        {     
            this->gen = new char[strlen(gen) + 1];                                                                                                                                       
            strcpy(this->gen, gen);
        }
        else
        {                                                                                               
            this->gen = new char[1];
            this->gen[0] = '\0';                                                                                                              
        }

        nrCarti++;

    }




    // Constructor de copiere
    Carte(const Carte& c) : anCatalogare(c.anCatalogare)                                                                                          
    {
        this->cod = c.cod;
        this->nrPagini = c.nrPagini;                                                                                          
        this->rating = c.rating;
        this->pret = c.pret;                                                                                                         
        this->editie = c.editie;
        this->disponibila = c.disponibila;
        this->titlu = c.titlu;                                                                                               
        this->autor = c.autor;



        // Copiem vectorul static
        for (int i = 0; i < 5; i++)                                                                           
            this->capitole[i] = c.capitole[i];
     
        strcpy(this->editura, c.editura);

     

        // Copiem vectorul dinamic
        this->nrPreturi = c.nrPreturi;

        if (this->nrPreturi > 0)
        {
            this->preturiVechi = new float[this->nrPreturi];

            for (int i = 0; i < this->nrPreturi; i++)
                this->preturiVechi[i] = c.preturiVechi[i];                                                                      
        }
        else
            this->preturiVechi = nullptr;



        // Copiem sirul dinamic                                                                                               
        this->gen = new char[strlen(c.gen) + 1];
        strcpy(this->gen, c.gen);                                                            

        nrCarti++;
    }



    // Operator =
    Carte& operator=(const Carte& c)
    {
        if (this != &c)
        {
            this->cod = c.cod;                                                            
            this->nrPagini = c.nrPagini;                                                                                          
            this->rating = c.rating;
            this->pret = c.pret;
            this->editie = c.editie;                                                            
            this->disponibila = c.disponibila;
            this->titlu = c.titlu;                                                  
            this->autor = c.autor;
                                                                      
            for (int i = 0; i < 5; i++)
                this->capitole[i] = c.capitole[i];

            strcpy(this->editura, c.editura);



            // Stergem memoria veche
            delete[] this->preturiVechi;
            delete[] this->gen;


            // Copiem vectorul dinamic
            this->nrPreturi = c.nrPreturi;

            if (this->nrPreturi > 0)
            {                                                                                                    
                this->preturiVechi = new float[this->nrPreturi];

                for (int i = 0; i < this->nrPreturi; i++)
                    this->preturiVechi[i] = c.preturiVechi[i];
            }
            else
                this->preturiVechi = nullptr;



            // Copiem sirul dinamic
            this->gen = new char[strlen(c.gen) + 1];
            strcpy(this->gen, c.gen);
        }


        return *this;

    }                                             



    // Destructor
    ~Carte()
    {
        delete[] this->preturiVechi;
        delete[] this->gen;

        nrCarti--;

    }                    



    // Getteri
    int getCod() const { return this->cod; }
    int getNrPagini() const { return this->nrPagini; }                                                                           
    float getRating() const { return this->rating; }
    double getPret() const { return this->pret; }
    char getEditie() const { return this->editie; }
    bool getDisponibila() const { return this->disponibila; }
    string getTitlu() const { return this->titlu; }
    string getAutor() const { return this->autor; }
    int getAnCatalogare() const { return this->anCatalogare; }
    static int getNrCarti() { return nrCarti; }


    int getCapitol(int pozitie) const
    {
        if (pozitie >= 0 && pozitie < 5)
            return this->capitole[pozitie];

        return -1;
    }

    const char* getEditura() const
    {
        return this->editura;
    }

    const char* getGen() const
    {
        return this->gen;
    }

    float getPretVechi(int pozitie) const
    {
        if (pozitie >= 0 && pozitie < this->nrPreturi)
            return this->preturiVechi[pozitie];

        return -1;
    }


    int getNrPreturi() const
    {
        return this->nrPreturi;
    }

    // Setteri cu validare
    void setCod(int cod)
    {
        if (cod > 0)
            this->cod = cod;
        else
            cout << "Cod invalid!\n";
    }



    void setNrPagini(int nrPagini)
    {
        if (nrPagini > 0)
            this->nrPagini = nrPagini;
        else
            cout << "Numar pagini invalid!\n";
    }

    void setRating(float rating)
    {
        if (rating >= 0 && rating <= 10)
            this->rating = rating;
        else
            cout << "Rating invalid!\n";
    }

    void setPret(double pret)
    {
        if (pret >= 0)
            this->pret = pret;
        else
            cout << "Pret invalid!\n";
    }

    void setEditie(char editie)
    {
        if (editie >= 'A' && editie <= 'Z')
            this->editie = editie;
        else
            cout << "Editie invalida!\n";
    }

    void setDisponibila(bool disponibila)
    {
        this->disponibila = disponibila;
    }

    void setTitlu(string titlu)
    {
        if (!titlu.empty())
            this->titlu = titlu;
        else
            cout << "Titlu invalid!\n";
    }

    void setAutor(string autor)
    {
        if (!autor.empty())
            this->autor = autor;
        else
            cout << "Autor invalid!\n";
    }

    void setCapitol(int pozitie, int valoare)
    {
        if (pozitie >= 0 && pozitie < 5 && valoare > 0)
            this->capitole[pozitie] = valoare;
        else
            cout << "Capitol invalid!\n";
    }

    void setPretVechi(int pozitie, float valoare)
    {
        if (pozitie >= 0 && pozitie < this->nrPreturi && valoare >= 0)
            this->preturiVechi[pozitie] = valoare;
        else
            cout << "Pret invalid!\n";
    }




    // Operator de afisare
    friend ostream& operator<<(ostream& out, const Carte& c)

    {
        out << "\n===== CARTE =====\n";
        out << "Cod: " << c.cod << endl;
        out << "Titlu: " << c.titlu << endl;
        out << "Autor: " << c.autor << endl;
        out << "Pagini: " << c.nrPagini << endl;
        out << "Rating: " << c.rating << endl;
        out << "Pret: " << c.pret << endl;
        out << "Editie: " << c.editie << endl;
        out << "Disponibila: " << c.disponibila << endl;
        out << "Editura: " << c.editura << endl;
        out << "Gen: " << c.gen << endl;
        out << "An catalogare: " << c.anCatalogare << endl;

        out << "Capitole: ";
        for (int i = 0; i < 5; i++)
            out << c.capitole[i] << " ";

        out << "\nPreturi vechi: ";
        for (int i = 0; i < c.nrPreturi; i++)
            out << c.preturiVechi[i] << " ";

        out << endl;
        return out;
    }



    // Operator de citire
    friend istream& operator>>(istream& in, Carte& c)

    {

        cout << "Cod: ";
        in >> c.cod;

        while (c.cod <= 0)
        {
            cout << "Cod invalid: ";
            in >> c.cod;
        }

        cout << "Titlu: ";
        in >> ws;
        getline(in, c.titlu);

        cout << "Autor: ";
        getline(in, c.autor);

        cout << "Numar pagini: ";
        in >> c.nrPagini;

        while (c.nrPagini <= 0)
        {
            cout << "Numar invalid: ";
            in >> c.nrPagini;
        }

        cout << "Rating: ";
        in >> c.rating;

        while (c.rating < 0 || c.rating > 10)
        {
            cout << "Rating invalid: ";
            in >> c.rating;
        }

        cout << "Pret: ";
        in >> c.pret;

        while (c.pret < 0)
        {
            cout << "Pret invalid: ";
            in >> c.pret;
        }

        cout << "Editie: ";
        in >> c.editie;

        cout << "Disponibila (0/1): ";
        in >> c.disponibila;

        cout << "Editura: ";
        in >> ws;
        in.getline(c.editura, 30);

        cout << "Gen: ";
        string genNou;
        getline(in, genNou);

        delete[] c.gen;
        c.gen = new char[genNou.length() + 1];
        strcpy(c.gen, genNou.c_str());

        cout << "Capitole (5 valori): ";


        for (int i = 0; i < 5; i++)
        {
            in >> c.capitole[i];

            while (c.capitole[i] <= 0)
            {
                cout << "Valoare invalida: ";
                in >> c.capitole[i];
            }

        }

        int n;

        cout << "Numar preturi vechi: ";
        in >> n;

        while (n < 0 || n > 100)
        {
            cout << "Numar invalid: ";
            in >> n;
        }



        delete[] c.preturiVechi;
        c.preturiVechi = nullptr;
        c.nrPreturi = n;

        if (n > 0)
        {
            c.preturiVechi = new float[n];

            for (int i = 0; i < n; i++)
            {
                cout << "Pret vechi: ";
                in >> c.preturiVechi[i];

                while (c.preturiVechi[i] < 0)
                {
                    cout << "Pret invalid: ";
                    in >> c.preturiVechi[i];
                }
            }
        }

        return in;
    }

};


// Initializare atribut static
int Carte::nrCarti = 0;



// Program principal
int main()
{
    // Constructor fara parametri
    Carte c1;
    cout << c1;

    // Constructor cu parametri
    int capitole[] = {10, 15, 20, 12, 18};
    float preturi[] = {50, 45, 40};

    Carte c2
(
	1,
	 250,
 	9.5,
 	75,
	 'A',
 	true,                    
           "Ion", 
	"Liviu Rebreanu",  
 	 capitole, 
	"Humanitas",
 	preturi, 3,
	 "Roman"
);            

    cout << c2;


    // Constructor de copiere                           
    Carte c3(c2);
    cout << c3;

                                        
    // Operator =
    Carte c4;
    c4 = c2;
    cout << c4;


    // Testare getteri
    cout << "\nTESTARE GETTERI\n";
    cout << c2.getCod() << endl;
    cout << c2.getTitlu() << endl;
    cout << c2.getPret() << endl;
    cout << c2.getGen() << endl;
    cout << c2.getEditura() << endl;

    // Testare setteri
    cout << "\nTESTARE SETTERI\n";
    c2.setCod(10);
    c2.setPret(100);
    c2.setRating(10);
    c2.setTitlu("Amintiri din copilarie");
    c2.setCapitol(0, 25);
    c2.setPretVechi(0, 60);

    cout << c2;


    // Testare validari
    cout << "\nTESTARE VALIDARI\n";
    c2.setCod(-5);
    c2.setPret(-100);
    c2.setRating(15);
    c2.setNrPagini(-20);



    // Testare operator >>
    Carte c5;
    cin >> c5;



    // Testare operator <<
    cout << c5;




    // Testare atribut static
    cout << "\nNumar carti: "
         << Carte::getNrCarti() << endl;


    return 0;


}


























