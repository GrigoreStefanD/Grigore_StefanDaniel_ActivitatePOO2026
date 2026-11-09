 #define _CRT_SECURE_NO_WARNINGS 
     
 #include <iostream>    
 #include <string>            
 #include <vector>                 
                  
 using namespace std;       
          

 // simplu - colectie si suma locuri  

          
 

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
		 cout << "id: " << id << " | " << denumire << " | locuri: " << nrLocuri << "\n";              
	 }                
	 int getLocuri() const 
    
	 { return nrLocuri; }  

          
 };                 
      

 int Cofetarie::contor = 0;      
      


           
 int main()  
     
 {           


	 vector<Cofetarie> v; 
      
	 v.emplace_back("a", 5); 
         
	 v.emplace_back("b", 7); 
 
	 v.emplace_back("c", 3);    
              
	 cout << "lista cofetarii:\n"; 
  
	 int total = 0; 
                 
	 for (const auto& c : v)                
	 {             
		 c.afisare();  
		 total += c.getLocuri();      
	 }
               
	 cout << "total locuri: " << total << "\n";

         
	 return 0; 

               
 }     




  