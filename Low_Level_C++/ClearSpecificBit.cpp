/*
    Problem Statement:
    Write an ASM function that clears the k-th bit (0-indexed from right) in a number.

    Example:
    Input:  num = 7 (Binary: 00000111), k = 1
    Output: 5 (Binary: 00000101)

    Use bitwise operations only:
    - AND (and)
    - NOT (not)
    - Left shift (shl)

    Compile:
    nasm -f win64 ClearSpecificBit.asm -o ClearSpecificBit.o^
    && g++ -O2 -std=c++17 ClearSpecificBit.cpp ClearSpecificBit.o -o ClearSpecificBit.exe^
    && ClearSpecificBit.exe
*/

#include <iostream>

extern "C" int ClearSpecificBit(int num, int index);

int main()
{
    std::cout << ClearSpecificBit(7, 1) << "\n";  // 5
    std::cout << ClearSpecificBit(15, 0) << "\n"; // 14
    std::cout << ClearSpecificBit(10, 3) << "\n"; // 2
    std::cout << ClearSpecificBit(8, 3) << "\n";  // 0
    return 0;
}
