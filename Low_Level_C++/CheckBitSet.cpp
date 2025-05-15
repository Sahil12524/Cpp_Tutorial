/*
    Problem Statement:
    Write an ASM function that checks if the k-th bit (0-indexed from right) in a number is set.

    Example:
    Input:  num = 5 (Binary: 00000101), k = 0 → Output: 1
            num = 5 (Binary: 00000101), k = 1 → Output: 0
            num = 5 (Binary: 00000101), k = 2 → Output: 1

    Use bitwise operations only:
    - AND (and)
    - Left shift (shl)
    - CMP + SETNE

    Compile:
    nasm -f win64 CheckBitSet.asm -o CheckBitSet.o^
    && g++ -O2 -std=c++17 CheckBitSet.cpp CheckBitSet.o -o CheckBitSet.exe^
    && CheckBitSet.exe
*/

#include <iostream>

extern "C" int CheckBitSet(int num, int index);

int main()
{
    std::cout << CheckBitSet(5, 0) << '\n';   // 1 (LSB is 1)
    std::cout << CheckBitSet(5, 1) << '\n';   // 0
    std::cout << CheckBitSet(5, 2) << '\n';   // 1
    std::cout << CheckBitSet(0, 3) << '\n';   // 0
    std::cout << CheckBitSet(8, 3) << '\n';   // 1
    std::cout << CheckBitSet(255, 7) << '\n'; // 1
    return 0;
}
