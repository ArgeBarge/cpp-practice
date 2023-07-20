#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class testObject {
	int myNum;
	static 
public:
	testObject() {
		myNum = 5;
	}
	int getMyNum() {
		return myNum;
	}
};


int main(int argc, char** argv)
{
	std::vector<testObject>* x = new std::vector<testObject>(100);

	std::cout << (*x)[0].getMyNum();
	std::cout << 
}