 #define _CRT_SECURE_NO_WARNINGS     


 #include <iostream>              
 #include <string>      
             
 using namespace std;                  
  



 // simplu - permite modificare denumire    
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


        
	 // set denumire 


  
	 void setDenumire(const string& den)        
	 { denumire = den; }     
 };          
    

  
 int Cofetarie::contor = 0;             
    

       
 int main() 

     
 {   
	 Cofetarie c("veche", 8);                 
	 c.afisare(); 

    
	 // modificam denumirea              
	 c.setDenumire("noua");
              
	 cout << "dupa modificare:\n";             
	 c.afisare();
 
	 return 0;



 }    