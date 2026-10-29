 #define _CRT_SECURE_NO_WARNINGS 


 #include <iostream>      
 #include <string>    
 #include <vector>  
       

 using namespace std;              
              


 // simplu - fabrica cu vector si stergere        
 class Fabrica   

 {     
 private: 
	int id;            
	 string denumire;       
	 int nrAngajati;            
	 static int contor;           
 public:                
	 Fabrica() : id(++contor), denumire("default"), nrAngajati(0) 
	 {}                 
	 Fabrica(const string& den, int nr) : id(++contor), denumire(den), nrAngajati(nr)       
	 {}       
	 void afisare() const                
	

 {       


 cout << "id: " << id << " | " << denumire << "| angajati: " << nrAngajati << "\n";       


	 } 
 };
              
      

            
 int Fabrica::contor = 0;  
              



 
 int main()   
 {       
	 vector<Fabrica> v;     
	 v.emplace_back("alfa", 50);            
	 v.emplace_back("beta", 120);               
	 v.emplace_back("gamma", 30);                
             
	 cout << "inainte stergere:\n";               
	 for (size_t i = 0; i < v.size(); ++i)                
	 {     
		 cout << i + 1 << ") ";                  
		 v[i].afisare();     
	 }                  
    
	 // stergem elementul 1 (index 0) demonstrativ              
	 if (!v.empty()) v.erase(v.begin());        
     
	 cout << "dupa stergere:\n";               
	 for (size_t i = 0; i < v.size(); ++i)       
	 {  
		 cout << i + 1 << ") ";              
		 v[i].afisare();          
	 }             
       
	 return 0;  



       
 }            