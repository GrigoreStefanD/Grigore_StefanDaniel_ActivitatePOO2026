
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <iomanip>
#include <algorithm>
 
using namespace std;
    


   // aplicatie pentru gestionarea laptopurilor
 // avem constructori, operatori, getteri si setteri,
// operatori de comparare si afisare
 // citirea datelor de la tastatura
    
                                 
      
class Laptop
{
private:  
    const int CODUnic;

    float MemorieRAM; 
    int nrProgrameInstalate; 
    float* MemorieOcupata; 

    // Functie pentru copierea memoriei ocupate
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

    // Constructor fara parametri pentru celelalte atribute
    Laptop(const int id) : CODUnic(id)
    {
        MemorieRAM = 0; 
        nrProgrameInstalate = 0;
        MemorieOcupata = NULL;
    } 

      


    // Constructor cu parametri 
    Laptop(const int ID, float ram, int nr, float* memorie) 
        : CODUnic(ID)  
    {
        MemorieRAM = max(0.0f, ram);
        nrProgrameInstalate = max(0, nr);

        MemorieOcupata = copiazaMemorie
        ( 
            memorie, nrProgrameInstalate
        ); 



    }  

      

    // Constructor de copiere
    Laptop(const Laptop& l) : CODUnic(l.CODUnic)
    {
        MemorieRAM = l.MemorieRAM;
        nrProgrameInstalate = l.nrProgrameInstalate;

        MemorieOcupata = copiazaMemorie
        (  
            l.MemorieOcupata,
            l.nrProgrameInstalate 
        );  

          
    }
       



    // Operator =

    Laptop& operator=(const Laptop& l)
    {
        if (this != &l)
        {
            float* memorieNoua = copiazaMemorie(
                l.MemorieOcupata,
                l.nrProgrameInstalate 
            );   

            delete[] MemorieOcupata;  
              
            MemorieRAM = l.MemorieRAM; 
            nrProgrameInstalate = l.nrProgrameInstalate;  
            MemorieOcupata = memorieNoua; 
        } 


        return *this;


    }

    // Destructor
    ~Laptop()
    {
        delete[] MemorieOcupata;
    } 

    // Getteri  
     
    int getCODUnic() const 
    {       
        return CODUnic;
    }
      

    float getMemorieRAM() const
    {
        return MemorieRAM; 
    } 

     

    int getNrPrograme() const 
    {
        return nrProgrameInstalate; 
    }

    float getMemorieOcupata(int index) const
    {
        if (index >= 0 && index < nrProgrameInstalate)
            return MemorieOcupata[index];

        return -1;
    } 
     
     
    // Setteri
    void SetMemorieRAM(float ram)  
    {
        MemorieRAM = max(0.0f, ram); 
    } 

     

    void SetNrPrograme(int nr)  
    { 

        if (nr < 0)
            nr = 0; 
          
        float* memorieNoua = NULL;



        if (nr > 0)
        {
            memorieNoua = new float[nr]();        

            int limita = min(nr, nrProgrameInstalate);  

            for (int i = 0; i < limita; i++)  
            {
                memorieNoua[i] = MemorieOcupata[i];
            }
              

        }   

        delete[] MemorieOcupata; 
         

        MemorieOcupata = memorieNoua;
        nrProgrameInstalate = nr;


    }

    // Setter pentru memoria ocupata de programe
    void SetMem(float* memorie, int nr)
    {
        if (nr < 0)
              nr = 0;
          
        float* memorieNoua = copiazaMemorie(memorie, nr);

        delete[] MemorieOcupata;

        MemorieOcupata = memorieNoua;
                
        nrProgrameInstalate =

            (nr > 0 && memorie != NULL) ? nr : 0;


    }

    // Operator [] pentru accesarea memoriei unui program


    float operator[](int index) const
    {
        if (index >= 0 && index < nrProgrameInstalate)
            return MemorieOcupata[index];

        return -1;   
         
    }

      
    // Operator > pentru compararea memoriei RAM

    bool operator>(const Laptop& l) const 
    { 
         
        return MemorieRAM > l.MemorieRAM;

    }
     
    // Operator << pentru afisare

    friend ostream& operator<<(ostream& iesire, const Laptop& l)  
    {
        iesire << "Laptopul cu ID: " << l.CODUnic 
            << ", memorie RAM: "  
            << fixed << setprecision(2) 
            << l.MemorieRAM << " GB"
            << ", numar programe instalate: " 
            << l.nrProgrameInstalate 
            << ", memoria ocupata de programe: ";
         
        
        for (int i = 0; i < l.nrProgrameInstalate; i++) 
        { 
            iesire << l.MemorieOcupata[i] << " GB"; 

            if (i < l.nrProgrameInstalate - 1) 
                iesire << ", ";
        } 
         
        iesire << endl;

        return iesire; 


    }
      
    // Operator >> pentru citire
      
    friend istream& operator>>(istream& intrare, Laptop& l)   
    {   

        float ram;      
        int nr; 
         
        cout << "Introdu memoria RAM (GB): "; 
        intrare >> ram;     
         
        if (!intrare)  
            return intrare;      
              
        cout << "Introdu numarul de programe instalate: ";
        intrare >> nr;
                                        
                    
        if (!intrare)
            return intrare;            


        if (nr < 0)          
        {
            intrare.setstate(ios::failbit);         
            return intrare;        
        }

        // Alocare dinamica pentru memoria ocupata     
        float* valori = nr > 0 ? new float[nr] : NULL;         


        for (int i = 0; i < nr; i++)
        {
            cout << "Memoria ocupata de programul " 
                << i + 1 << " (GB): ";
             
            intrare >> valori[i];

            if (!intrare)
            {
                delete[] valori;
                return intrare;
            }
        }

        l.SetMemorieRAM(ram);
        l.SetMem(valori, nr);

        delete[] valori; 

        return intrare;   
    }


      
};



int main()
    
{
    // Testare constructor fara parametri    
    Laptop l1(100);
      
    cout << "Primul laptop:" << endl; 
    cout << l1; 
      
    cout << "Memorie RAM: "
        << l1.getMemorieRAM() << " GB" << endl; 

    cout << "Numar programe: "   
        << l1.getNrPrograme() << endl; 

        
         

    // Testare constructor cu parametri
    float memorie1[5] = 
    {
        2.5f, 1.8f, 3.0f, 4.0f, 1.2f
    }; 
       
    Laptop l2(200, 16.0f, 5, memorie1);  
       
    cout << "\nAl doilea laptop:" << endl;  
    cout << l2;   

    // Testare constructor de copiere   
    Laptop l3(l2);  
       
    cout << "\nLaptopul copiat l3:" << endl;
    cout << l3;
       

    // Testare operator =
    float memorie2[2] = { 1.0f, 2.0f };
     
      
     
    Laptop l4(300, 8.0f, 2, memorie2);
     
    l4 = l2; 
       
    cout << "\nLaptopul l4 dupa atribuirea l4 = l2:   " << endl;
    cout << l4;

    cout << "Codul unic al lui l4 ramane:     "
        << l4.getCODUnic() << endl;

     
 

    // testare operator []
    cout << "\nMemoria primului program din l2: " 
        << l2[0] << " GB" << endl;  
       
    cout << "Memoria celui de-al doilea program: "   
        << l2[1] << " GB" << endl;   

      

    // testare operator >  
    cout << "\nComparare laptopuri:" << endl;   

    if (l2 > l4)  
        cout << "l2 are mai multa memorie RAM decat l4."   
        << endl; 
    else 
        cout << "l2 nu are mai multa memorie RAM decat l4." 
        << endl; 
                    


      
    // Ttestare setteri
    l1.SetMemorieRAM(32.0f);   

    float programeNoi[3] = { 2.0f, 5.5f, 3.5f }; 
     
    l1.SetMem(programeNoi, 3);  

    cout << "\nLaptopul l1 dupa modificarea datelor:" << endl;
    cout << l1; 


    // testare operator >> 
    Laptop l5(400);
     
    cout << "\nIntroducere date pentru l5:" << endl; 
    cin >> l5; 
     
    cout << "\nDatele laptopului l5:" << endl; 
    cout << l5; 

       

     


      
    return 0;

     



}

 



