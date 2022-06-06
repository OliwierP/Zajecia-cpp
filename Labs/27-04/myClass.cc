#include <iostream>




class myClass {

public:
	int var;

	void print(myClass object) {
		std::cout << object.var << std::endl;
	}

	void print2(myClass object);

	void print3() {

		std::cout << this->var << std::endl;
	}

};

int main() {


	myClass::print2(MyClass) {
		std::cout << object.var << std::endl;
	}

	myClass obj;

	obj.var = 5;

	std::cout << obj.var << std::endl;

	obj.print(obj);

	//obj.print2(obj);

	obj.print3();

	return 0 ;
}
