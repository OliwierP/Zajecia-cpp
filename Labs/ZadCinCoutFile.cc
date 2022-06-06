#include <iostream>
#include <fstream>


int main(){
	std::cout << "Podaj liczbe: ";
	int number;
	std::cin >> number;
	fstream fileW("plik.txt", ios::out);

	if (fileW.good()){
		std::cout << "Udalo sie otworzyc plik..." << std::endl;
		std::cout << "zapisana liczba: " << number << std::endl;
		fileW << number;
		fileW.close();
	}
	else {
		std::cerr << "Nie udalo sie otworzyc pliku" << std::endl;
	}
	std::cout << std::endl << std::endl << "Odczyt z pliku"<< std::endl;
	fstream fileR("plik.txt", ios::in);
	if (fileR.good()){
		string line;
		std::cout << "Plik otwarty i zawiera: " << std::endl;
		while ( !fileR.eof()){
			getline(fileR, line);
			std::cout << line << std::endl;
		}
		fileR.close();
	}
	else {
		std::cerr << "Nie udalo sie otworzyc pliku" << std::endl;
	}
	return 0;
}
