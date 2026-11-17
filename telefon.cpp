#include<iostream>
#include<string>
using namespace std;

class Telefon 
{

private:
	const int CODUnic;
	float MemorieTotala;
	int nrAplicatiiInstalate;
	float* MemorieOcupata;
public:
	Telefon(const int id) :CODUnic(id)
 {
		this->MemorieTotala = 0;
		this->nrAplicatiiInstalate = 0;
		this->MemorieOcupata = new float[1];
		this->MemorieOcupata[0] = NULL;

	}

	Telefon(const int ID, float mt, int nr, float* mo) : CODUnic(ID) {
		this->MemorieTotala = mt;
		if (this->MemorieOcupata != NULL) {
			this->nrAplicatiiInstalate = nr;
			this->MemorieOcupata = new float[nrAplicatiiInstalate];
			for (int i = 0; i < nrAplicatiiInstalate; i++) {
				this->MemorieOcupata[i] = mo[i];
			}
		}
		else {
			this->nrAplicatiiInstalate = nr;
			this->MemorieOcupata = NULL;
		}
	}

	void SetMem(float* newM, int nr) 
{
		if (this->MemorieOcupata != NULL)
 {
			delete[]this->MemorieOcupata;
		}
		this->nrAplicatiiInstalate = nr;
		this->MemorieOcupata = new float[nr];
		for (int i = 0; i < nr; i++) {
			this->MemorieOcupata[i] = newM[i];
		}
		
	}


	Telefon(const Telefon &t) : CODUnic(t.CODUnic) 
{
		this->MemorieTotala = t.MemorieTotala;
		if (this->MemorieOcupata != NULL) {
			this->nrAplicatiiInstalate = t.nrAplicatiiInstalate;
			this->MemorieOcupata = new float[nrAplicatiiInstalate];
			for (int i = 0; i < nrAplicatiiInstalate; i++) {
				this->MemorieOcupata[i] = t.MemorieOcupata[i];
			}
		}
		else {
			this->nrAplicatiiInstalate = 0;
			this->MemorieOcupata = NULL;
		}
	}

	~Telefon() {
		if (this->MemorieOcupata != NULL) {
			delete[]this->MemorieOcupata;
		}
	}

	float getMemorieTotale() {
		return this->MemorieTotala;
	}

	int getNrAplicatii() {
		return this->nrAplicatiiInstalate;
	}

	Telefon operator=(const Telefon &t)  {
		delete[]this->MemorieOcupata;

		this->MemorieTotala = t.MemorieTotala;
		if (this->MemorieOcupata != NULL) {
			this->nrAplicatiiInstalate = t.nrAplicatiiInstalate;
			this->MemorieOcupata = new float[nrAplicatiiInstalate];
			for (int i = 0; i < nrAplicatiiInstalate; i++) {
				this->MemorieOcupata[i] = t.MemorieOcupata[i];
			}
		}
		else {
			this->nrAplicatiiInstalate = 0;
			this->MemorieOcupata = NULL;
		}
		return *this;
	}

	friend ostream& operator<<(ostream&, Telefon);
	friend istream& operator>>(istream&, Telefon&);

	float operator[](int index) {
		if (index > 0 && index < nrAplicatiiInstalate) {
			return this->MemorieOcupata[index];
		}
		else {
			return -1;
		}
	}

	bool operator>(Telefon &t) {
		int t1 = t.MemorieTotala;
		int t2 = t.MemorieTotala;
		if (t1 > t2) {
			return true;
		}
		else {
			return false;
		}
	}
	

};

istream& operator>>(istream& intrare, Telefon &t) {
	
	cout << " introdu mem totala";
	float mem;
	intrare >> mem;
	cout << "total aplicatii";
	int nr;
	intrare >> nr;
	float* array = new float[nr];
	for (int i = 0; i < nr; i++) {
		cout << "memorie ocupata pt aplicatie " << i + 1 << ", ";
		intrare >> array[i];
	}
	t.SetMem(array, nr);
	delete[]array;
	return intrare;

}

ostream& operator<<(ostream& iesire, Telefon t) {
	iesire << "telefonul cu id" << t.CODUnic << " are o memorie de " << t.MemorieTotala << " si are " << t.nrAplicatiiInstalate << " aplicatii instalate, care ocupata ";
	for (int i = 0; i < t.nrAplicatiiInstalate; i++) {
		iesire <<", " <<t.MemorieOcupata[i] ;
		
	}
	iesire << endl;
	return iesire;
}


void main()
 {
	
		Telefon t1(100);
		cout << t1.getMemorieTotale() << endl;
		cout << t1.getNrAplicatii() << endl;
		int CODUnic = 100;
		float array[5] = { 100.09, 60.08, 60, 90, 50 };
		Telefon t2(100, 1000.00, 5, array);
		cout << t2.getNrAplicatii()<<endl;
		Telefon t3(t2);
		cout << t3.getMemorieTotale() << endl;
		float array2[2] = { 5.4, 6.8 };
		Telefon t4(200, 1000, 2, array2);
		t4 = t2;
		cout << t4.getNrAplicatii() << endl;
		cout << t2;

		cout << t2[1] << endl;
		
		Telefon t5(101);
		cin >> t5;
		cout << t5;
		
		
	
}