          
#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <vector>
#include <string>
        
using namespace std;
   
// proiect simplu: Masina - adauga citeste afiseaza 
  
  
    
// clasa Masina - campuri public  
class Masina  
{    
public:  
	string marca;   
	string model;    
	int an;              
	string nrInmatriculare;     
};    

// citeste linie de la tastatura    
string citesteLinie(const string& prompt)   
{
	string s;
	cout << prompt; 
	getline(cin, s); 
	return s;    
}
   
//  aici citeste int simplu  
int citesteInt(const string& prompt) 
      
{   
	while (true)     
	{        
		string linie = citesteLinie(prompt);
		try 
		{ 
			return stoi(linie);
		}  
		catch (...)
		{
			cout << "valoare invalida \n";
		} 
		  
		    
	}  
	     

}     



// aici afiseaza lista masini
void afiseazaMasini(const vector<Masina>& parc)
{ 


	if (parc.empty())     
	{
		cout << "nu exista masini  \n";    
		return;  
	} 
	
	cout << "\nlista masini:\n";

	for (size_t i = 0; i < parc.size(); ++i)       
	{    
		const auto& m = parc[i];  
		cout << i + 1 
			
			<< ". " 
			
			<< m.marca 
			
			<< " " 
			
			<< m.model   
			
			<< " | An: " << m.an
			
			<< " | Nr: " << m.nrInmatriculare << "\n";
	}  

	    
}

 
    
int main()   
{  
	vector<Masina> parc; // stocare masini
	 
	while (true)   
	{
		cout << "\n--- Meniu simplu ---\n";
		   
		cout << "1. Adauga masina\n";  
		   
		cout << "2. Afiseaza masini\n";  

		cout << "3. Iesire\n";        
		         
		 
  		 
		int opt = citesteInt("Alegere (1-3): ");  

		if (opt == 1)     
		{  
			Masina m; 
			m.marca = citesteLinie("marca: ");                  
			m.model = citesteLinie("model: ");    
			m.an = citesteInt("an fabricatie: ");        
			m.nrInmatriculare = citesteLinie("numar inmatriculare: ");              
			parc.push_back(m); 
			cout << "masina adaugata\n";          
		}    
		 
		else if (opt == 2)      
		{  
			afiseazaMasini(parc);                
		}  
		 
		else if (opt == 3)            
		{
			cout << "la revedere!\n";      
			break;  
		}   
		   
		else     
		{ 
			cout << "optiune invalida.\n";  
		}
	}

	 
	
	
	return 0;   

	  

}



