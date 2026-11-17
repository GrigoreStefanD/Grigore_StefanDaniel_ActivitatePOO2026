#include <iostream>
#include<fstream>
#include <conio.h>
#include <vector>
#include <map>



using namespace std;



class Spectacol 
{
private:
	int id;
	char* sala;
	int nrSpectatori;
	long double pretBilet;
	char data[17];

public:
	Spectacol(){
		id = 0;
		sala = new char[strlen("Sala") + 1];
		strcpy(sala, "Sala");	
		nrSpectatori = 0;
		pretBilet = 0.0;
		strcpy(data, "30/01/2016 18:23");
	}

	Spectacol(int id, char* sala, int nrSpectatori, long double pretBilet, char data[17])
 {
		this->id = id;
		this->sala = new char[strlen(sala) + 1];
		strcpy(this->sala, sala);
		this->nrSpectatori = nrSpectatori;
		this->pretBilet = pretBilet;
		strcpy(this->data, data);
	}

	Spectacol(const Spectacol &s)
 {
		this->id = s.id;
		this->sala = new char[strlen(s.sala) + 1];
		strcpy(this->sala, s.sala);
		this->nrSpectatori = s.nrSpectatori;
		this->pretBilet = s.pretBilet;
		strcpy(this->data, s.data);
	}

	~Spectacol() 
{
		delete[] sala;
	}

	void operator=(Spectacol s)
 {
		this->id = s.id;
		delete[] this->sala;
		this->sala = new char[strlen(s.sala) + 1];
		strcpy(this->sala, s.sala);
		this->nrSpectatori = s.nrSpectatori;
		this->pretBilet = s.pretBilet;
		strcpy(this->data, s.data);
	}

	void setSala(char* sala)
 {
		delete[] this->sala;
		this->sala = new char[strlen(sala) + 1];
		strcpy(this->sala, sala);
	}

	char* getSala() 
{
		return sala;
	}

	int getNrSpectatori() 
{
		return nrSpectatori;
	}

	long double getPretBilet() 
{
		return pretBilet;
	}

	virtual double getValoare()
 {
		return nrSpectatori * pretBilet;
	}

	friend ostream& operator << (ostream &out, Spectacol s) 
{
		out << "Id: " << s.id << endl;
		out << "Sala: " << s.sala << endl;
		out << "Numar spectatori: " << s.nrSpectatori << endl;
		out << "Pret bilet: " << s.pretBilet << endl;
		out << "Data: " << s.data << endl;
		out << endl;
		
		return out;
	}

	friend ofstream& operator << (ofstream &out, Spectacol s) 
{
		out << s.id << " ";
		out << s.sala << " ";
		out << s.nrSpectatori << " ";
		out << s.pretBilet << " ";
		out << s.data << " ";
		out << endl;

		return out;
	}

	friend istream& operator >> (istream &in, Spectacol &s)
 {
		char aux[50];
		cout << "Id: ";
		in >> s.id;
		cout << "Sala: ";
		in >> aux;
		delete[] s.sala;
		s.sala = new char[strlen(aux) + 1];
		strcpy(s.sala, aux);
		cout << "Numar spectatori: ";
		in >> s.nrSpectatori;
		cout << "Pret bilet: ";
		in >> s.pretBilet;
		cout << "Data: ";
		in >> s.data;
	
		cout << endl;

		return in;
	}

	friend ifstream& operator >> (ifstream &in, Spectacol &s)
 {
		char aux[50];
		in >> s.id;
		in >> aux;
		delete[] s.sala;
		s.sala = new char[strlen(aux) + 1];
		strcpy(s.sala, aux);
		in >> s.nrSpectatori;
		in >> s.pretBilet;

		in >> aux;
		strcat(aux, " ");
		strcpy(s.data, aux);
		in >> aux;
		strcat(s.data, aux);

		return in;
	}
};

class Cinematograf 
{
private:
	char denumire[30];
	int nrSpectacole;
	Spectacol *spectacole;

public:
	Cinematograf() 
{
		strcpy(this->denumire, "Cinematograf");
		nrSpectacole = 0;
		spectacole = NULL;
	}

	Cinematograf(char denumire[30], int nrSpectacole) 
{
		strcpy(this->denumire, denumire);
		this->nrSpectacole = nrSpectacole;
		this->spectacole = new Spectacol[this->nrSpectacole];
		for (int i = 0; i < this->nrSpectacole; i++) 
{
			this->spectacole[i] = Spectacol();
		}
	}

	Cinematograf(char denumire[30], Spectacol spectacol) 
{
		strcpy(this->denumire, denumire);
		this->nrSpectacole = 1;
		this->spectacole = new Spectacol[this->nrSpectacole];
		this->spectacole[0] = spectacol;
	}

	Cinematograf(const Cinematograf &c) 
{
		strcpy(this->denumire, c.denumire);
		this->nrSpectacole = c.nrSpectacole;
		this->spectacole = new Spectacol[this->nrSpectacole];
		
		for (int i = 0; i < c.nrSpectacole; i++)
 {
			this->spectacole[i] = c.spectacole[i];
		}
	}
	~Cinematograf(){}

	char* getDenumire() 
{
		return denumire;
	}

	operator double() 
{
		double valTot = 0;
		for (int i = 0; i < this->nrSpectacole; i++)
			valTot += this->spectacole[i].getValoare();

		return valTot;
	}

	Spectacol operator[](int i) {
		if (i > this->nrSpectacole - 1)
			throw std::invalid_argument("Nu exista atatea spectacole");

		else return this->spectacole[i];
	}

	Cinematograf operator+=(Spectacol o)
 {
		Spectacol *op = new Spectacol[this->nrSpectacole];
		for (int i = 0; i < this->nrSpectacole; i++) 
{
			op[i] = this->spectacole[i];
		}

		this->nrSpectacole++;
		delete[] this->spectacole;
		this->spectacole = new Spectacol[this->nrSpectacole];

		for (int i = 0; i < this->nrSpectacole - 1; i++)
			this->spectacole[i] = op[i];

		this->spectacole[this->nrSpectacole - 1] = o;

		return (*this);
	}

	Cinematograf operator-=(Spectacol o)
 {
		int k;
		Spectacol *op = new Spectacol[this->nrSpectacole];
		Spectacol *op2 = new Spectacol[this->nrSpectacole];

		for (int i = 0; i < this->nrSpectacole; i++)
 {
			op[i] = this->spectacole[i];
		}

		for (int i = 0; i < this->nrSpectacole; i++)
 {
			if (strcmp(op[i].getSala(), o.getSala()) == 0)
				k = i;
			else op2[i] = op[i];
		}

		if (k == this->nrSpectacole - 1) 
{
			this->nrSpectacole--;
			delete[] this->spectacole;
			this->spectacole = new Spectacol[this->nrSpectacole];

			for (int i = 0; i < this->nrSpectacole; i++)
				this->spectacole[i] = op2[i];
		}
		else
{
			for (int i = k; i < this->nrSpectacole - 1; i++)
				op2[i] = op2[i + 1];

			this->nrSpectacole--;
			delete[] this->spectacole;
			this->spectacole = new Spectacol[this->nrSpectacole];

			for (int i = 0; i < this->nrSpectacole; i++)
				this->spectacole[i] = op2[i];
		}

		return (*this);
	}

	friend ostream& operator << (ostream &out, Cinematograf c)
 {
		out << "Nume Cinema: " << c.denumire << endl;
		out << "Numar spectacole: " << c.nrSpectacole << endl;
		out << "Spectacole: " << endl;
		for (int i = 0; i < c.nrSpectacole; i++) 
{
			out << c.spectacole[i];
		}

		return out;
	}

	friend ofstream& operator << (ofstream &out, Cinematograf c)
 {
		out << c.denumire << endl;

		out << c.nrSpectacole << endl;
		for (int i = 0; i < c.nrSpectacole; i++)
 {
			out << c.spectacole[i] << " ";
		}

		return out;
	}

	friend istream& operator >> (istream &in, Cinematograf &c)
 {
		cout << "Nume Cinema: ";
		in >> c.denumire;
		cout << "Numar spectacole: ";
		in >> c.nrSpectacole;

		c.spectacole = new Spectacol[c.nrSpectacole];
		cout << "Spectacole: \n";
		for (int i = 0; i < c.nrSpectacole; i++)
 {
			in >> c.spectacole[i];
		}

		return in;
	}

	friend ifstream& operator >> (ifstream &in, Cinematograf &c)
 {
		in >> c.denumire;
		in >> c.nrSpectacole;

		c.spectacole = new Spectacol[c.nrSpectacole];
		for (int i = 0; i < c.nrSpectacole; i++)
 {
			in >> c.spectacole[i];
		}

		return in;
	}

};

class Spectacol3D : public Spectacol
{
private:
	int nrOchelari;
	float pretPereche;

public:
	Spectacol3D(int id, char* sala, int nrSpectatori, long double pretBilet, char data[17], int nrOchelari, float pretPereche) : Spectacol(id, sala, nrSpectatori, pretBilet, data) 
{
		this->nrOchelari = nrOchelari;
		this->pretPereche = pretPereche;
	}

	virtual double getValoare()
{
		return nrOchelari * pretPereche + getNrSpectatori() * getPretBilet();
	}

	friend ostream& operator << (ostream& out, Spectacol3D sd)
 {
		out << (Spectacol)sd;
		out << "Ochelari vanduti: " << sd.nrOchelari << endl;
		out << "Pret/pereche: " << sd.pretPereche << endl;

		return out;
	}
};




void main() 
{
	//4p
	Spectacol s1;
	Spectacol s2(1, "VIP", 13, 75, "22/01/2016 10:00");
	Spectacol s3(2, "Ground", 33, 25, "22/01/2016 12:00");
	cout << s1 << s2 << s3 << endl;
	s1.setSala("Gold");
	cout << s1.getSala() << endl;
	cout << s2.getValoare();
	cout << s1 << s2 << s3 << endl;
	Spectacol s4 = s1;
	cin >> s4;
	cout << s4;

	//1p
	Cinematograf c1;
	Cinematograf c2("Multiplex", 2);
	Cinematograf c3("Multiplex", s2);
	cin >> c1;
	cout << c1 << c2 << c3;

	//1p
	Cinematograf c4;	
	c4 += s1;
	c4 += s2;
	c4 += s3;

	cout << c4;
	c4 -= s1;
	cout << c4;

	//1p
	cout << "Valoarea incasarilor de la " << c4.getDenumire() << " este: " << (double)c4 << endl;

	try{
		cout << "Primul spectacol este: " << endl << c4[0];
		cout << "Al doilea spectacol este: " << endl << c4[10];
	}
	catch (const std::invalid_argument& e) 
{
		cout << "Index invalid";
	}

	//1p
	ofstream fisOut("cinema.txt");
	fisOut << c4;
	fisOut.close();
	Cinematograf c5;
	ifstream fisIn("cinema.txt");
	fisIn >> c5;
	cout << c5;

	//1p
	Spectacol3D sd(3, "Ground", 33, 25, "22/01/2016 12:00", 20, 5);
	cout << sd;
	c4 += sd;
	cout << (double)c4;

	//1p
	std::vector<Spectacol> spectacole;
	vector<Spectacol>::iterator i;
	spectacole.push_back(s1);
	spectacole.push_back(s2);
	spectacole.push_back(s3);
	spectacole.push_back(s4);
	spectacole.push_back(sd);


	for (i = spectacole.begin(); i != spectacole.end(); ++i) {
	
	cout << (*i);
	}
	
	std::map<string, int> superMap;
	typedef std::<string, int> element;

	_getch();

}