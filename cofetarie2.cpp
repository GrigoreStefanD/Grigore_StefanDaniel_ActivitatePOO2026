 

#define _CRT_SECURE_NO_WARNINGS         
 #include <iostream> 
 #include <string>               
     
 using namespace std;        
             
 // simplu - citire denumire si nr locuri                 
 
class Cofetarie   
       
 {  
 
 private:        
	 const int id;                  
	 string denumire;           
	 int nrLocuri;        
	 static int contor;

  
 public: 
	 Cofetarie() : id(++contor), denumire("default"), nrLocuri(0)            
	 {
}   
        
	 Cofetarie(const string& den, int nr) : id(++contor), denumire(den), nrLocuri(nr)     
	 {
}  

         
	 void afisare() const 
     
	 {   
		 cout << "id: " << id << "\n";                 
		 cout << "denumire: " << denumire << "\n";            
		 cout << "nr locuri: " << nrLocuri << "\n";

  
	 } 

          
	 // citire simpla din cin        
	 static Cofetarie citire()
       
	 {        
		 string den;     
 
		 int nr; 
		 cout << "introdu denumire: ";        
		 
// folosim getline dupa un cin.ignore in cazul folosirii anterior 
   
		 getline(cin, den); 
 
		 if (den.empty()) getline(cin, den);
                  
		 cout << "introdu nr locuri: "; 
                
		 cin >> nr;   

		 cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
   
		 return Cofetarie(den, nr);  
             
	 }
 
  
 };     
         
 int Cofetarie::contor = 0;   

    
 
 int main() 
         
 {           
	 cout << "creare prin citire:\n";             
	 Cofetarie c = Cofetarie::citire();               
	 c.afisare();            
	 return 0;  


    
 }      