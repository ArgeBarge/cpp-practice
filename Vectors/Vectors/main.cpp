#include <iostream>
#include <cstdlib>

class CVector {
public:
	int x, y;
	CVector() : x(0), y(0) {};
	CVector(int a, int b) : x(a), y(b) {};
	CVector operator + (const CVector&);
};

CVector CVector::operator+ (const CVector& param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

class MyClass {
public:
	int x;
	int& get() { return x; }
	MyClass() : x(5) {};
};

template <class T>
class Matrix {
public:
	T* values;
	Matrix(int size) {
		values = new T[size];
		for (int i = 0; i < size; i++)
		{
			values[i] = 0.5;
		}
			
	}
};
int main(int args, char** argv)
{
	CVector foo(3, 1);
	CVector bar(1, 2);

	CVector result = foo + bar;

	std::cout << result.x << "," << result.y << "\n";

	MyClass *myObj = new MyClass;
	int &myNum = myObj->get();
	std::cout << myNum << " " << myObj->x;
	myNum++;
	std::cout << myNum << " " << myObj->x;

	Matrix<int>* new_matrix = new Matrix<int>(10);
	if (new_matrix->values != NULL)
		std::cout << new_matrix->values[0];
	
}





