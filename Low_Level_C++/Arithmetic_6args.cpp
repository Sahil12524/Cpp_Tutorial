/*
    Compile & Run:
    1. nasm -f win64 Arithmetic_6args.asm -o Arithmetic_6args.o
    2. g++ Arithmetic_6args.cpp Arithmetic_6args.o -o Arithmetic_6args.exe
    3. Arithmetic_6args.exe
*/

#include <iostream>
extern "C" int add_numbers(int a, int b, int c, int d, int e, int f);
int main()
{
    int result = add_numbers(5, 10, 15, 20, 25, 30);
    std::cout << "SUM: " << result << "\n";
    return 0;
}