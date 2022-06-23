#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double a = 12.0/13.0;
	double b = 101.0/7.0;

	std::cout << "Wynik naszego działania: " << fixed << setprecision(5) << a << " jest niepoprawny, ale:" << endl;
	std::cout << std::setw(12) << "output: "<< std::setw(8) << setprecision(3) << b << std::setw(6) <<"T: " << std::setw(6) << a << endl;
	std::cout << std::setw(12) << "output1:"<< std::setw(8) << setprecision(4) << a << std::setw(6) <<"T: " << std::setw(6) << setprecision(5) << b << endl;
	std::cout << std::setw(12) << "output2:"<< std::setw(8) << setprecision(4) << a << std::setw(6) <<"T: " << std::setw(6) << setprecision(6) << b << endl;
	std::cout << std::setw(4) << "" << std::setfill('-') << std::setw(32) << "" << std::setfill(' ') << endl;
	std::cout << std::setw(12) << "average:"<< std::setw(8) << setprecision(4) << b << std::setw(6) <<"T: " << std::setw(6) << setprecision(6) << b << endl;

}
