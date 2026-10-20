  #define _CRT_SECURE_NO_WARNINGS

  
#include <iostream >
#include <cstring> 
 
using namespace std;  
 
//final care ruleaza corect si afiseaza    
 // V_12 dupa corectarea erorilor de compilare si rulare cu constructori destructor
 // operatori supraincarcati metode de acces si modificare a atributelor private 

  
class Benzinarie    
	  
{  
private:   
	char* tipCombustibil; 
	float pret;   
	int nrPompe;    
	float capacitateRezervor; 
	const int id; 
  

	  
public:  
	static int numarator;  
	 
	 
	Benzinarie() : id(numarator++)    
	{  
		tipCombustibil = new char[strlen("necunoscut") + 1]; 
		strcpy(tipCombustibil, "necunoscut");  
		pret = 0; 
		nrPompe = 0;  
		capacitateRezervor = 50; 
	}  
	 
	 

	Benzinarie(const char* tipCombustibil, float pret, int nrPompe, float capacitateRezervor) : id(numarator++)  
	{
		this->tipCombustibil = new char[strlen(tipCombustibil) + 1]; 
		strcpy(this->tipCombustibil, tipCombustibil); 
		this->pret = pret; 
		this->nrPompe = nrPompe; 
		setCapacitate(capacitateRezervor); 
	}
	 

	 

	Benzinarie(const Benzinarie& alta) : id(numarator++)
	{
		tipCombustibil = new char[strlen(alta.tipCombustibil) + 1];
		strcpy(tipCombustibil, alta.tipCombustibil);
		pret = alta.pret;
		nrPompe = alta.nrPompe;
		capacitateRezervor = alta.capacitateRezervor;
	}

	 


	Benzinarie& operator=(const Benzinarie& alta)
	{  

		if (this != &alta )  
		{  
			setTip(alta.tipCombustibil);
			pret = alta.pret;
			nrPompe = alta.nrPompe;
			capacitateRezervor = alta.capacitateRezervor;
		}  
		return *this;  


	}  
	 
	 

	~Benzinarie()   
	{ 
		delete[] tipCombustibil;   
	}   
	  
	const char* getTipCombustibil() const   
	{        
		return tipCombustibil; 
	}  
	 

	float getPret() const 
	{   
		return pret;    
	}   
	  
	 
	  
	int getNrPompe() const    
	{ 
		return nrPompe; 
	} 
	   
  

	void setTip(const char* tipCombustibil)  
	{
		char* tipNou = new char[strlen(tipCombustibil) + 1];     
		strcpy(tipNou, tipCombustibil); 
		delete[] this->tipCombustibil;  
		this->tipCombustibil = tipNou;         
	}   

     
	void setPret(float pret)
	{  
		this->pret = pret;
	}  
	 
	 
	 
	 
	void setPompe(int nrPompe) 
	{  
		this->nrPompe = nrPompe;
	}  
	  
	    

	    
	void setCapacitate(float capacitate)     
	{

		if (capacitate < 0)  
		{
			capacitateRezervor = 0;   
		}
		 
		else if (capacitate > 50) 
		{ 
			capacitateRezervor = 50;  
		}
		 
		else 
		{ 
			capacitateRezervor = capacitate;  
		}  


	}    
	   

	  

	float getCapacitate() const   
	{
		return capacitateRezervor;
	}

    
	 


	friend ostream& operator<<(ostream& iesire, const Benzinarie& b)   
	{
		iesire << "Tip combustibil: " << b.getTipCombustibil() << ", pret: " << b.getPret() << " lei";
		iesire << ", numar pompe: " << b.getNrPompe() << ", capacitate rezervor: " << b.getCapacitate() << " l" << endl;
		return iesire;
	}
	 
	 


	Benzinarie& operator-=(int numar)   
	{
		setCapacitate(capacitateRezervor - numar); 
		return *this;
	}

	    



}; 
 
int Benzinarie::numarator = 0;     

int main()    
{
	 

	 Benzinarie b1;
	cout << "Capacitate initiala b1: " << b1.getCapacitate() << " l" << endl;


	Benzinarie b2("benzina", 4.5, 4, 40);
	cout << "Tip combustibil b2: " << b2.getTipCombustibil() << endl;
	cout << "Date initiale b2:" << endl;
	cout << b2;



	b2.setTip("motorina");
	cout << "Date b2 dupa schimbarea combustibilului:" << endl;
	cout << b2;

	Benzinarie b3("benzina", 4.7, 5, 80);

	cout << "Date b3 (capacitatea este limitata la 50 l):" << endl;
	cout << b3; 

	b2 -= 20; 

	cout << "Date b2 dupa scaderea a 20 l:" << endl;
	cout << b2;
	  

	Benzinarie benzinarii[3];
	  
	benzinarii[0].setTip("benzina"); 
	      
	benzinarii[0].setPret(5.2f);
	    
	benzinarii[0].setPompe(6); 
	        
	benzinarii[0].setCapacitate(45); 

	cout << "Date benzinarii[0] dupa setarea pretului la 5.2 lei, a 6 pompe si a capacitatii la 45 l:" << endl;
	cout << benzinarii[0];
	  
	     

	return 0;                          

	            





} 





 

