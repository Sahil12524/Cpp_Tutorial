/*
    Problem Statement:
    Write an ASM function to check if a number is a power of 2.

    Concept:
    A number is a power of two if it has exactly one set bit.
    So, (n & (n - 1)) == 0 for n > 0.

    Examples:
    Input:  8  (Binary: 00001000) → Output: 1 (true)
    Input:  10 (Binary: 00001010) → Output: 0 (false)
    Input:  1  (Binary: 00000001) → Output: 1 (true)
    Input:  0  (invalid, not a power of 2)    → Output: 0
    Input: -2 (negative, invalid)             → Output: 0

    How to compile:
    nasm -f win64 CheckPowerOfTwo.asm -o CheckPowerOfTwo.o
    g++ -O2 -std=c++17 CheckPowerOfTwo.cpp CheckPowerOfTwo.o -o CheckPowerOfTwo.exe
    CheckPowerOfTwo.exe
*/

#include <iostream>

extern "C" int CheckPowerOfTwo(int n);

int main()
{
    std::cout << CheckPowerOfTwo(8) << '\n';  // 1
    std::cout << CheckPowerOfTwo(10) << '\n'; // 0
    std::cout << CheckPowerOfTwo(1) << '\n';  // 1
    std::cout << CheckPowerOfTwo(0) << '\n';  // 0
    std::cout << CheckPowerOfTwo(-2) << '\n'; // 0
    return 0;
}