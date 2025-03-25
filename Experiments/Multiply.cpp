/*
    Compile & Run:
    1. nasm -f win64 Multiply.asm -o Multiply.o
    2. g++ -O0 -fno-inline Multiply.cpp Multiply.o -o Multiply.exe
    3. Multiply.exe
*/

#include <iostream>

extern "C" int multiply_three(const int a, const int b, const int c);

int main()
{
    const int num1 = 3, num2 = 4, num3 = 5;
    const int result = multiply_three(num1, num2, num3);

    std::cout << "Result: " << result << "\n";
    return 0;
}