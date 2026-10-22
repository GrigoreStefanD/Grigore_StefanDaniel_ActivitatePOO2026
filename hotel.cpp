
#define _CRT_SECURE_NO_WARNINGS	//de trecut asta este pentru a nu mai da erori la strcpy_s si alte functii similare

   
#include <iostream>   // nu uita cin si cout 
#include <cstring>//  strlen strcpy_s   
#include <iomanip>  // ca sa pot afisa cu 2 zecimale 
#include <algorithm>  //daca vreu sa iau val min sau max dintre 2 val
       
  

using namespace std; 
 
  
 //fara erori de comp
//corectat destructor 
// finl de urcat
//aplic de gest a unitatilor hoteliere
//constructori, destructor, operator=, operator<<, operator-=, setteri si getteri


class Hotel 
{  
private:
	   
	 const int id;
	  
	int numarStele;  
	 bool micDejunInclus;   
	int camereDisponibile;  
	 int numarCamere; 
	float pretPeNoapte;  
	
	char* numeHotel;   
	char* tipCamera;   
	  
	 
	  
	static char* copiazaText(const char* text)   
		 
	{    
		// aloca memorie pentru un nou sir de caractere si copy cont textului in acesta
		char* copie = new char[strlen(text) + 1];  
		strcpy_s(copie, strlen(text) + 1, text);  
		return copie;  
		 
	}  
	  
public:
	  

	static int numarator;  
	  

	  
	Hotel() : id(numarator++)//constructor fara parametri


	{


		numarStele = 1;  
		micDejunInclus = false; 
		camereDisponibile = 0; 
		
		numarCamere = 0; 
		pretPeNoapte = 0; 
	
		
		numeHotel = copiazaText("nespecificat"); 
		tipCamera = copiazaText("nespecificata"); 


	}



	///constructor cu parametri	
	Hotel(const char* numeHotel, const char* tipCamera, int numarStele, bool micDejunInclus,float pretPeNoapte, int numarCamere, int camereDisponibile)
		: id(numarator++)
	{

		this->numarStele = min(5, max(1, numarStele));
		this->micDejunInclus = micDejunInclus;
		this->numarCamere = max(0, numarCamere);
		setCamereDisponibile(camereDisponibile);
		this->pretPeNoapte = pretPeNoapte;

		this->numeHotel = copiazaText(numeHotel);
		this->tipCamera = copiazaText(tipCamera);


	}



	//constructor de copiere
	Hotel(const Hotel& altul) : id(numarator++)
	{
		numarStele = altul.numarStele;
		micDejunInclus = altul.micDejunInclus;
		camereDisponibile = altul.camereDisponibile;
		numarCamere = altul.numarCamere;
		pretPeNoapte = altul.pretPeNoapte;
		numeHotel = copiazaText(altul.numeHotel);
		tipCamera = copiazaText(altul.tipCamera);
	}

	//
	Hotel& operator=(const Hotel& altul)

	{


		// verificare autoasignare
		if (this != &altul) 

		{
			numarStele = altul.numarStele; 
			micDejunInclus = altul.micDejunInclus; 
			numarCamere = altul.numarCamere; 
			setCamereDisponibile(altul.camereDisponibile); 
			pretPeNoapte = altul.pretPeNoapte; 
			setNumeHotel(altul.numeHotel); 
			setTipCamera(altul.tipCamera); 
		} 
		return *this;  
	}
	   
	//destructor
	~Hotel()
	{ 
		delete[] numeHotel;          
		delete[] tipCamera; 
	}  

	                     


	int getNumarStele() const   
	{
		return numarStele;  
	}


	                             


	bool getMicDejunInclus() const  
	{
		return micDejunInclus; 
	}  
	  

	int getCamereDisponibile() const 
	{  
		return camereDisponibile; 
	}  

	   
	int getNumarCamere() const
	{  
		return numarCamere;
	} 
	 

	float getPretPeNoapte() const
	{ 
		return pretPeNoapte;
	} 
	  

	const char* getNumeHotel() const
	{
		 
		return numeHotel; 
	}


	const char* getTipCamera() const
	{

		return tipCamera;
	}
	 
	 
	void setNumarStele(int numarStele)
	{
		this->numarStele = min(5, max(1, numarStele));


	}
	  
	 
	void setMicDejunInclus(bool micDejunInclus)   
	{
		this->micDejunInclus = micDejunInclus;
		 
	} 
	   

	 
	void setCamereDisponibile(int camereDisponibile)
	{ 
		this->camereDisponibile = min(numarCamere, max(0, camereDisponibile));
	} 
	   

	void setNumarCamere(int numarCamere)  
	{
		this->numarCamere = max(0, numarCamere);

		if (camereDisponibile > this->numarCamere)

		{
			camereDisponibile = this->numarCamere;
		}
		 
		  
		  
	}
	 
	// setteri pentru pretPeNoapte numeHotel si tipCamera
	void setPretPeNoapte(float pretPeNoapte)
	{  
		this->pretPeNoapte = max(0.0f, pretPeNoapte); 
		  
	}  
	  

	// /
	void setNumeHotel(const char* numeHotel) 
	{  
		char* numeNou = copiazaText(numeHotel);
		delete[] this->numeHotel;
		this->numeHotel = numeNou;
 
	}
	 

	  // 
	void setTipCamera(const char* tipCamera)
	{
		char* tipNou = copiazaText(tipCamera);
		delete[] this->tipCamera;
		this->tipCamera = tipNou;


	}


	  
	// supraincarcare operator-= pentru rezervarea camerelor
	Hotel& operator-=(int camereRezervate)   
	{
		if (camereRezervate > 0)
			   
		{
			setCamereDisponibile(camereDisponibile - camereRezervate);
		}  

		return *this; 
		  

	} 

	 
	// supraincarcare operator<< pentru afisarea obiectului Hotel
	friend ostream& operator<<(ostream& iesire, const Hotel& hotel)   

	{
		iesire << "Hotel:   " << hotel.getNumeHotel()     
			<< ", tip camera:  " << hotel.getTipCamera()   
			<< ", stele:   " << hotel.getNumarStele()   
			<< ", mic  dejun inclus: " << (hotel.getMicDejunInclus() ? "da" : "nu")   
			<< ",  camere disponibile: " << hotel.getCamereDisponibile() << "/" << hotel.getNumarCamere()    
			<< ",  pret/noapte: " << fixed << setprecision(2) << hotel.getPretPeNoapte() << " lei" << endl; 
		return iesire;   
	}   
	 

	  
};
 
 

//initializare membru static care se pune la inceputul main-ului inafara clasei
int Hotel::numarator = 0;   
 
  


int main()   
   

{
	//testare clasa Hotel		
	Hotel cazare("Hotel Central  ", "dubla   ", 4, true, 350.0f, 80, 35);  
	cout << "Date   cazare :" << endl;   
	cout << cazare;   
	 
	  
	//rezervare camere
	cazare -= 3;   
	cout << " D upa rezervarea a 3 camere:" << endl; 
	cout << cazare;   
	  
	 
	//testare constructor cu parametri
	Hotel pensiune("Pensiunea Verde   ", "single ", 3, false, 220.0f, 20, 12);   
	cout << " A  doua unitate de cazare:  " << endl;   
	cout << pensiune;    
	 
	 
	//testare constructor de copiere
	Hotel unitati[2]; 
	unitati[0].setNumeHotel(" hotel Lacul Albastru"); 
	unitati[0].setTipCamera(" apartament"); 
	unitati[0].setNumarCamere(15); 
	unitati[0].setCamereDisponibile(8); 
	unitati[0].setPretPeNoapte(480.0f); 
	unitati[0].setMicDejunInclus(true);   
	unitati[0].setNumarStele(5); 
	//testare operator=
	cout << "Unitate confi prin setteri" << endl; 
	cout << unitati[0]; 
	  
	 

	   
	return 0; 

	  
}







