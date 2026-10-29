#define _CRT_SECURE_NO_WARNINGS                  
#include <iostream>            
#include <string>              
#include <vector>            
   
using namespace std;      
          
// magazin - lista simpla de produse           
class Produs            
{              
private:      
	string denumire;   
	int cantitate;     
     
public:                  
	// ctor cu date    
	Produs(const string& den, int nr) : denumire(den), cantitate(nr)       
	{                
	}             
           
	// afis produs                
	void afisare() const 
	{             
		cout << denumire << " - bucati: " << cantitate << "\n";         
	}       
 
	// returneaza cantitatea               
	int getCantitate() const         
	{              
		return cantitate;             
	}            
};    
                
int main()                
{ 
	vector<Produs> produse;      
   
	produse.emplace_back("paine", 15);   
	produse.emplace_back("lapte", 8); 
	produse.emplace_back("mere", 20);              
   
	int total = 0;             
   
	cout << "produse in magazin:\n";           
                  
	for (const auto& produs : produse)                
	{          
		produs.afisare();       
		total += produs.getCantitate();         
	}       
             
	cout << "total bucati: " << total << "\n";              
              
	return 0;  
}          
                