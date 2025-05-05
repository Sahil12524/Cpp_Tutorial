/*
    Problem Statement:
    Write an ASM function that counts how many bits are set (1s) in a number's binary representation.

    Example:
    Input:  5  (Binary: 00000101)
    Output: 2

    Use bitwise operations only:
    - Right shift (shr)
    - AND (test or and)

    Compile with:
    nasm -f win64 CountSetBits.asm -o CountSetBits.o
    g++ -O2 -std=c++17 CountSetBits.cpp CountSetBits.o -o CountSetBits.exe
    CountSetBits.exe
*/

#include <iostream>

extern "C" int CountSetBits(int num);

int main()
{
    // TODO: Call CountSetBits with test values and print results
    std::cout << CountSetBits(5) << '\n';
    std::cout << CountSetBits(15) << '\n';
    std::cout << CountSetBits(1023) << '\n';
    return 0;
}
