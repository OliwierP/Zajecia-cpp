#include <iostream>

int f1(int a, int b) {
    return a + b;
}

int& f2(int a, int b) {
    c = a + b;
    return c;
}

int* f3(int a, int b, int* c) {
    *c = a + b;
    return c;
}

void f4(int a, int b, int c[]) {
    c[0] = a + b;
}

int main() {
    std::cout << f1(2, 2) << std::endl;
    std::cout << f2(2, 2) << std::endl;
    int *p;
    std::cout << f3(2, 2, p) << std::endl;
    int t[1];
    f4(1, 2, t);
    std::cout << t[0] << std::endl;
    return 0;
}
