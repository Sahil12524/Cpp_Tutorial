/*
    Compile & Run:
    1. nasm -f win64 Float_Arithmetic_4args.asm -o Float_Arithmetic_4args.o
    2. g++ Float_Arithmetic_4args.cpp Float_Arithmetic_4args.o -o Float_Arithmetic_4args.exe
    3. Float_Arithmetic_4args.exe
*/

#include <iostream>
extern "C" double add_floats(double a, double b, double c, double d);
int main()
{
    double a = 5.5, b = 10.5, c = 20.5, d = 30.5;
    double result = add_floats(a, b, c, d);
    std::cout << "SUM: " << result << "\n";
    return 0;
}