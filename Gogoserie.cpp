#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <set>

using namespace std;


class Gogoserie
{
	const int codActivitate;
	string numeGogoserie;
	char* locatie;
	float suprafata;


public:

	//constructorul fara parametri
	Gogoserie() :codActivitate(0)
	{

		this->numeGogoserie = "Necunoscut";
		this->locatie = new char[strlen("Necunoscuta") + 1];
		strcpy(this->locatie, "Necunoscuta");
		this->suprafata = 0;

	}


	//constructorul cu parametri
	Gogoserie(string numeGogoserie, const char* locatie, float suprafata) :codActivitate(321)
	{
		this->numeGogoserie = numeGogoserie;
		this->locatie = new char[strlen(locatie) + 1];
		strcpy(this->locatie, locatie);
		this->suprafata = suprafata;

	}

	//Getteri
	const int getcodActivitate()
	{
		return this->codActivitate;
	}
	string getNumeGogoserie()
	{
		return this->numeGogoserie;
	}
	char* getLocatie()
	{
		return this->locatie;
	}

	float getSuprafata()
	{
		return this->suprafata;
	}

	//Setteri
	void setNumeGogoserie(string numeGogoserie)
	{
		this->numeGogoserie = numeGogoserie;
	}
	void setLocatie(const char* locatie)
	{
		if (this->locatie != NULL)
		{
			delete[] this->locatie;
		}
		this->locatie = new char[strlen(locatie) + 1];
		strcpy(this->locatie, locatie);

	}


	void setSuprafata(float suprafata)
	{
		this->suprafata = suprafata;
	}

	void afisare()
	{
		cout << "Cod Activitate: " << this->codActivitate << endl;
		cout << "Numele Gogoseriei este: " << this->numeGogoserie << endl;
		cout << "Locatia Gogoseriei este: " << this->locatie << endl;
		cout << "Suprafata Gogoseriei este: " << this->suprafata << " m2" << endl;

	}

	//constructorul de copiere
	Gogoserie(const Gogoserie& g) :codActivitate(g.codActivitate)
	{
		this->numeGogoserie = g.numeGogoserie;
		this->locatie = new char[strlen(g.locatie) + 1];
		strcpy(this->locatie, g.locatie);
		this->suprafata = g.suprafata;

	}

	//destructor 
	~Gogoserie()
	{
		if (this->locatie != NULL)
		{
			delete[] this->locatie;
		}

	}


	//operator = 
	Gogoserie& operator=(const Gogoserie& g)
	{
		if (this != &g)
		{
			if (this->locatie != NULL)
			{
				delete[] this->locatie;
			}

			this->numeGogoserie = g.numeGogoserie;
			this->locatie = new char[strlen(g.locatie) + 1];
			strcpy(this->locatie, g.locatie);
			this->suprafata = g.suprafata;

		}
		return *this;
	}


	//operator de afisare
	friend ostream& operator<<(ostream& out, const Gogoserie g)
	{
		out << "Cod Activitate: " << g.codActivitate << endl;
		out << "Numele Gogoseriei este: " << g.numeGogoserie << endl;
		out << "Locatia Gogoseriei este: " << g.locatie << endl;
		out << "Suprafata Gogoseriei este: " << g.suprafata << "mp." << endl;
		return out;
	}

	

};


class Cartier
{
	string nume;
	int nrGogoserii;
	Gogoserie* Gogoserii;
	float taxa;
	bool avizISU;
public:

	//constructorul fara parametri
	Cartier()
	{
		this->nume = "Necunoscut";
		this->nrGogoserii = 0;
		this->Gogoserii = NULL;
		this->taxa = 0;
		this->avizISU = true;

	}

	//constructorul cu parametri 
	Cartier(string nume, int nrGogoserii, Gogoserie* Gogoserii, float taxa, bool avizISU)
	{
		this->nume = nume;
		this->nrGogoserii = nrGogoserii;
		this->Gogoserii = new Gogoserie[this->nrGogoserii];
		for (int i = 0; i < nrGogoserii; i++)
		{
			this->Gogoserii[i] = Gogoserii[i];
		}
		this->taxa = taxa;
		this->avizISU = avizISU;

	}

	//constructorul de copiere
	Cartier(const Cartier& c)
	{
		this->nume = c.nume;
		this->nrGogoserii = c.nrGogoserii;
		this->Gogoserii = new Gogoserie[this->nrGogoserii];
		for (int i = 0; i < this->nrGogoserii; i++)
		{
			this->Gogoserii[i] = c.Gogoserii[i];
		}
		this->taxa = c.taxa;
		this->avizISU = c.avizISU;
	}

	//operator = 
	Cartier& operator=(const Cartier& c)
	{
		if (this != &c)
		{
			if (this->Gogoserii != NULL)
			{
				delete[] this->Gogoserii;
			}

			this->nume = c.nume;
			this->nrGogoserii = c.nrGogoserii;
			this->Gogoserii = new Gogoserie[this->nrGogoserii];
			for (int i = 0; i < this->nrGogoserii; i++)
			{
				this->Gogoserii[i] = c.Gogoserii[i];
			}
			this->taxa = c.taxa;
			this->avizISU = c.avizISU;
		}
		return *this;
	}

	~Cartier()
	{
		delete[]this->Gogoserii;
	}


	friend ostream& operator<<(ostream& out, const Cartier c)
	{
		out << "Nume: " << c.nume << endl << "nrGogoserii: " << c.nrGogoserii << endl;
		for (int i = 0; i < c.nrGogoserii; i++)
		{

			out << c.Gogoserii[i] << endl << endl;
		}
		out << "Taxa: " << c.taxa << endl;
		out << "Aviz ISU (1 = Da,0 = Nu): " << c.avizISU << endl;
		return out;
	}


	friend istream& operator>>(istream& in, Cartier& c)
	{
		if (c.Gogoserii != NULL)
		{
			delete[]c.Gogoserii;
		}

		cout << "Nume: ";
		in >> c.nume;

		cout << "nrGogoserii: ";
		in >> c.nrGogoserii;

		cout << "Taxa: ";
		in >> c.taxa;

		cout << "Aviz ISU (1 = Da,0 = Nu): ";
		in >> c.avizISU;

		return in;
	}

};


void main()
{

	Gogoserie g1;
	cout << g1.getcodActivitate() << endl;
	cout << g1.getNumeGogoserie() << endl;
	cout << g1.getLocatie() << endl;
	cout << g1.getSuprafata() << endl;
	cout << "_____________\n";

	Gogoserie g2("La Gogoasa Fermecata", "Mihai Bravu", 75.5);
	cout << g2.getcodActivitate() << endl;
	cout << g2.getNumeGogoserie() << endl;
	cout << g2.getLocatie() << endl;
	cout << g2.getSuprafata() << endl;
	cout << "_____________\n";

	Gogoserie g3;
	g3.setNumeGogoserie("Coca Framantata");
	g3.setLocatie("Ferentari Noi");
	g3.setSuprafata(55.5);
	g3.afisare();
	cout << "_____________\n";

	cout << "Constructor de copiere\n";
	Gogoserie g4 = g3;
	g4.afisare();
	cout << "_____________\n";

	cout << "Operator =\n";
	g1 = g1;
	g1.afisare();
	cout << "_____________\n";

	Cartier c1;
	cout << c1 << endl;
	Gogoserie Gogoserii[] = { g1,g2 };
	Gogoserie* Gogoserii2 = new Gogoserie[2];
	Gogoserii2[0] = g1;
	Gogoserii2[1] = g2;
	Cartier c2("Bucurestii Noi", 2, Gogoserii, 1400, true);
	cout << c2 << endl;
	Cartier c3;
	c3 = c2;
	cout << c3 << endl;
	/*Cartier c4;
	cin >> c4;*/

}
