/*
    Problem Statement:
    Write an ASM function that sets the k-th bit (0-indexed from right) in a number.

    Example:
    Input:  num = 5 (Binary: 00000101), k = 1
    Output: 7 (Binary: 00000111)

    Use bitwise operations only:
    - OR (or)
    - Left shift (shl)

    Compile:
    nasm -f win64 SetSpecificBit.asm -o SetSpecificBit.o^
    && g++ -O2 -std=c++17 SetSpecificBit.cpp SetSpecificBit.o -o SetSpecificBit.exe^
    && SetSpecificBit.exe
*/

#include <iostream>

extern "C" int SetSpecificBit(int num, int index);

int main()
{
    std::cout << SetSpecificBit(5, 1) << "\n";  // 7
    std::cout << SetSpecificBit(0, 3) << "\n";  // 8
    std::cout << SetSpecificBit(10, 0) << "\n"; // 11
    std::cout << SetSpecificBit(15, 2) << "\n"; // 15 (already set)
    return 0;
}
