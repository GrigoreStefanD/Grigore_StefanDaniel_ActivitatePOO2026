#define _CRT_SECURE_NO_WARNINGS    
               
#include <iostream>  
#include <string>                  
  
using namespace std;                
   
 
          
 
class Cofetarie              
{          
              
private:             
          
	const int id; 
	string denumire;             
	int nrLocuri; 
    
	static int contor; // cont id  
              
       
public:            
    
	// ctor def      
	Cofetarie() : id(++contor), denumire("default"), nrLocuri(0)                
	{}          
               
	// ctor param               
	Cofetarie(const string& den, int nr) : id(++contor), denumire(den), nrLocuri(nr)     
	{}                  
          
	// afis info             
	void afisare() const              
	{               
		cout << "id: " << id << "\n";          
		cout << "denumire: " << denumire << "\n";                  
		cout << "nr locuri: " << nrLocuri << "\n";            
	}   
                  
	// func stat nr               
	static int getContor()           
	{   
		return contor;         
	} 
};  
       
                  
            
int Cofetarie::contor = 0;     
 
int main()  
{                 
	// creare  obj def  
	Cofetarie c1;      
	c1.afisare();        
           
	// creare obj param                  
	Cofetarie c2("dulceata", 12);              
	c2.afisare();           
               
	cout << "am creat " << Cofetarie::getContor() << " cofetarii" << endl;               
	return 0;         
      
                
         
                  
}     