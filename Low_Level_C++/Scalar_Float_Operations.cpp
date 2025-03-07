/*
    Compile & Run:
    1. nasm -f win64 Scalar_Float_Operations.asm -o Scalar_Float_Operations.o
    2. g++ Scalar_Float_Operations.cpp Scalar_Float_Operations.o -o Scalar_Float_Operations.exe
    3. Scalar_Float_Operations.exe
*/

#include <iostream>
extern "C" double add_floats(double a, double b, double c, double d);
extern "C" double sub_floats(double a, double b, double c, double d);
extern "C" double mul_floats(double a, double b, double c, double d);
extern "C" double div_floats(double a, double b, double c, double d);
int main()
{
    double a = 5.5, b = 10.5, c = 20.5, d = 30.5;

    std::cout << "SUM: " << add_floats(a, b, c, d) << "\n";
    std::cout << "SUB: " << sub_floats(a, b, c, d) << "\n";
    std::cout << "MUL: " << mul_floats(a, b, c, d) << "\n";
    std::cout << "DIV: " << div_floats(a, b, c, d) << "\n";
    return 0;
}