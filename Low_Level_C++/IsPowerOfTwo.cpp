/*
    Problem Statement:
    Write an ASM function to check if a number is a power of two using bitwise operations.

    If the number is a power of two, print: Yes
    Else, print: No

    Concept:
    n & (n - 1) == 0

    nasm -f win64 IsPowerOfTwo.asm -o IsPowerOfTwo.o
    g++ -O2 -std=c++17 IsPowerOfTwo.cpp IsPowerOfTwo.o -o IsPowerOfTwo.exe
    IsPowerOfTwo.exe
*/

#include <iostream>

extern "C" void IsPowerOfTwo(int num);

int main()
{
    IsPowerOfTwo(8);
    IsPowerOfTwo(10);
    IsPowerOfTwo(4);
    IsPowerOfTwo(0);
    IsPowerOfTwo(-8);
    IsPowerOfTwo(16);
    IsPowerOfTwo(256);
    return 0;
}