#include <iostream>
using namespace std;

class Samochod
{

  public:
    int fA;
    void Metoda() {}
    
    void Metoda2() {
        
        fB = 10;
        std::cout << fB << std::endl;
    }

  protected:
    int fB;
  private:
    int fC;
};

int main()
{

  Samochod obiektSyrenka;      ///< tworzymy obiekt
  Samochod *wskSyrenka = new Samochod();
  obiektSyrenka.fA = 1;        //  OK
  //obiektSyrenka.fB = 1;        //  Error
  //obiektSyrenka.fC = 1;        //  Error
  
  obiektSyrenka.Metoda2();

  //obiektSyrenka.Metoda();      //  OK

  wskSyrenka->fA = 1;          //  OK
  //wskSyrenka->fB = 1;          //  Error
  //wskSyrenka->fC = 1;          //  Error

  wskSyrenka->Metoda();        //  OK

  delete wskSyrenka;
}
