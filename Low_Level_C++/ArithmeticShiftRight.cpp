/*
    Problem Statement:
    Write an ASM function that performs arithmetic right shift on a signed integer.

    Input:
        num = -8, shift = 2
    Output:
        -2

    Explanation:
        -8 (binary): 11111000
        Arithmetic shift right by 2 → 11111110 (preserves sign) = -2

    Compile:
    nasm -f win64 ArithmeticShiftRight.asm -o ArithmeticShiftRight.o^
    && g++ -O2 -std=c++17 ArithmeticShiftRight.cpp ArithmeticShiftRight.o -o ArithmeticShiftRight.exe^
    && ArithmeticShiftRight.exe
*/

#include <iostream>

extern "C" int ArithmeticShiftRight(int num, int shift);

int main()
{
    std::cout << ArithmeticShiftRight(-8, 2) << "\n";   // -2
    std::cout << ArithmeticShiftRight(-1, 1) << "\n";   // -1
    std::cout << ArithmeticShiftRight(32, 3) << "\n";   // 4
    std::cout << ArithmeticShiftRight(-128, 4) << "\n"; // -8
    return 0;
}