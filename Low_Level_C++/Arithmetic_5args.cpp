/*
    Compile & Run:
    1. nasm -f win64 Arithmetic_5args.asm -o Arithmetic_5args.o
    2. g++ Arithmetic_5args.cpp Arithmetic_5args.o -o Arithmetic_5args.exe
    3. Arithmetic_5args.exe
*/

#include <iostream>
extern "C" int add_numbers(int a, int b, int c, int d, int e);
int main()
{
    int a = 5, b = 10, c = 15, d = 20, e = 25;
    int result = add_numbers(a, b, c, d, e);
    std::cout << "SUM: " << result << "\n";
    return 0;
}
