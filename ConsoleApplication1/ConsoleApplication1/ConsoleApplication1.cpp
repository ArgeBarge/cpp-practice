// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "matrix.h"

class myClass {
    public:
        int myNum;
        std::string myString;
        myClass() {
            myNum = 5;
            myString = "Hello";
        }

        std::string getString() {
            return myString;
        }

};

class Burger {
public:
    std::string patty;
    Burger() {
        patty = "beef";
    }

    std::string getPatty() {
        return patty;
    }
};

class Veggie : public Burger {
public:
    std::string getPatty() {
        return "Veggie";
    }
};

class Chicken : public Burger {
public:
    
    std::string getPatty() {
        return "Chicken";
    }
    
};

template <class T>
void duplicate(T& a, T& b, T& c)
{
    a *= 2;
    b *= 2;
    c *= 2;
}

class staticClass {
    
    staticClass() {
        myNum1 = 1;
    }
public:
    int myNum1;
    static int myNum;
    static staticClass *theSingleton;
    
};

int staticClass::myNum = 5;

staticClass *staticClass::theSingleton = new staticClass();

int main()
{
    Matrix test_matrix(3, 3);
    test_matrix.print();
    test_matrix.set("1,5,4,7,4,3,1,2,6,");
    test_matrix.print();

    Matrix matrix1(3, 3);
    Matrix matrix2(3, 3);

    matrix1.set("2,0,0,0,2,0,0,0,2,");
    matrix2.set("2,2,2,2,2,2,2,2,2,");

    matrix1.print();
    matrix2.print();

    Matrix* mpter = new Matrix(3, 3);

    Matrix *result = multiply_matrices(&matrix1, &matrix2);
    Matrix* result1 = add_matrices(&matrix1, &matrix2);

    result1->print();
    result->print();
    result->free();

    int a, b, c;
    a = 2;
    b = 3;
    c = 4;
    std::cout << "We are here\n";

    duplicate<int>(a, b, c);
    //result.free();
    
    std::shared_ptr<int> num1(new int);
    std::shared_ptr<int> num2(num1);

    *num1 = 5;
    std::cout << *num2 << "Num 2";

   /*std::cout << "\n" << myObject.myNum << "\n" << myObject1.myNum;
    staticClass::myNum++;
    std::cout << "\n" << myObject.myNum << "\n" << myObject1.myNum << "\n";
    (myObject.myNum1)++;
    std::cout << "\n" << myObject.myNum1 << "\n";
    std::cout << myObject1.myNum1 << "\n"; */

    //Matrix* sub_matrix = get_submatrix(&test_matrix, 0);
    //sub_matrix->print();
    Matrix* test_matrix1 = init_matrix(3, 3);
    test_matrix1->set("4,2,3,5,53,4,3,2,4,");
    test_matrix1->print();
    std::cout << get_determinant(test_matrix1) << " Result!" << "\n";
   
    std::system("pause");
    
    return 0;
}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


