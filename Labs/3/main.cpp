#include <iostream>
#include <string>

void funkcja1() {
	std::cout << "funkcja1 !!!" << std::endl;
}

void funkcja2() {
	std::cout << "funkcja2 !!!" << std::endl;
}

void funkcja3() {
	std::cout << "funkcja3 !!!" << std::endl;
}

void funkcja4() {
	std::cout << "funkcja4 !!!" << std::endl;
}

void funkcja5() {
	std::cout << "funkcja5 !!!" << std::endl;
}
int main(int argc, char *argv[]) {

		
	

	for (int i = 1; i < argc; i++) {

		std::string program = argv[i];
		if (program == "funkcja1")
			funkcja1();
		else if (program == "funkcja2")
			funkcja2();
		else if (program == "funkcja3")
			funkcja3();
		else if (program == "funkcja4")
			funkcja4();
		else if (program == "funkcja5")
			funkcja5();
		else
			std::cout << "to nie jest funkcja";	
	}

	return 0;	
}


