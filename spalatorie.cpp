  
  
#define _CRT_SECURE_NO_WARNINGS                  
#include <iostream>   
#include <string>                   
#include <limits>  

using namespace std;
   
// spalatorie cu citire                    
 
class Spalatorie
{         
private:           
	const int id;          
	string denumire;          
	int nrMasini;       
	static int contor;       

	  
public:
	Spalatorie() : id(++contor), denumire("default"), nrMasini(0)         
	{   
	}
	        

	Spalatorie(const string& den, int nr) : id(++contor), denumire(den), nrMasini(nr)          
	{  
	}
	                           

	void afisare() const     
	{
		cout << "id: " << id << "\n";            
		cout << "denumire: " << denumire << "\n";         
		cout << "nr masini: " << nrMasini << "\n";            
	}


	// citire         
	static Spalatorie citire()              
	{        
		string den;          
		int nr;        

		cout << "introdu denumire: ";
		                   
		getline(cin, den);       
		if (den.empty()) getline(cin, den);               

		cout << "introdu nr masini: ";                                 
		while (!(cin >> nr))      
		{   
			cin.clear();    
			cin.ignore(numeric_limits<streamsize>::max(), '\n');      
			cout << "valoare invalida, reintrodu: ";          
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		return Spalatorie(den, nr);

	}                        
	 
	 
}; 

             
int Spalatorie::contor = 0;                       
                                                                           
int main() 
{  
	  

	cout << "creare spalatorie prin citire:\n";      


	Spalatorie s = Spalatorie::citire();                       
	s.afisare(); 

	        
	return 0;           

	  


}  
 
 
       