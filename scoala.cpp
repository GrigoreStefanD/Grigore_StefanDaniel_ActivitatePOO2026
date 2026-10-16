#define _CRT_SECURE_NO_WARNINGS             
#include <iostream> 
#include <string>      
#include <vector>        

using namespace std;       

   
class Scoala 
	      
{ 
private:  

	const int id;            
	string denumire;                  
	int nrElevi;           
	static int contor;                


public:
	Scoala() : id(++contor), denumire("def"), nrElevi(0)              
	{       
	}  

	Scoala(const string& den, int nr) : id(++contor), denumire(den), nrElevi(nr)              
	{             
	}    

	void afisare() const          

	{      
		cout << "id: " << id << " | " << denumire << " | elevi: " << nrElevi << "\n";       
	}      



	int getElevi() const           
	{
		return nrElevi;       


	}


	 
}; 
     



int Scoala::contor = 0;   

  
 
 
int main()   
 
{
	vector<Scoala> v;   



	v.emplace_back("ion creanga", 120); 
	v.emplace_back("mircea cel batran", 300); 
	v.emplace_back("alexandru", 80);  




	cout << "lista scoli:\n"; 
		int total = 0;
	for (const auto& s : v) 


	{ 
		s.afisare();
		total += s.getElevi(); 
		   

		 
	} 


	cout << "total elevi: " << total << "\n"; 
	return 0;

	   

}       
 

     
   
    