/*
    Compile & Run:
    1. nasm -f win64 Swap.asm -o Swap.o
    2. g++ -O2 -fno-inline Swap.cpp Swap.o -o Swap.exe
    3. Swap.exe
*/
#include <iostream>

extern "C" void Swap(int *a, int *b);

int main()
{
    int num1 = 10, num2 = 20;

    std::cout << "Before swap: " << num1 << " " << num2 << "\n";

    Swap(&num1, &num2);

    std::cout << "After swap: " << num1 << " " << num2 << "\n";

    return 0;
}