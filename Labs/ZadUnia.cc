#include <iostream>
using namespace std;


union _Union {
    int a;
    double b;
};

int main() {
    _Union d;
    // Przypisanie warto�ci do a
    d.a = 1;
    cout << "a: " << d.a << endl;
    // Odczyt b��dnej warto�ci w przypadku b
    cout << "b: " << d.b << endl;
    // Przypisanie warto�ci do b
    d.b = 2.2;
    cout << "b: " << d.b << endl;
    // Odczyt b��dnej warto�ci w przypadku a
    cout << "a: " << d.a << endl;
    return 0;
}