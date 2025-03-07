/*
    commands to compile and run:
    1. nasm -f win64 Arithmetic_3args.asm -o Arithmetic_3args.o
    2. g++ Arithmetic_3args.cpp Arithmetic_3args.o -o Arithmetic_3args.exe
    3. Arithmetic_3args.exe
*/

#include <iostream>
extern "C" int add_numbers(int x, int y, int z);
int main()
{
    int a = 5, b = 15, c = 50;
    int result = add_numbers(a, b, c);
    std::cout << "SUM: " << result << "\n";
    return 0;
}