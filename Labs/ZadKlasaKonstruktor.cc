#include <iostream>


class Moja {

public:
	//Moja();
	/*Moja() {
	wiek = 0;	
	} */
	Moja() : wiek(0) {}

	/*Moja(int x) {
		wiek = x;
	} */

	Moja(int x) : wiek(x) {}


	// Moja(int a);
	Moja(const Moja &m) {
      wiek = m.wiek;
    
   }
	
	~Moja() {
		std::cout << typeid(this).name() <<" Obiekt zostal usuniety" << std::endl;
	}

	/*int setWiek(int x) {
		
		wiek = x;
	}*/

	Moja& setWiek(int x) {

		wiek = x;
		return *this;
	}

	int getWiek() {

		return wiek;
	}

	void Pokaz() {

		// std::cout << "Wiek: " << this->wiek << std::endl;
		std::cout << typeid(this).name() << " Wiek: " << wiek << std::endl;
	} 

	
	
private:
	int wiek;

};

int main() {



	/*Moja::Moja() {
	wiek = 0;	
	} */

	/*Moja::Moja(int x) {
		wiek = x;
	}*/

	Moja m1;
	Moja m2(15);
	Moja m3 = m2;

	m1.Pokaz();
	m1.setWiek(5).Pokaz();
	m2.Pokaz();
	m2.setWiek(100);
	m2.Pokaz();
	m3.Pokaz();
	
	Moja *m4 = new Moja(m1.getWiek());
	m4->Pokaz();
	delete(m4);
	
	std::cout << "Obiekt: " << typeid(m3).name() << std::endl;

	return 0;

}