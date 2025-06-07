/*
    Problem Statement:
    Rotate a 32-bit signed integer left by 'k' bits using the ROL (Rotate Left) instruction.

    Example:
    Input:  num = 0x80000000, k = 1 → Output: 1
            num = 0x12345678, k = 4 → Output: 0x23456781

    Compile:
    nasm -f win64 RotateLeft.asm -o RotateLeft.o^
    && g++ -O2 -std=c++17 RotateLeft.cpp RotateLeft.o -o RotateLeft.exe^
    && RotateLeft.exe
*/

#include <iostream>
#include <iomanip>

extern "C" int RotateLeft(int num, int k);

void print_result(int num, int k)
{
    int result = RotateLeft(num, k);
    std::cout << "Input:  0x" << std::hex << std::setw(8) << std::setfill('0') << num
              << ", Shift(k): " << std::dec << k
              << " => Result: 0x" << std::hex << std::setw(8) << std::setfill('0') << result << '\n';
}

int main()
{
    print_result(0x80000000, 1); // Expect: 0x00000001
    print_result(0x12345678, 4); // Expect: 0x23456781
    print_result(0xFFFFFFFF, 1); // Expect: 0xFFFFFFFF (all bits stay set)
    print_result(0x00000001, 31); // Expect: 0x80000000
    print_result(0xDEADBEEF, 8);  // Expect: 0xADBEEFDE

    return 0;
}
