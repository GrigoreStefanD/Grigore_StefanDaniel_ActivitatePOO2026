#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS
//#define _CRT_SECURE_NO_WARNIGS_GLOBALS//asta este cod pentru a folosi strcpy si strcat la nivel global

#include <iostream>// pentru cout si cin
#include <cstring>
#include <string>

#include <iomanip>// 

#include <stdexcept>// pentru exceptii asta e cod pentru  a folosi exceptii de tip invalid_argument

using namespace std;

////  aici avem o aplicatie de gestiune a unei cartilor  
//  functii adaugare cart stergere carte modificare carte afisare carte afisare toate cartile
//V_8 dupa eroare afisare carte 
//V_9 dupa eroare afisare toate cartile//
//  
// neterminat
// 

class Carte
{
private:
    
    char* nume;
    string autor;
    bool citita;
    int nrPagini;
    int nrRecenzii;
     float pret;
    string editura;
    // atribut nou: retinem ratingul cartii intre 1 si 5
    float rating;





public:
    // constructor implicit cu valori prestabilite
    Carte()
    {
        // initializam pointerul cu nullptr
        nume = nullptr;
        //    atribuim titlul folosind setterul
        setNume("vanatorii ");
          //   initializam autorul
        autor = "hamlet";
           //   initializam starea de citire
        citita = true;
         //   initializam numarul de pagini
        nrPagini = 400;
           //  initializam numarul de recenzii
        nrRecenzii = 30;
         // initializam pretul cartii
        pret = 30.0f; 
        editura = "edituraA"; 
      // initializam ratingul 
        rating = 4.5f;  



    }

    // constructor cu toti cei opt parametri
    Carte(const char* pNume, string pAutor, bool pCitita,  int pNrPagini, int pNrRecenzii, float pPret, string pEditura, float pRating)


    {
        // initializam pointerul inainte de alocarea memoriei
        nume = nullptr;
         
        // verificam daca titlul este valid
        if (pNume == nullptr || strlen(pNume) < 2) 
            throw invalid_argument("titlul nu este valid"); 
         
        // verificam daca autorul este completat 
        if (pAutor.empty())
            throw invalid_argument("autorul nu poate fi gol"); 
          
        // verificam numarul minim de pagini 
        if (pNrPagini < 20) 
            throw invalid_argument("cartea trebuie sa aiba cel putin 20 de pagini"); 

        // verificam numarul minim de recenzii 
        if (pNrRecenzii < 1) 
            throw invalid_argument("numarul de recenzii trebuie sa fie pozitiv"); 



         // verificam pretul minim
        if (pPret < 5)
            throw invalid_argument("pretul trebuie sa fie cel putin 5");

         // verificam daca editura este completata
        if (pEditura.empty())
            throw invalid_argument("editura nu poate fi goala");

        // verificam daca ratingul se afla intre 1 si 5
        if (pRating < 1 || pRating > 5)
            throw invalid_argument("ratingul trebuie sa fie intre 1 si 5");

        // copiem titlul in memoria proprie a obiectului
        setNume(pNume);
         
        // initializam autorul
        autor = pAutor; 
         
        // initializam starea de citire
        citita = pCitita; 
         
        // initializam numarul de pagini
        nrPagini = pNrPagini; 
         
        // initializam numarul de recenzii
        nrRecenzii = pNrRecenzii;
         
        // initializam pretul
        pret = pPret; 
             
        // initializam editura 
        editura = pEditura; 
            
         
         
         
        // initializam ratingul
    
        rating = pRating;  



    }

      



    // constructor cu patru parametri
    Carte(const char* pNume, string pAutor,bool pCitita, float pPret)
    {


        // initializam pointerul inainte de alocarea memoriei
        nume = nullptr;

        // verificam titlul
        if (pNume == nullptr || strlen(pNume) < 2)
            throw invalid_argument("titlul nu este valid");

        // verificam autorul
        if (pAutor.empty())
            throw invalid_argument("autorul nu poate fi gol");

        // verificam pretul
        if (pPret < 5)
            throw invalid_argument("pretul trebuie sa fie cel putin 5");

        // copiem titlul in memoria proprie
        setNume(pNume);

        // initializam autorul
        autor = pAutor;

        // initializam starea de citire
        citita = pCitita;
                               
        // folosim zero deoarece numarul de pagini nu a fost furnizat   
        nrPagini = 0; 
         
        // folosim zero deoarece numarul de recenzii nu a fost furnizat   
        nrRecenzii = 0;

        // initializam pretul
        pret = pPret;   
          
        // folosim o valoare implicita pentru editura
        editura = "necunoscuta";    
           
        // folosim zero pentru a indica lipsa ratingului
        rating = 0;
    }
       
    // constructor de copiere pentru o copie independenta a cartii
    Carte(const Carte& sursa)      
    {

        // initializam pointerul    
        nume = nullptr;
          
        // copiem titlul intr-o zona noua de memorie   
        setNume(sursa.nume);   

        // copiem autorul      
        autor = sursa.autor;     
             
        // copiem starea de citire       
        citita = sursa.citita;    

        // copiem numarul de pagini      
        nrPagini = sursa.nrPagini;   
           
        // copiem numarul de recenzii      
        nrRecenzii = sursa.nrRecenzii;   
           
        // copiem pretul  
        pret = sursa.pret;   

        // copiem editura   
        editura = sursa.editura;    

        // copiem ratingul     
        rating = sursa.rating;   

    }    


         
    // destructor care elibereaza memoria rezervata pentru titlu  
    ~Carte()
            
    { 
               // verificam daca pointerul indica o zona de memorie    
        if (nume != nullptr)   
        {  
                    // eliberam memoria alocata cu new[]   
            delete[] nume;
             
                 // resetam pointerul dupa eliberarea memoriei   
            nume = nullptr; 



        }   


    } 
     
        

                   // operator de atribuire pentru copierea corecta a unui obiect
    Carte& operator=(const Carte& sursa)

    {   
        // evitam atribuirea obiectului catre el insusi 
        if (this != &sursa) 
        {
            // copiem titlul intr-o zona separata de memorie 
            setNume(sursa.nume);

              // copiem autorul  
            autor = sursa.autor;  
               
              // copiem starea de citire
            citita = sursa.citita;  
 
            // copiem numarul de pagini    
            nrPagini = sursa.nrPagini;
              
            // copiem numarul de recenzii
            nrRecenzii = sursa.nrRecenzii; 

              // copiem pretul   
            pret = sursa.pret;
              
              // copiem editura  
            editura = sursa.editura;
             
            // copiem ratingul  
            rating = sursa.rating;
        }

             // returnam obiectul curent pentru a permite atribuiri in lant
        return *this;
    }

        // getter pentru titlu
    const char* getNume() const
    {
        // returnam titlul cartii
        return nume;
    }

    // setter pentru titlu
    void setNume(const char* pNume) 
    {
          // verificam daca titlul este valid 
        if (pNume == nullptr || strlen(pNume) < 2) 
            throw invalid_argument("titlul trebuie sa aiba cel putin doua caractere");
         
           // alocam memorie pentru noul titlu 
        char* copie = new char[strlen(pNume) + 1];
         
              // copiem titlul in memoria nou alocata 
        strcpy(copie, pNume);
          
          // eliberam memoria vechiului titlu
        delete[] nume;
         
         // actualizam pointerul cu noua adresa
        nume = copie;  
    }
      
    ///  // getter pentru autor
    string getAutor() const
    {
          // returnam autorul
        return autor;
    }
       
     // setter pentru autor  
    void setAutor(string pAutor)
    {
          // verificam daca autorul nu este gol
        if (pAutor.empty())
            throw invalid_argument("autorul nu poate fi gol");
  
           // actualizam autorul
        autor = pAutor;
    }  
     
     
        
     
         // getter pentru starea de citire
    bool getCitita() const
    {
        // returnam starea de citire 
        return citita;
    }  

     // setter pentru starea de citire
      void setCitita(bool pCitita)
    {
        // actualizam starea de citire
        citita = pCitita;
    }
     
      // getter pentru numarul de pagini 
     int getNrPagini() const 
    {  
        // returnam numarul de pagini
        return nrPagini;
    }
     
      // setter pentru numarul de pagini  
    void setNrPagini(int pNrPagini) 


    { 
        // verificam numarul minim de pagini
        if (pNrPagini < 20)
            throw invalid_argument("numarul de pagini trebuie sa fie cel putin 20");

        // actualizam numarul de pagini
        nrPagini = pNrPagini; 
         
         

    }

     
     
     
    // getter pentru numarul de recenzii
    int getNrRecenzii() const 
    { 
        // returnam numarul de recenzii
        return nrRecenzii;
    }
      

     
    // setter pentru numarul de recenzii
    void setNrRecenzii(int pNrRecenzii)
    { 
        // verificam daca exista cel putin o recenzie
        if (pNrRecenzii < 1) 
            throw invalid_argument("trebuie sa existe cel putin o recenzie"); 

        // actualizam numarul de recenzii 
        nrRecenzii = pNrRecenzii; 
         
         
    }  

        

     

    // getter pentru pret
    float getPret() const 
         
         
    {
        // returnam pretul
        return pret; 
    }
         


     
      // setter pentru pret
    void setPret(float pPret) 
    {
            // verificam pretul minim
        if (pPret < 5) 
            throw invalid_argument("pretul trebuie sa fie cel putin 5");
         
                  // actualizam pretul
        pret = pPret;
    }
      
     
     
       // getter pentru editura
    string getEditura() const
    {
           // returnam editura
        return editura;
    }
       
     
       // setter pentru editura
    void setEditura(string pEditura)
    { 
        // verificam daca editura este completata 
        if (pEditura.empty())
            throw invalid_argument("editura nu poate fi goala");  

        // actualizam editura
        editura = pEditura;
    }

       // getter pentru rating 
    float getRating() const
    {
          // returnam ratingul
        return rating; 
    }  
     
     

    // setter pentru rating
    void setRating(float pRating)
    {
        // verificam daca ratingul se afla intre 1 si 5
        if (pRating < 1 || pRating > 5)
            throw invalid_argument("ratingul trebuie sa fie intre 1 si 5");

        // actualizam ratingul 
        rating = pRating; 
    }
        
     
     

     
       // functie care calculeaza pretul dupa aplicarea unei reduceri 
    float calculeazaPretCuReducere(float procent) const
    {
        // verificam daca procentul este valid    
        if (procent < 0 || procent > 100)
            throw invalid_argument("reducerea trebuie sa fie intre 0 si 100"); 

        // calculam si returnam pretul redus
        return pret * (1 - procent / 100.0f);
    }
       
     
    // functie care afiseaza toate datele cartii
    void afiseaza() const
      {
        // afisam titlul
        cout << "titlu: " << nume << endl;

        // afisam titlul
        cout << "autor: " << autor << endl;
 
        //// afisam titlul 
        cout << "citita: " << (citita ? "da" : "nu") << endl;

          // afisam numarul de pagini
        cout << "numar pagini: " << nrPagini << endl;

          // afisam numarul de recenzii
        cout << "numar recenzii: " << nrRecenzii << endl;
          
          // afisam pretul cu doua zecimale 
        cout << fixed << setprecision(2);
        cout << "pret: " << pret << endl;

        // afisam   
        cout << "editura: " << editura << endl;

           // verificam daca ratingul este cunoscut
        if (rating == 0) 
        {
            // afisam mesajul pentru rating necunoscut 
             cout << "rating: necunoscut" << endl;
        } 
        else 
        {
                // afisam ratingul
             cout << "rating: " << rating << " din 5" << endl;
        }

        
        cout << "-------------- ---------------" << endl;
    }
};






int main()

{

    /// folosim try pentru a trata eventualele erori
    try



    {
          // cream un obiect folosind constructorul implicit
        Carte carte1;



           // afisam datele primei carti
        cout << "cartea 1 - constructor implicit" << endl;
        carte1.afiseaza();

          


            // cream un obiect folosind constructorul complet 
        Carte carte2(  "morometii",  "marin preda",  true,  320,   45,  40.0f,    "cartea romaneasca",   4.7f   );   


         
           // afisam datele celei de-a doua carti    
        cout << endl << "cartea 2 - constructor complet" << endl;
        carte2.afiseaza(); 
          
          // cream un obiect folosind constructorul cu patru parametri
        Carte carte3("ion", "liviu rebreanu", false, 25.0f);  
           
            // afisam datele celei de-a treia carti     
        cout << endl << "cartea 3 - constructor cu patru parametri" << endl;
        carte3.afiseaza();
            
        // cream o copie independenta a cartii 2 
        Carte carte4(carte2);
           
        // afisam datele copiei   
        cout << endl << "cartea 4 - constructor de copiere" << endl;
        carte4.afiseaza();  
            
        // cream un obiect nou folosind constructorul implicit
        Carte carte5; 
            
             // atribuim datele cartii 2 obiectului carte5
        carte5 = carte2; 
          
        // afisam rezultatul atribuirii
        cout << endl << "cartea 5 - operator de atribuire" << endl;
        carte5.afiseaza();
          
        // modificam titlul copiei pentru a verifica independenta memoriei
        carte4.setNume("morometii - editia noua");
             
           // afisam titlul modificat al copiei 
        cout << endl << "dupa modificarea copiei:" << endl;
        cout << "titlul cartii 4: " << carte4.getNume() << endl;

          
            // verificam daca titlul original a ramas neschimbat
        cout << "titlul cartii 2: " << carte2.getNume() << endl;

            
         
        // calculam pretul cartii 2 dupa o reducere de 20 la suta 
        float pretRedus = carte2.calculeazaPretCuReducere(20); 
          
         

           // afisam pretul redus 
        cout << endl << "pretul cartii 2 dupa reducere: "
            << pretRedus << endl;
           
 
        // modificam ratingul cartii 3  
        carte3.setRating(4.2f);

            

        // modificam editura cartii 3
        carte3.setEditura("editura noua");

            
         
        /// afisam cartea dupa modificari 
        cout << endl << "cartea 3 dupa modificari"  << endl;
        carte3.afiseaza();
           
              
         
           // testam tratarea unei valori invalide   
        try  
        {
              // incercam sa atribuim un pret mai mic decat limita permisa 
            carte2.setPret(2.0f);
        }
        
        catch (const exception& e)
        {
               // afisam mesajul erorii fara a opri restul programului 
            cout << endl << "eroare la modificarea pretului: " 
                << e.what() << endl; 
        } 
           
         
    }

     
    catch (const exception& e) 
    {
         
                // afisam erorile care nu au fost tratate in interior
        cout << "eroare: " << e.what() << endl;
         

              // returnam o valoare diferita de zero pentru a indica eroarea   
        return 1; 
    }

       
     
       // returnam zero daca programul terminat cu succes   
    return 0;

       
}

 
 
 
 

  


  


