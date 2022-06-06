#include <iostream>


void fun1(int a, bool b) {
    
    std::cout << a + b << std::endl;
}

int fun(int a, bool b) {
    
    return a + b;
}

int main() {
    
    bool zmienna = false;
    int k = 10;
    
    std::cout << fun(k, zmienna) << std::endl;
    fun1(k, zmienna);
    
    // std::cout << zmienna + k << std::endl;
    return 0;
}
