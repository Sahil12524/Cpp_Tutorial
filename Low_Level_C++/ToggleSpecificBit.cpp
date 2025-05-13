/*
    Problem Statement:
    Write an ASM function that toggles the k-th bit (0-indexed from right) in a number.

    Example:
    Input:  num = 5 (Binary: 00000101), k = 0
    Output: 4 (Binary: 00000100)

    Input:  num = 5 (Binary: 00000101), k = 1
    Output: 7 (Binary: 00000111)

    Use bitwise operations only:
    - XOR (xor)
    - Left shift (shl)

    Compile:
    nasm -f win64 ToggleSpecificBit.asm -o ToggleSpecificBit.o^
    && g++ -O2 -std=c++17 ToggleSpecificBit.cpp ToggleSpecificBit.o -o ToggleSpecificBit.exe^
    && ToggleSpecificBit.exe
*/

#include <iostream>

extern "C" int ToggleSpecificBit(int num, int index);

int main()
{
    std::cout << ToggleSpecificBit(5, 0) << "\n"; // 4
    std::cout << ToggleSpecificBit(5, 1) << "\n"; // 7
    std::cout << ToggleSpecificBit(8, 3) << "\n"; // 0
    std::cout << ToggleSpecificBit(0, 2) << "\n"; // 4
    return 0;
}
