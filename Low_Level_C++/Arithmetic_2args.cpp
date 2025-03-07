/*
    commands to compile and run:
    1. nasm -f win64 Arithmetic_2args.asm -o Arithmetic_2args.o
    2. g++ Arithmetic_2args.cpp Arithmetic_2args.o -o Arithmetic_2args.exe
    3. Arithmetic_2args.exe
*/

#include <iostream>
extern "C" int add_numbers(int x, int y);
int main()
{
    int a = 5, b = 15;
    int result = add_numbers(a, b);
    std::cout << "SUM: " << result << "\n";
    return 0;
}