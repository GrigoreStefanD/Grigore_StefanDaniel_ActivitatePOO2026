#define _CRT_SECURE_NO_WARNINGS

    
#include <iostream> 
#include <string> 
#include <limits>   

using namespace std;
   

// v5 act loc ocupate fara erori    
  
 

class Restaurant
{  
private:
    const int id;   
    string denumire;    
    int nrLocuri;  
    int locuriOcupate;        
    int* locuriMese;        
    static int contor; 

      

public:
    // constr  cu date
    Restaurant(const string& den, int locuri): id(++contor), denumire(den), nrLocuri(locuri),locuriOcupate(0), locuriMese(new int[locuri])
    
    {

        for (int i = 0; i < nrLocuri; i++)
        {
            locuriMese[i] = 4;
        }


    }


    // cons  de copiere
    Restaurant(const Restaurant& r): id(++contor), denumire(r.denumire), nrLocuri(r.nrLocuri), locuriOcupate(r.locuriOcupate), locuriMese(new int[r.nrLocuri])
    {
        
        for (int i = 0; i < nrLocuri; i++)
        {
            locuriMese[i] = r.locuriMese[i];
        }



    } 

    // des   
    ~Restaurant()  
    {
        delete[] locuriMese;     
    }

    // ocupa loc  
    void ocupaLocuri(int nr)
    {  
        int capacitate = 0; 
 
          for (int i = 0; i < nrLocuri; i++)
        {
            capacitate += locuriMese[i];
        } 

        if (nr > 0 && locuriOcupate + nr <= capacitate) 
        {
            locuriOcupate += nr;
        }  


    }

    // afisare date
    void afisare() const
    {

        cout << "id: " << id << "\n";   
        cout << "restaurant: " << denumire << "\n"; 
         
        int capacitate = 0;     

        for (int i = 0; i < nrLocuri; i++) 
        {
            capacitate += locuriMese[i];  
        }


        cout << "locuri libere: "
            << capacitate - locuriOcupate << "\n";


    }  

       
};
   
int Restaurant::contor = 0;                             
   
 
          
           
int main()   
{                     
    Restaurant* restaurant = nullptr;  
    Restaurant* copie = nullptr;  
    int opt;    

     
     
    while (true)
    {
          
        cout << "\n1. creare\n2. copiere\n3. afisare\n4. iesire\n";  
        cout << "alegere: ";  



                        
        if (!(cin >> opt))
        {        
            cout << "Valoare invalida Introdu o optiune numerica\n";      
            cin.clear();      
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;          
        }      



        // creare restaurant
        if (opt == 1)
        {    
            string denumire; 
            int mese;
                        
                   
            // citire nume restaurant cu spatii
            cout << "denumire restaurant ";    
            cin.ignore(numeric_limits<streamsize>::max(), '\n');     
            getline(cin, denumire);
                          


            // verificare numar mese
            cout << "nr mese ";

            while (!(cin >> mese) || mese <= 0)
            { 
                cout << "valoare invalida introdu un numar: "; 
                cin.clear();        
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
              
               

            delete restaurant; 
            delete copie;
              
             
              restaurant = new Restaurant(denumire, mese); 
            copie = nullptr;    
              
              cout << "restaurant creat cu succes\n";

               
        }  
          


        // copiere restaurant 
        else if (opt == 2) 
        {  
  
            if (restaurant != nullptr) 
            {  
                delete copie;
                copie = new Restaurant(*restaurant);  

                cout << "Copie creata cu succes\n";  
            }

             
            else 
            { 
                cout << "Creeaza restaurantul intai\n"; 
            } 
        }  
         

        // afisare restaurante 
        else if (opt == 3)  
        {
            
            if (restaurant != nullptr) 
            {
                cout << "\nRestaurant original\n";
                restaurant->afisare();
            }



            if (copie != nullptr)
            { 
                cout << "\nRestaurant copiat\n"; 
                copie->afisare();
            }    

                 

              
            if (restaurant == nullptr) 
            { 
                cout << "Nu exista restaurant\n";    
            } 



        }
         


        // Iesire 
        else if (opt == 4) 
        {    
            break;    
        } 

        else
        { 
            cout << "Optiune invalida\n";
        }  


         
    }
      
    delete restaurant; 
    delete copie;  

    return 0; 


     
     
}
 
 
  



  
 
  

 
