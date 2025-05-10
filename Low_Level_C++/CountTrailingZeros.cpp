/*
    Problem Statement:
    Write an ASM function that counts the number of trailing zeros
    in the binary representation of a number.

    Example:
    Input:  8   (Binary: 00001000) → Output: 3
    Input:  12  (Binary: 00001100) → Output: 2
    Input:  5   (Binary: 00000101) → Output: 0

    Use bitwise operations only:
    - AND (test or and)
    - Right shift (shr)

    Compile:
    nasm -f win64 CountTrailingZeros.asm -o CountTrailingZeros.o^
    && g++ -O2 -std=c++17 CountTrailingZeros.cpp CountTrailingZeros.o -o CountTrailingZeros.exe^
    && CountTrailingZeros.exe
*/

#include <iostream>

extern "C" int CountTrailingZeros(int num);

int main()
{
    std::cout << CountTrailingZeros(8) << '\n';  // 3
    std::cout << CountTrailingZeros(12) << '\n'; // 2
    std::cout << CountTrailingZeros(5) << '\n';  // 0
    std::cout << CountTrailingZeros(0) << '\n';  // 0
    std::cout << CountTrailingZeros(16) << '\n'; // 4
    return 0;
}