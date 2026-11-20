
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int id;
    string nume;
    int varsta;
    float medie;
    double inaltime;
    char initiala;
    bool bursier;

    int* nota;
    float* bonus;
    double* taxa;
    char* grupa;   
    bool* prezent;   
    string* facultate;
   
    const int codUniversitate;

    static int numarStudenti;   

public:
   
    Student() : codUniversitate(100)
    {   
        this->id = 0;   
        this->nume = "Necunoscut";
        this->varsta = 18;
        this->medie = 0;
        this->inaltime = 1.70;   
        this->initiala = '-';
        this->bursier = false;

        this->nota = new int(0);   
        this->bonus = new float(0);
        this->taxa = new double(0);   
        this->grupa = new char('-');
        this->prezent = new bool(false);   
        this->facultate = new string("Necunoscuta");
         
        Student::numarStudenti++;   

        cout << "Constructor fara parametri\n";   
    }
   

   
    Student(int id, string nume, int varsta, float medie,
            double inaltime, char initiala, bool bursier,
            int nota, float bonus, double taxa,   
            char grupa, bool prezent, string facultate)   
        : codUniversitate(200)
    {
        this->id = (id > 0) ? id : 1;
        this->nume = (!nume.empty()) ? nume : "Necunoscut";   
        this->varsta = (varsta >= 18 && varsta <= 100) ? varsta : 18;
        this->medie = (medie >= 1 && medie <= 10) ? medie : 1;
        this->inaltime = (inaltime >= 0.5 && inaltime <= 2.5) ? inaltime : 1.70;
        this->initiala = initiala;   
        this->bursier = bursier;
   
        this->nota = new int((nota >= 1 && nota <= 10) ? nota : 1);   
        this->bonus = new float((bonus >= 0) ? bonus : 0);   
        this->taxa = new double((taxa >= 0) ? taxa : 0);      
        this->grupa = new char(grupa);                     v
        this->prezent = new bool(prezent);
        this->facultate = new string(facultate);
   
        Student::numarStudenti++;

        cout << "Constructor cu parametri\n";
    }   



    Student(const Student& s)   
        : codUniversitate(s.codUniversitate)
    {
        this->id = s.id;
        this->nume = s.nume;
        this->varsta = s.varsta;
        this->medie = s.medie;      
        this->inaltime = s.inaltime;
        this->initiala = s.initiala;
        this->bursier = s.bursier;

        this->nota = new int(*s.nota);               
        this->bonus = new float(*s.bonus);
        this->taxa = new double(*s.taxa);   
        this->grupa = new char(*s.grupa);   
        this->prezent = new bool(*s.prezent);   
        this->facultate = new string(*s.facultate);

        Student::numarStudenti++;   
   
        cout << "Constructor de copiere\n";
    }   


    Student& operator=(const Student& s)      
    {
        if (this != &s)
        {   
            this->id = s.id;
            this->nume = s.nume;   
            this->varsta = s.varsta;
            this->medie = s.medie;
            this->inaltime = s.inaltime;   
            this->initiala = s.initiala;
            this->bursier = s.bursier;

            *(this->nota) = *(s.nota);
            *(this->bonus) = *(s.bonus);   
            *(this->taxa) = *(s.taxa);   
            *(this->grupa) = *(s.grupa);
            *(this->prezent) = *(s.prezent);
            *(this->facultate) = *(s.facultate);   
        }

        return *this;
    }   
   
   

    ~Student()
    {
        delete this->nota;   
        delete this->bonus;
        delete this->taxa;      
        delete this->grupa;
        delete this->prezent;
        delete this->facultate;   

        Student::numarStudenti--;

        cout << "Destructor: " << this->nume << endl;
    }

    int getId() const   
    {
        return this->id;
    }

    string getNume() const
    {
        return this->nume;
    }

    int getVarsta() const   
    {
        return this->varsta;
    }

    float getMedie() const
    {   
        return this->medie;
    }

    double getInaltime() const
    {
        return this->inaltime;
    }

    char getInitiala() const
    {
        return this->initiala;
    }   

    bool getBursier() const
    {
        return this->bursier;
    }

    int getNota() const
    {
        return *(this->nota);
    }

    float getBonus() const
    {
        return *(this->bonus);
    }

    double getTaxa() const
    {
        return *(this->taxa);
    }

    char getGrupa() const
    {
        return *(this->grupa);
    }

    bool getPrezent() const
    {
        return *(this->prezent);
    }

    string getFacultate() const
    {
        return *(this->facultate);
    }

    int getCodUniversitate() const
    {
        return this->codUniversitate;
    }

    static int getNumarStudenti()
    {
        return Student::numarStudenti;
    }

    void setId(int id)
    {
        if (id > 0)
        {
            this->id = id;
        }
        else
        {
            cout << "ID invalid!\n";
        }
    }



    void setNume(string nume)
    {
        if (!nume.empty())
        {
            this->nume = nume;
        }
        else
        {
            cout << "Nume invalid!\n";   
        }
    }



    void setVarsta(int varsta)   
    {
        if (varsta >= 18 && varsta <= 100)
        {
            this->varsta = varsta;
        }
        else                     
        {
            cout << "Varsta invalida!\n";
        }
    }
   


    void setMedie(float medie)
    {
        if (medie >= 1 && medie <= 10)
        {
            this->medie = medie;
        }   
        else   
        {
            cout << "Medie invalida!\n";
        }      
    }

    void setInaltime(double inaltime)   
    {
        if (inaltime >= 0.5 && inaltime <= 2.5)
        {
            this->inaltime = inaltime;
        }
        else
        {   
            cout << "Inaltime invalida!\n";
        }
    }

    void setInitiala(char initiala)
    {   
        this->initiala = initiala;
    }

    void setBursier(bool bursier)
    {
        this->bursier = bursier;   
    }

    void setNota(int nota)
    {
        if (nota >= 1 && nota <= 10)
        {
            *(this->nota) = nota;
        }
        else
        {
            cout << "Nota invalida!\n";
        }
    }   



    void setBonus(float bonus)
    {
        if (bonus >= 0)
        {
            *(this->bonus) = bonus;
        }
        else
        {
            cout << "Bonus invalid!\n";
        }
    }

    void setTaxa(double taxa)
    {
        if (taxa >= 0)
        {
            *(this->taxa) = taxa;
        }
        else
        {
            cout << "Taxa invalida!\n";
        }
    }



    void setGrupa(char grupa)
    {
        *(this->grupa) = grupa;
    }

    void setPrezent(bool prezent)
    {
        *(this->prezent) = prezent;
    }

    void setFacultate(string facultate)
    {
        if (!facultate.empty())
        {
            *(this->facultate) = facultate;
        }
        else
        {
            cout << "Facultate invalida!\n";
        }
    }



    void citire()
    {
        cout << "ID: ";
        cin >> this->id;

        cout << "Nume: ";
        cin >> ws;
        getline(cin, this->nume);

        do
        {
            cout << "Varsta (18-100): ";
            cin >> this->varsta;
        }
        while (this->varsta < 18 || this->varsta > 100);

        do
        {
            cout << "Medie (1-10): ";
            cin >> this->medie;
        }
        while (this->medie < 1 || this->medie > 10);

        cout << "Inaltime: ";
        cin >> this->inaltime;

        cout << "Initiala: ";
        cin >> this->initiala;

        cout << "Bursier (0/1): ";
        cin >> this->bursier;

        do
        {
            cout << "Nota (1-10): ";
            cin >> *(this->nota);
        }
        while (*(this->nota) < 1 || *(this->nota) > 10);

        do
        {
            cout << "Bonus: ";
            cin >> *(this->bonus);
        }
        while (*(this->bonus) < 0);

        do
        {
            cout << "Taxa: ";
            cin >> *(this->taxa);
        }
        while (*(this->taxa) < 0);

        cout << "Grupa: ";
        cin >> *(this->grupa);

        cout << "Prezent (0/1): ";
        cin >> *(this->prezent);

        cout << "Facultate: ";
        cin >> ws;
        getline(cin, *(this->facultate));
    }



    void afisare(ostream& out) const
    {
        out << "\n----- STUDENT -----\n";
        out << "ID: " << this->id << endl;
        out << "Nume: " << this->nume << endl;
        out << "Varsta: " << this->varsta << endl;
        out << "Medie: " << this->medie << endl;
        out << "Inaltime: " << this->inaltime << endl;
        out << "Initiala: " << this->initiala << endl;
        out << "Bursier: " << this->bursier << endl;

        out << "\n--- Atribute dinamice ---\n";
        out << "Nota: " << *(this->nota) << endl;
        out << "Bonus: " << *(this->bonus) << endl;
        out << "Taxa: " << *(this->taxa) << endl;
        out << "Grupa: " << *(this->grupa) << endl;   
        out << "Prezent: " << *(this->prezent) << endl;
        out << "Facultate: " << *(this->facultate) << endl;

        out << "Cod universitate: " << this->codUniversitate << endl;
        out << "Numar studenti: " << Student::numarStudenti << endl;
    }     
   

    friend istream& operator>>(istream& in, Student& s)
    {
        s.citire();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s)
    {
        s.afisare(out);
        return out;
    }
};

     


int Student::numarStudenti = 0;     




int main()                
{
    cout << "\n===== TEST 1: CONSTRUCTOR FARA PARAMETRI =====\n";
 
    Student s1;
    cout << s1; 

    cout << "\n===== TEST 2: CONSTRUCTOR CU PARAMETRI =====\n";
 
    Student s2(1, "Andrei Popescu", 20, 9.50,
               1.80, 'A', true,
               10, 100.5, 2500, 'B', true,
               "Informatica");                                    

    cout << s2;

    cout << "\n===== TEST 3: CONSTRUCTOR DE COPIERE =====\n";

    Student s3(s2);
    cout << s3;

    cout << "\n===== TEST 4: OPERATOR ATRIBUIRE =====\n";

    s1 = s2;
    cout << s1;

    cout << "\n===== TEST 5: GETTERI =====\n";

    cout << "ID: " << s2.getId() << endl;
    cout << "Nume: " << s2.getNume() << endl;
    cout << "Varsta: " << s2.getVarsta() << endl;
    cout << "Medie: " << s2.getMedie() << endl;
    cout << "Inaltime: " << s2.getInaltime() << endl;
    cout << "Initiala: " << s2.getInitiala() << endl;
    cout << "Bursier: " << s2.getBursier() << endl;
    cout << "Nota: " << s2.getNota() << endl;
    cout << "Bonus: " << s2.getBonus() << endl;
    cout << "Taxa: " << s2.getTaxa() << endl;
    cout << "Grupa: " << s2.getGrupa() << endl;
    cout << "Prezent: " << s2.getPrezent() << endl;
    cout << "Facultate: " << s2.getFacultate() << endl;
    cout << "Cod universitate: " << s2.getCodUniversitate() << endl;

    cout << "\n===== TEST 6: SETTERI =====\n";

    s2.setId(2);
    s2.setNume("Maria Ionescu");
    s2.setVarsta(21);
    s2.setMedie(9.90);
    s2.setInaltime(1.65);
    s2.setInitiala('M');
    s2.setBursier(true);
    s2.setNota(10);
    s2.setBonus(200);
    s2.setTaxa(3000);
    s2.setGrupa('A');
    s2.setPrezent(true);
    s2.setFacultate("Matematica");

    cout << s2;

    cout << "\n===== TEST 7: VALIDARI =====\n";

    s2.setId(-5);
    s2.setNume("");
    s2.setVarsta(150);
    s2.setMedie(15);
    s2.setInaltime(5);
    s2.setNota(-5);
    s2.setBonus(-100);
    s2.setTaxa(-200);
    s2.setFacultate(""); 
    cout << "\n===== TEST 8: CITIRE ISTREAM =====\n"; 
 
    Student s4;
    cin >> s4; 

    cout << "\n===== TEST 9: AFISARE OSTREAM =====\n"; 

    cout << s4; 

    cout << "\n===== TEST 10: ATRIBUT STATIC =====\n"; 
 
    cout << "Numar obiecte existente: " 
         << Student::getNumarStudenti() << endl;

    cout << "\n===== SFARSIT PROGRAM =====\n"; 

    return 0;



}



