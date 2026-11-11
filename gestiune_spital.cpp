#define _CRT_SECURE_NO_WARNINGS
                  
#include <iostream>              
#include <string>  
   
using namespace std;                  
               
// spital - evidenta paturilor   
       
class Spital                 
{        
private: 
            
	const int id;      
	string denumire;                
	int nrPaturi;           
	int paturiOcupate;  
	int* starePaturi;                
	static int contor; 
          
                 
public:          
	// ctor cu date  
            
	Spital(const string& den, int nr, int ocupate)             
		: id(++contor), denumire(den), nrPaturi(nr), paturiOcupate(ocupate), starePaturi(new int[nr])  
    
	{                 
		for (int i = 0; i < nrPaturi; i++)              
		{   
			starePaturi[i] = i < paturiOcupate ? 1 : 0;   
		}              
	} 
        
         
	// ctor de copiere  
     
	Spital(const Spital& s)           
		: id(++contor), denumire(s.denumire), nrPaturi(s.nrPaturi), paturiOcupate(s.paturiOcupate), starePaturi(new int[s.nrPaturi])             
	{            
		for (int i = 0; i < nrPaturi; i++)                 
		{             
			starePaturi[i] = s.starePaturi[i];        
		}                  
	}           
        


	// destructor             
	~Spital()   
	{   
		delete[] starePaturi;
   
	}       
        


	// calculeaza paturi libere           
	int getPaturiLibere() const    
	{                
		int libere = 0; 

          
		for (int i = 0; i < nrPaturi; i++)        
		{     
			if (starePaturi[i] == 0)               
			{              
				libere++; 
               
			}             
		}       

 
		return libere;   
  
	}                
   


	// afis date          
	void afisare() const  
	{        
		cout << "id: " << id << "\n";          
		cout << "spital: " << denumire << "\n";               
		cout << "paturi libere: " << getPaturiLibere() << "\n"; 
 
	} 

};    
            
      
          
int Spital::contor = 0;                 
 


int main()    
{  
            
	Spital* spital = nullptr; 
	Spital* copie = nullptr;    
	int opt;     
            

	while (true)  
     
	{                 
		cout << "\n1. creare\n2. copiere\n3. afisare\n4. iesire\n";                  
		cout << "alegere: ";                
		cin >> opt;             
     

		if (opt == 1)     
		{               
			string denumire;              
			int paturi;                
			int ocupate;                
                 
			cout << "denumire spital: ";        
			cin >> denumire;       
			cout << "nr paturi: ";        
			cin >> paturi;        
			cout << "paturi ocupate: ";    
			cin >> ocupate;              
            

			if (paturi > 0 && ocupate >= 0 && ocupate <= paturi)       
			{         
				delete spital;           
				delete copie; 
				spital = new Spital(denumire, paturi, ocupate);                  
				copie = nullptr;                  
			}  

      
			else       
			{       
				cout << "date invalide\n";              
			} 

            
		}         
 



		else if (opt == 2)        
		{   
			if (spital != nullptr)        
			{     
				delete copie;          
				copie = new Spital(*spital);            
				cout << "copie creata\n"; 
			} 

             
			else    
			{       
				cout << "creeaza spitalul intai\n";      
			}  

		}  

               
		else if (opt == 3)                 
		{             
			if (spital != nullptr)          
			{             
				cout << "spital original:\n";                
				spital->afisare();           
			}      
			if (copie != nullptr)               
			{            
				cout << "spital copiat:\n";    
				copie->afisare();              
			}    
			if (spital == nullptr)        
			{                
				cout << "nu exista spital\n";   
			} 
      
		} 

             
		else if (opt == 4)       
		{                 
			break;           
		}    
        
		else              
		{              
			cout << "optiune invalida\n";       
		}   

	}   
      

                
	delete spital; 
	delete copie;                 
        
	return 0;  
 
}      



          
              