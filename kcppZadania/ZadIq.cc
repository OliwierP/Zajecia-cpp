#include <iostream>



int main(){
	int tab[] = {1,2,3,4,5,6,7};
	
	int i = 4;
	int *q = tab;
	

	printf("%d\n", tab[i]);
	printf("%d\n", q[i]);
	printf("%d\n", i[q]);
  
  //  i[g] jest traktowane tak samo jak g[i]

}
