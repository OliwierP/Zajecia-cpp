#include <iostream>
using namespace std;


union _Union {
    int a;
    double b;
};

int main() {
    _Union d;
    // Przypisanie wartoœci do a
    d.a = 1;
    cout << "a: " << d.a << endl;
    // Odczyt b³êdnej wartoœci w przypadku b
    cout << "b: " << d.b << endl;
    // Przypisanie wartoœci do b
    d.b = 2.2;
    cout << "b: " << d.b << endl;
    // Odczyt b³êdnej wartoœci w przypadku a
    cout << "a: " << d.a << endl;
    return 0;
}