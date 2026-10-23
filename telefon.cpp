
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>  


using namespace std;  

   
   //
// aplicatie pentru gestionarea telefoanelor mobile
  //avem functii pentru constructori operatori getteri si setteri operatori de comparare si afisare
// face si citire de la tastatura pentru a putea introduce datele unui telefon mobil
 //    apoi se testeaza toate functiile implementate in main
   
class Telefon
{  

private: 
    const int CODUnic;
     
    float MemorieTotala;
    int nrAplicatiiInstalate; 
    float* MemorieOcupata; 


      

    // functie pentru copierea memoriei ocupate
    static float* copiazaMemorie(const float* memorie, int nr)  
    {
        if (nr <= 0 || memorie == NULL)
            return NULL; 

        float* copie = new float[nr]; 
         
        for (int i = 0; i < nr; i++)  
        {
            copie[i] = memorie[i];   
        }

        return copie;
          

    }  

public:
      


    // constructor fara parametri pentru celelalte atribute
    Telefon(const int id) : CODUnic(id)
    {
        MemorieTotala = 0;
        nrAplicatiiInstalate = 0; 
        MemorieOcupata = NULL;  
    }

      

    // constructor cu parametri
    Telefon(const int ID, float mt, int nr, float* mo)
        : CODUnic(ID)
    {  
        MemorieTotala = max(0.0f, mt);
        nrAplicatiiInstalate = max(0, nr);

        MemorieOcupata = copiazaMemorie(
            mo, nrAplicatiiInstalate
        );
    }

      
      
    // constructor de copiere
    Telefon(const Telefon& t) : CODUnic(t.CODUnic)  
    {
        MemorieTotala = t.MemorieTotala;   
        nrAplicatiiInstalate = t.nrAplicatiiInstalate;  

        MemorieOcupata = copiazaMemorie(   
            t.MemorieOcupata, 
            t.nrAplicatiiInstalate   
        );



    }  


      

    //  =
    Telefon& operator=(const Telefon& t)  


    {
        if (this != &t)           
                    

        {               

            float* memorieNoua = copiazaMemorie( 
                t.MemorieOcupata, 
                t.nrAplicatiiInstalate
            ); 
                   

            delete[] MemorieOcupata; 
             
              
             
            MemorieTotala = t.MemorieTotala;
            nrAplicatiiInstalate = t.nrAplicatiiInstalate;        
            MemorieOcupata = memorieNoua;
        }
        
        return *this;           
             

          
    }
            
    // Destructor  
    ~Telefon() 
    { 
        delete[] MemorieOcupata; 
    }
     
    // Getteri
    int getCODUnic() const 
    { 
        return CODUnic;
    }
     
       
    float getMemorieTotala() const
    {
        return MemorieTotala;
    } 

       
    int getNrAplicatii() const 
    { 
        return nrAplicatiiInstalate; 
    }
       
     

    float getMemorieOcupata(int index) const 
    { 
        if (index >= 0 && index < nrAplicatiiInstalate) 
            return MemorieOcupata[index];
         
        return -1;  
    }




	  //setteri
    void SetMemorieTotala(float mt)    
    {
        MemorieTotala = max(0.0f, mt); 
    } 
     
    void SetNrAplicatii(int nr) 
    {
        if (nr < 0)
            nr = 0;

        float* memorieNoua = NULL;

        if (nr > 0)
        {
            memorieNoua = new float[nr]();

            int limita = min(nr, nrAplicatiiInstalate);

            for (int i = 0; i < limita; i++)
            {
                memorieNoua[i] = MemorieOcupata[i];
            }
        }

        delete[] MemorieOcupata;

        MemorieOcupata = memorieNoua;
        nrAplicatiiInstalate = nr;
    }
        

	  // setter pentru memoria ocupata de aplicatii
    void SetMem(float* newM, int nr)
    {
        float* memorieNoua = copiazaMemorie(newM, nr);

        delete[] MemorieOcupata;

        MemorieOcupata = memorieNoua;
        nrAplicatiiInstalate =
            (nr > 0 && newM != NULL) ? nr : 0;
    }




         // operator [] pentru accesarea memoriei unei aplicatii
    float operator[](int index) const
    {
        if (index >= 0 && index < nrAplicatiiInstalate)

            return MemorieOcupata[index];

        return -1;
    }



    // operator > pentru compararea memoriei totale
    bool operator>(const Telefon& t) const
    {
        return MemorieTotala > t.MemorieTotala;


    }


    // operator << pentru afisare
    friend ostream& operator<<(ostream& iesire, const Telefon& t)
    {


        iesire << "Telefonul cu ID:   " << t.CODUnic
            << " , memorie totala:   "
            << fixed << setprecision(2)

            << t.MemorieTotala << " GB"

            << " , numar aplicatii instalate:  "

            << t.nrAplicatiiInstalate
            << "  , memoria ocupata de aplicatii:  ";


		//fac asta pentru ca operatorul << nu poate fi folosit direct pe un pointer 
        // trebuie sa parcurg vectorul de memorie ocupata pentru a afisa fiecare valoare 
        for (int i = 0; i < t.nrAplicatiiInstalate; i++)

        {
            iesire << t.MemorieOcupata[i] << " GB";

            if (i < t.nrAplicatiiInstalate - 1)
                iesire << ", ";
        }




        iesire << endl;



        return iesire;
    }




    // Operator >> pentru citire
    friend istream& operator>>(istream& intrare, Telefon& t)
    {
        float memorie;
        int nr;

        cout << "Introdu memoria totala (GB): ";
        intrare >> memorie;

        if (!intrare)
            return intrare;

        cout << "Introdu numarul de aplicatii instalate: ";
        intrare >> nr;

        if (!intrare)
            return intrare;


        if (nr < 0)
        {
            intrare.setstate(ios::failbit);
            return intrare;
        }



		// alocare dinamica pentru vect de mem ocp 
        // se aloca memorie pentru vect de mem ocp
        float* valori = nr > 0 ? new float[nr] : NULL;

        for (int i = 0; i < nr; i++)
        {
            cout << "Memoria ocupata de aplicatia "
                << i + 1 << " (GB): ";

            intrare >> valori[i];

            if (!intrare)
            {
                delete[] valori;
                return intrare;
            }
        }


        t.SetMemorieTotala(memorie);
        t.SetMem(valori, nr);


        delete[] valori;


        return intrare;


    }


};








int main()
{
    // Testare constructor fara parametri pentru aplicatii
    Telefon t1(100);

    cout << "Primul telefon:" << endl;   
    cout << t1;
      
    cout << "Memorie totala: "
        << t1.getMemorieTotala() << endl; 
      
    cout << "Numar aplicatii: "
        << t1.getNrAplicatii() << endl; 




    // Testare constructor cu parametri 
    float array[5] = { 100.09f, 60.08f, 60.0f, 90.0f, 50.0f };     

    Telefon t2(100, 512.0f, 5, array);

    cout << "\nAl doilea telefon:" << endl;
    cout << t2;


    // Testare constructor de copiere 
    Telefon t3(t2); 

    cout << "\nTelefonul copiat t3:" << endl; 
    cout << t3;
       

    // Testare operator =   
    float array2[2] = { 5.4f, 6.8f }; 
     
    Telefon t4(200, 128.0f, 2, array2); 
     
    t4 = t2;    

    cout << "\nTelefonul t4 dupa atribuirea t4 = t2:" << endl;  
    cout << t4;   
       
    cout << "Codul unic al lui t4 ramane: " 
        << t4.getCODUnic() << endl;

       
    // Testare operator []   
    cout << "\nMemoria primei aplicatii din t2: "  
        << t2[0] << " GB" << endl;  

    cout << "Memoria celei de-a doua aplicatii: "   
        << t2[1] << " GB" << endl;    



    // Testare operator >  
    cout << "\nComparare telefoane:" << endl; 
      
    if (t2 > t4)   
        cout << "t2 are memorie totala mai mare decat t4." << endl;  
    else   
        cout << "t2 nu are memorie totala mai mare decat t4." << endl;   
       
     
      
    // Testare setter  
    t1.SetMemorieTotala(256.0f);   

    float aplicatiiNoi[3] = { 10.5f, 20.0f, 15.5f };  
      
    t1.SetMem(aplicatiiNoi, 3);    
      
    cout << "\n telefonul t1 dupa modificarea datelor:   " << endl;   
    cout << t1;  

        
     
    // Testare operator >> 
    Telefon t5(101);  

    cout << "\n  introducere date pentru t5:  " << endl; 
    cin >> t5;  

    cout << "\n datele telefonului t5:  " << endl;  
    cout << t5; 
      
  
    return 0; 
        
}  
  
 

 
 
 


 

                         


  
