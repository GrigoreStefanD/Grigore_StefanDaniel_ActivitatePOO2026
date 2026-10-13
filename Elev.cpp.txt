


#define CRT_SECURE_NO_WARNINGS                     
#include <iostream>            
#include <string>         
          
using namespace std;

class Elev  
{
private:


    string nume;               
    string scoala;                  
    int nrNote;    
    int* note;              
      

public:


    // const
    Elev() {
        nume = "";             
        scoala = "";
        nrNote = 0;             
        note = nullptr;
    }
            
    // citire   
    void citire() 
    {


        cout << "Nume elev: ";
        cin >> nume;
              
        cout << "Scoala: ";
        cin >> scoala;
               
        cout << "Numar note: ";
        cin >> nrNote;
         
        note = new int[nrNote];
          

        for (int i = 0; i < nrNote; i++) 

        {
            cout << "Nota " << i + 1 << ": ";
            cin >> note[i];
        }     
    }
                
    // aici pentru afisare
    void afisare()   
    {

        cout << "\nElev: " << nume;

        cout << "\nScoala: " << scoala;


        for (int i = 0; i < nrNote; i++) 
        {
            cout << "\nNota: " << note[i];
        }


    }
     
      


	// Destructor pentru eliberare memmorie
    ~Elev() 
    { 
        delete[] note;  
    }
       



};


 
 



int main()  

{


    Elev* e = new Elev; 
     

    e->citire();   
    e->afisare();  
      
    delete e;   
      
    return 0;







}