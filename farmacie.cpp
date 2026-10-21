
#define _CRT_SECURE_NO_WARNINGS     // pentru a evita erorile de compilare la strcpy_s
  
 
#include <iostream>//  cin si cout 
#include <cstring> //  strlen si strcpy_s  
#include <iomanip>//  formatare a iesirii   
#include <algorithm>  // algoritm     
   
           
// pentru a evita prefixul std:: la fiecare utilizare a elemen din standard library
using namespace std;  
         
          
// V_6 fara erori compilare                  
// avem constructori destructor operator= operator<< operator-= setteri si getteri                      
	// afiseaza corect datele              

class Farmacie     
	   
{    
private:

	const int id;
	bool necesitaReteta;   
	int stoc; 
	float pret; 
	int numarProduse; 
	char* producator;  
	char* numeMedicament;     

	        
	  

	static char* copiazaText(const char* text)
	{ 
		 char* copie = new char[strlen(text) + 1];
		strcpy_s(copie, strlen(text) + 1, text);


		return copie;


	} 

	  
public:
	    
	    

	 static int numarator;

	  

	Farmacie() : id(numarator++)
	{
		necesitaReteta = false;    
	 	  stoc = 0; 
		  pret = 0; 
		 numarProduse = 0;   
		producator = copiazaText("necunoscut");
		numeMedicament = copiazaText("necunoscut"); 

	}        
	   

	Farmacie(const char* producator, const char* numeMedicament, bool necesitaReteta, int stoc, int numarProduse, float pret)         
		: id(numarator++)            
	{      

		            
		this->necesitaReteta = necesitaReteta;            
		setStoc(stoc);  
		            
		this->pret = pret;                

		setNumarProduse(numarProduse);
		 
		this->producator = copiazaText(producator);  
		this->numeMedicament = copiazaText(numeMedicament);  

		  

	}   
	             
	 
	  
	Farmacie(const Farmacie& alta) : id(numarator++)    
	{
		necesitaReteta = alta.necesitaReteta;
		stoc = alta.stoc;
		pret = alta.pret;
		numarProduse = alta.numarProduse;
		producator = copiazaText(alta.producator);
		numeMedicament = copiazaText(alta.numeMedicament);


	}
	   
	 
	//operator= supraincarcat pentru a copia val
	Farmacie& operator=(const Farmacie& alta)   
	{        
		if (this != &alta)
		{
			necesitaReteta = alta.necesitaReteta;
			stoc = alta.stoc;
			pret = alta.pret;
			numarProduse = alta.numarProduse;
			setProducator(alta.producator);
			setNumeMedicament(alta.numeMedicament);
		}
		return *this;

	}
	 
	     
	 
	// Destructor
	~Farmacie()

	{
		delete[] numeMedicament;  
		delete[] producator; 


	}
	  
	    

	bool getNecesitaReteta() const  
	{
		return necesitaReteta;   
	}
	   

	     
	int getStoc() const 
	{ 
		return stoc;
	}    
	   
	  
	const char* getProducator() const 
	{
		return producator; 
	}
	      
	 


	float getPret() const 
	{
		return pret; 
	}    

	   
	 
	int getNumarProduse() const  
	{ 
		return numarProduse; 
	}
	  
	   
	  
	const char* getNumeMedicament() const  
	{
		return numeMedicament;  
	}   
	  

	 
	void setNecesitaReteta(bool necesitaReteta)
	{
		this->necesitaReteta = necesitaReteta;
	}

	void setStoc(int stoc)
	{
		this->stoc = max(0, stoc);
	}




	void setProducator(const char* producator)
	{
		char* producatorNou = copiazaText(producator);
		delete[] this->producator;
		this->producator = producatorNou;
	}

	void setPret(float pret)
	{
		this->pret = pret;
	}



	void setNumarProduse(int numarProduse)
	{
		this->numarProduse = max(0, numarProduse);
	}



	void setNumeMedicament(const char* numeMedicament)
	{
		char* numeNou = copiazaText(numeMedicament);
		delete[] this->numeMedicament;
		this->numeMedicament = numeNou;
	}



	Farmacie& operator-=(int cantitate)
	{
		if (cantitate > 0)
		{
			setStoc(stoc - cantitate);
		}
		return *this;
	}



	// operatorului << pentru afisarea Farmacie 
	friend ostream& operator<<(ostream& iesire, const Farmacie& farmacie)
	{
		iesire << "Medicament: " << farmacie.getNumeMedicament()
			<< ", producator: " << farmacie.getProducator()
			<< ", necesita reteta: " << (farmacie.getNecesitaReteta() ? "da" : "nu")
			<< ", stoc: " << farmacie.getStoc() << " bucati"
			<< ", numar produse: " << farmacie.getNumarProduse()
			<< ", pret: " << fixed << setprecision(2) << farmacie.getPret() << " lei" << endl;
		return iesire;
	}






};


 // aici este initializarea variabilei statice 
int Farmacie::numarator = 0;




int main()

{



	    // testare clasa Farmacie  
	Farmacie medicamente[3];
	medicamente[0].setProducator("Biofarm"); 
	medicamente[0].setNecesitaReteta(false); 
	medicamente[0].setStoc(45);   
	medicamente[0].setNumarProduse(6); 
	 medicamente[0].setPret(8.75f); 
	medicamente[0].setNumeMedicament("Vitamina C");   
	cout << "Medicament configurat cu setteri:" << endl;   
	cout << medicamente[0];  




	  // testare constructor cu parametri
	Farmacie medicamentCuReteta("Antibiotice Iasi", "Amoxicilina", true, 40, 12, 28.9f);  
	cout << "Medicament care necesita reteta:" << endl; 
	cout << medicamentCuReteta;  



	    // testare constructor cu parametri       
	Farmacie medicamentFaraReteta("Zentiva", "Paracetamol", false, 100, 30, 12.5f);  
	cout << "Date initiale:" << endl;  
	cout << medicamentFaraReteta; 
	 


	// testare operator -= si setteri      
	medicamentFaraReteta -= 20;    
	medicamentFaraReteta.setNumeMedicament("Ibuprofen");     
	cout << "Dupa modificarea medicamentului si scaderea stocului:" << endl;        
	cout << medicamentFaraReteta;  
	 

	// testare constructor de copiere      
	Farmacie medicamentCopiat = medicamentCuReteta; 

 
	// testare operator= supraincarcat    
	Farmacie farmacieNoua;        
	cout << "Obiect creat cu constructorul fara parametri; stoc: "      
		<< farmacieNoua.getStoc() << " bucati" << endl;           
	  



	return 0;





}














