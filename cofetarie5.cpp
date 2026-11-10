 #define _CRT_SECURE_NO_WARNINGS 

        
 #include <iostream>   
 #include <string>               
 #include <vector>          
  

 using namespace std;  
           
 // simplu - adaugare si stergere din vector  
  
 class Cofetarie
            
 {      
 private:   
	int id;        
	 string denumire;                
	 int nrLocuri;                 
	 static int contor; 
      
 public:  
	 Cofetarie() : id(++contor), denumire("default"), nrLocuri(0)
 
	 {}     
 


	 Cofetarie(const string& den, int nr) : id(++contor), denumire(den), nrLocuri(nr) 
   
	 {}   


  
	 void afisare() const  
        
	 {         
		 cout << "id: " << id << " | " << denumire << " | locuri: " << nrLocuri << "\n";                
	 }  

     
 };     

         
               
 int Cofetarie::contor = 0;       
    


 int main()          
 {    

    
	 vector<Cofetarie> v;       
	 v.emplace_back("alpha", 4);     
	 v.emplace_back("beta", 6); 
	 v.emplace_back("gamma", 2);     
        

	 cout << "inainte stergere:\n";          
	 for (size_t i = 0; i < v.size(); ++i) 

          
	 {  
		 cout << i + 1 << ") ";   
		 v[i].afisare();                
	 }  
           

   
	 // stergem elementul 2 (index 1) demonstrativ 
      
	 if (v.size() >= 2)      
	 {    
		 v.erase(v.begin() + 1);         
	 }         
            

      
	 cout << "dupa stergere:\n";            
	 for (size_t i = 0; i < v.size(); ++i)              
	 { 
		 cout << i + 1 << ") ";             
		 v[i].afisare();          
	 }           
         
	 return 0;  
                
 }     





        