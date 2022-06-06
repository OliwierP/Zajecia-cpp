#include <iostream>
using namespace std;


//------------------------------------------------------------------
class Figura
{   
 public:
   virtual void Narysuj() = 0;
   virtual void Pole(int, int) = 0;
	virtual void Pole(int) = 0;
   //virtual int Obwod() = 0;
};
//------------------------------------------------------------------




//------------------------------------------------------------------
class Trojkat : public Figura 
{  
 public:
   void Narysuj() {
      cout << "Przepis na narysowanie trojkata" << endl;
   }
   
   void Pole(int a, int h) {
       cout << (a * h) / 2;
   }
	void Pole(int a) {
       cout << (a * a * 1,71) /4;
   }
   
   //int Obwod(int a, int b, int c) {
       //return a + b + c;
   //}
};

//------------------------------------------------------------------
class Kwadrat
{  
 public:
   void Narysuj() {
      cout << "Przepis na narysowanie kwadrata" << endl;
   }
   
   void Pole(int a) {
       cout << a * a <<endl;
   }


   
   //int Obwod(int a) {
       //return 4 * a;
   //}#include <iostream>

};





//--------------------------------------------------------
//------------------------------------------------------------------
class Prostokat : public Figura 
{  
 public:
   void Narysuj() {
      cout << "Przepis na narysowanie prostokata" << endl;
   }
      
    void Pole(int a, int b) {
       cout << a * b;
    }

	void Pole(int a) {
       cout << a;
    }
    
    //int Obwod(int a, int b) {
        //return 2 * a + 2 * b;
    //}
       
    
};


//------------------------------------------------------------------
int main()
{ 
   
   Kwadrat *objKwadrat = new Kwadrat();
   objKwadrat->Narysuj();
   objKwadrat->Pole(3);

	Prostokat *objProstokat = new Prostokat();
   objProstokat->Narysuj();
   objProstokat->Pole(3, 5);


}
