#include <iostream>
using namespace std;


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
    int f, a;
    cout << "Wybierz funkcje (1 - operacje bitowe, 2 - modulo, 3 - operator warunkowy): ";
    cin >> f;
    cout << "Podaj liczbe: ";
    cin >> a;
    switch (f)
    {
    case 1:
        cout << czy_parzysta_bit(a) << endl;
        break;

    case 2:
        cout << czy_parzysta_modulo(a) << endl;
        break;

    case 3:
        cout << czy_parzysta_inna(a) << endl;
        break;

    default:
        break;
    }
}