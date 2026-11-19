#define _CRT_SECURE_NO _WARNINGS


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <set>
using namespace std;


class Gardian
{
public:

	string nume;
	int ani;
	float medieProbe;
	bool vaccinat;
	char gradProfesional;
	static int nrGardieni;
	double salariu;

	//constructorul fara parametri
	Gardian()
	{
		this->nume = "Nespecificat";
		this->ani = 0;
		this->medieProbe = 0;
		this->vaccinat = false;
		this->gradProfesional = ' ';
		this->salariu = 0.0;
		Gardian::nrGardieni++;
		cout << "S-a apelat constructorul fara parametri" << "\n---" << endl;
	}
	//constructorul cu parametri 
	Gardian(string n, int a, float mP, bool v, char gP, double s)
	{
		this->nume = n;
		this->ani = a;
		this->medieProbe = mP;
		this->vaccinat = v;
		this->gradProfesional = gP;
		this->salariu = s;
		Gardian::nrGardieni++;
		cout << "S-a apelat constructorul cu parametri" << "\n---" << endl;
	}
	//constructorul de copiere
	Gardian(Gardian& g)
	{
		this->nume = g.nume;
		this->ani = g.ani;
		this->medieProbe = g.medieProbe;
		this->vaccinat = g.vaccinat;
		this->gradProfesional = g.gradProfesional;
		this->salariu = g.salariu;
		Gardian::nrGardieni++;
		cout << "S-a apelat constructorul de copiere" << "\n---" << endl;
	}

	//supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& out, Gardian& g)
	{
		out << "nume: " << g.nume << endl;
		out << "ani: " << g.ani << endl;
		out << "medieProbe: " << g.medieProbe << endl;
		out << "vaccinat: " << g.vaccinat << endl;
		out << "gradProfesional: " << g.gradProfesional << endl;
		out << "salariu: " << g.salariu << endl;
		out << "total gardieni: " << g.nrGardieni << endl;
		return out;
	}

};
int Gardian::nrGardieni = 0;

class Scoala
{
public:

	string nume;
	int id;
	float suprafata;
	char tipScoala;
	bool avizSanitar;
	static int nrScoli;
	Gardian* gardieni;
	int nrGardieni;



	//constructorul fara parametri
	Scoala()
	{
		this->nume = "Nespecificat";
		this->id = 0;
		this->suprafata = 0;
		this->tipScoala = ' ';
		this->avizSanitar = false;
		this->gardieni = NULL;
		this->nrGardieni = 0;
		Scoala::nrScoli++;
		cout << "S-a apelat constructorul fara parametri" << "\n---" << endl;
	}

	//constructorul cu parametri
	Scoala(string nu, int i, float s, char tS, bool aS)
	{
		this->nume = nu;
		this->id = i;
		this->suprafata = s;
		this->tipScoala = tS;
		this->avizSanitar = aS;
		Scoala::nrScoli++;
		cout << "S-a apelat constructorul cu parametri" << "\n---" << endl;
	}

	Scoala(Gardian* Gardieni, int nrGardian)
	{
		this->nrGardieni = nrGardian;
		this->gardieni = new Gardian[this->nrGardieni];
		for (int i = 0; i < this->nrGardieni; i++)
		{
			this->gardieni[i] = Gardieni[i];

		}
	}

	//constructorul de copiere
	Scoala(Scoala& s)
	{
		this->nume = s.nume;
		this->id = s.id;
		this->suprafata = s.suprafata;
		this->tipScoala = s.tipScoala;
		this->avizSanitar = s.avizSanitar;
		this->nrGardieni = s.nrGardieni;
		this->gardieni = new Gardian[this->nrGardieni];
		for (int i = 0; i < this->nrGardieni; i++)
		{
			this->gardieni[i] = s.gardieni[i];

		}
		Scoala::nrScoli++;
		cout << "S-a apelat constructorul de copiere" << "\n---" << endl;
	}



	//supraincarcare operator <<
	friend ostream& operator<<(ostream out, Scoala& s)
	{
		out << "nume: " << s.nume << endl;
		out << "id: " << s.id << endl;
		out << "suprafata: " << s.suprafata << endl;
		out << "tipscoala: " << s.tipScoala << endl;
		out << "aviz sanitar: " << s.avizSanitar << endl;
		out << "nr gardieni:" << s.nrGardieni << endl;
		for (int i = 0; i < s.nrGardieni; i++)
		{
			out << s.gardieni[i] << endl;
		}
		out << "nr scoli: " << s.nrScoli << endl;
		return out;
	}
	//destructor
	~Scoala() {}

};
int Scoala::nrScoli = 0;


void main()
{
	Gardian g1;
	cout << g1 << endl;

	Gardian g2("George", 20, 7.8, true, 'A', 2.23);
	cout << g2 << endl;

	Gardian g3 = g2;
	cout << g3 << endl;

	Gardian vect[3] = { g1,g2,g3 };
	Scoala s1;
	Scoala s2(vect, 3);
	Scoala s3 = s1;
	Scoala s4("nu", 35, 2.4, 'P', true);
}