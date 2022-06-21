#include <iostream>
#include <string.h>


struct Pies {
	// char[20] imie;
	// char[20] rasa;
	string imie;
	string rasa;
	int wiek;
	bool czyAdptowany;

}pies;


int main() {

	

	pies p1;
	p1.imie = "Alex";
	p1.rasa = "owczarek niemiecki";
	p1.wiek = 7;
	p1.czyAdoptowany = false;

	return 0;

}