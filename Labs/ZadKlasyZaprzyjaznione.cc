#include <iostream>
using namespace std;


class A {
    private:
        int a;
    public:
        A(int a) {
            this->a = a;
        }
        int getA() {
            return a;
        }
        friend class B;
};

class B {
    private:
        int b;
    public:
        B(int b) {
            this->b = b;
        }
        int getB() {
            return b;
        }
        void printAa(A &a) {
            cout << a.a << endl;
        }
};

int main() {
    A a(1);
    B b(2);
   
    b.printAa(a);
    return 0;
}
