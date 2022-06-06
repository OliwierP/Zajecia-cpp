#include <iostream>


bool czy_parzysta_modulo(int num) {

	return !(num % 2);

}

bool czy_parzysta_bit(int num) {

	num = num & 0;
	return num;

}

bool czy_parzysta_inna(int num) {


	bool result = (num % 2? 1: 0);
	result = !result;
	return result;
result;
}

int main() {


	int liczba = 7;
	bool modulo = czy_parzysta_modulo(liczba);
	bool bit = czy_parzysta_bit(liczba);
	bool inna = czy_parzysta_inna(liczba);
	std::cout << modulo << " " << bit << " " << inna << std::endl;

	return 0;
}

