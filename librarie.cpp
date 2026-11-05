 #define _CRT_SECURE_NO_WARNINGS           
 #include <iostream> 
 #include <string>        
            

 using namespace std;  
               
      
 // simplu - librarie cu pret per carte   
   
 class Librarie       
 {    

 private:  
	 const int id;           
	 string denumire; 
	 int nrCarti;          
	 float pretPerCarte;       
	 static int contor; // cont id  
 public:
 
	 // ctor def
                 
	 Librarie() : id(++contor), denumire("default"), nrCarti(0), pretPerCarte(0.0f)      
	 {}     
             
    


	 // ctor param 

              
	 Librarie(const string& den, int nr, float pret) : id(++contor), denumire(den), nrCarti(nr), pretPerCarte(pret)           
	 {}               
   
	 // afis info   
	 void afisare() const         
	 {             
		 cout << "id: " << id << "\n";    
		 cout << "denumire: " << denumire << "\n";  
		 cout << "nr carti: " << nrCarti << "\n";    
		 cout << "pret/carte: " << pretPerCarte << "\n";           
	 }
 

 };   
             
      
 int Librarie::contor = 0;                
       
        
 int main() 
   
 {                
	 // cre doua obiecte  
            
	 Librarie l1;           
	 l1.afisare();              
        
	 Librarie l2("biblioteca", 200, 25.0f); 
              
	 l2.afisare();    
      
	 return 0;  
     
 }      



   