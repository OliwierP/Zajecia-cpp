#include <iostream>
#include <typeinfo>



typedef int calkowita;
typedef float zmiennoprzecinkowa;
typedef double dokladniejsza_zmiennoprzecinkowa;


namespace nasza {

	int k = 7;
}

enum Zbior {
	a, b, c, d = 6, e, f // 0, 1, 2, 6, 7, 8
};

int prefunkcja() {

	calkowita zmienna = 1;
	return zmienna;
}

int postfunkcja();

int main() {

	auto zmienna = 5;
	auto prezmienna = prefunkcja();
	auto postzmienna = postfunkcja();
	std::cout << zmienna << " " << sizeof(zmienna) << " " << typeid(zmienna).name() << std::endl;
	std::cout << prezmienna << " " << sizeof(prezmienna) << " " << typeid(prezmienna).name() <<std::endl;
	std::cout << postzmienna <<  " " << sizeof(postzmienna) << " " << typeid(postzmienna).name() <<std::endl;


	zmiennoprzecinkowa a = 5.11;
	dokladniejsza_zmiennoprzecinkowa b = 5.12;
	std::cout << "wynik: " << a + b << std::endl;

	std::cout << f << std::endl << c << std::endl << std::endl;
	
	zmiennoprzecinkowa k = 3.17;
	
	std::cout << k << std::endl;
	k = (calkowita) k;

	std::cout << k << std::endl << std::endl;

	std::cout << nasza::k << std::endl << k << std::endl;
	
	return 0;
	

}

int postfunkcja() {

	calkowita zmienna = 2;
	return zmienna;
}

int comp() {
	
	static int ncol = 0;
	ncol++;
	return ncol;
}
