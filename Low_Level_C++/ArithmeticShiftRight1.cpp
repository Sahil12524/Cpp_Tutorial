/*
    Problem Statement:
    Write an ASM function that performs arithmetic right shift on a signed integer by `k` positions.

    Example:
    Input:  num = -8 (Binary: 11111000), k = 1 → Output: -4 (Binary: 11111100)
            Input:  num = -1 (Binary: 11111111), k = 3 → Output: -1 (Binary: 11111111)
            Input:  num = 16 (Binary: 00010000), k = 2 → Output: 4 (Binary: 00000100)

    Compile:
    nasm -f win64 ArithmeticShiftRight1.asm -o ArithmeticShiftRight1.o^
    && g++ -O2 -std=c++17 ArithmeticShiftRight1.cpp ArithmeticShiftRight1.o -o ArithmeticShiftRight1.exe^
    && ArithmeticShiftRight1.exe
*/

#include <iostream>
#include <bitset>

extern "C" int ArithmeticShiftRight1(int num, int shift);

void print_result(int num, int shift)
{
    int result = ArithmeticShiftRight1(num, shift);
    std::cout << "\nInput: " << num << " (" << std::bitset<8>(num) << "), "
              << "Shift: " << shift << " => "
              << "Output: " << result << " (" << std::bitset<8>(result) << ")\n";
}

int main()
{
    print_result(-8, 1);  // -4
    print_result(-1, 3);  // -1
    print_result(16, 2);  // 4
    print_result(-32, 2); // -8
    print_result(7, 1);   // 3
    return 0;
}