/*
    This is a Generated Test Question to solve (Exam).
    Declare a pointer to an integer in C++.
    Then declare a pointer to that pointer.
    Access and modify values through ASM via multiple levels of indirection.
*/

/*
    1. nasm -f win64 DoublePointerTest.asm -o DoublePointerTest.o
    2. g++ -O2 -std=c++17 DoublePointerTest.cpp DoublePointerTest.o -o DoublePointerTest.exe
    3. DoublePointerTest.exe
*/

#include <iostream>

extern "C" int ReadValue(int *ptr);
extern "C" int ModifyValue(int *ptr, int val);

int main()
{
    int a = 10;
    int *pA = nullptr;
    int **qPA = nullptr;
    pA = &a;
    qPA = &pA;

    std::cout << "Value of variable 'a' [unmodified]: " << ReadValue(&a) << "\n";
    std::cout << "Value of variable '*pA' [unmodified]: " << ReadValue(pA) << "\n";
    std::cout << "Value of variable '**qPA' [unmodified]: " << ReadValue(*qPA) << "\n";

    ModifyValue(*qPA, 20);
    std::cout << "Value of variable 'a' [modified] from *qPA: " << a << "\n";

    ModifyValue(pA, 30);
    std::cout << "Value of variable 'a' [modified] from pA: " << a << "\n";

    ModifyValue(&a, 40);
    std::cout << "Value of variable 'a' [modified] from &a: " << a << "\n";

    std::cout << "Value of variable 'a' [final]: " << ReadValue(&a) << "\n";
    std::cout << "Value of variable '*pA' [final]: " << ReadValue(pA) << "\n";
    std::cout << "Value of variable '**qPA' [final]: " << ReadValue(*qPA) << "\n";

    return 0;
}