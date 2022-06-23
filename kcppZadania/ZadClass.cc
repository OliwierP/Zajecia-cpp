#include <iostream>

using namespace std;

class bClass{
    private:
        int a;

    protected:
        int b;

    public:
        int c;
        void setA(int intA){
            a = intA;
        }

        int getA();

        void setB(int intB){
            b = intB;
        }

        void setC(int intC){
            c = intC;
        }
        
        inline int getAplusB(){
            return a+b;
        }

};

int bClass::getA(){
    return a;
}

int main(){

    bClass bc;
    bc.setA(5);
    bc.setB(2);
    bc.setC(8);
    cout << "a: " << bc.getA() << endl;
    cout << "a + b: " << bc.getAplusB() << endl;
    return 1;
}
