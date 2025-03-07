/*
    commands to compile and run:
    1. nasm -f win64 Arithmetic_4args.asm -o Arithmetic_4args.o
    2. g++ Arithmetic_4args.cpp Arithmetic_4args.o -o Arithmetic_4args.exe
    3. Arithmetic_4args.exe
*/

#include <iostream>
extern "C" int add_numbers(int a, int b, int c, int d);
int main()
{
    int a = 5, b = 20, c = 50, d = 100;
    int result = add_numbers(a, b, c, d);
    std::cout << "SUM: " << result << "\n";
    return 0;
}