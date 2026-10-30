#define _CRT_SECURE_NO_WARNINGS   
#include <iostream>      
#include <string>             
                  
using namespace std;       
                

// cofetarie cu pret per loc  
     
class Cofetarie                
{       
    
private:   
	const int id;                  
	string denumire;                  
	int nrLocuri;               
	float pretPerLoc; 
	static int contor; // cont id      
         

    
public:          
	// ctor def         
	Cofetarie() : id(++contor), denumire("default"), nrLocuri(0), pretPerLoc(0.0f)           
	{}    
             

	// ctor param          
	Cofetarie(const string& den, int nr, float pret) : id(++contor), denumire(den), nrLocuri(nr), pretPerLoc(pret)         
	{} 
  

	// afis info            
	void afisare() const           
	{          
		cout << "id: " << id << "\n";                 
		cout << "denumire: " << denumire << "\n";                 
		cout << "nr locuri: " << nrLocuri << "\n";             
		cout << "pret/loc: " << pretPerLoc << "\n";   


	}  

      
  

      
};               
    
int Cofetarie::contor = 0;       
      
int main()         
{             
	// cre doua obiecte        
	Cofetarie c1;      
	c1.afisare();                 
               
	Cofetarie c2("dulce", 10, 12.5f);                 
	c2.afisare();            
        
	return 0; 


           
}  


   