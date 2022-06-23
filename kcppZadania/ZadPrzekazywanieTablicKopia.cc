#include <iostream>
using namespace std;

void fun(int tab[], int size){
	int copyTab[size] ;
	for(int i=0; i < size; i++){
                copyTab[i] = tab[i];
        }

	for(int i=0; i < size; i++){
               cout << copyTab[i] << ",";
        }
	cout << endl;
	cout << &copyTab << "," << &tab << endl;
}

int main(){
	int size = 3;
	int tab[] = {1,2,3};
	fun(tab,size);
	return 1;
}
