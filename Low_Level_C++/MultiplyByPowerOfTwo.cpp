/*
    Problem Statement:
    Multiply a signed integer by 2^k using shift arithmetic left (SAL).

    Example:
    Input:  num = 7,  k = 1   → Output: 14   (7 * 2)
            num = -7, k = 1   → Output: -14
            num = 3,  k = 3   → Output: 24   (3 * 8)
            num = -5, k = 2   → Output: -20

    Compile:
    nasm -f win64 MultiplyByPowerOfTwo.asm -o MultiplyByPowerOfTwo.o^
    && g++ -O2 -std=c++17 MultiplyByPowerOfTwo.cpp MultiplyByPowerOfTwo.o -o MultiplyByPowerOfTwo.exe^
    && MultiplyByPowerOfTwo.exe
*/

#include <iostream>

extern "C" int MultiplyByPowerOfTwo(int num, int k);

void print_result(int num, int k)
{
    int result = MultiplyByPowerOfTwo(num, k);
    std::cout << "Input: " << num << ", Shift(k): " << k
              << " => Result: " << result << '\n';
}

int main()
{
    print_result(7, 1);   // 14
    print_result(-7, 1);  // -14
    print_result(3, 3);   // 24
    print_result(-5, 2);  // -20
    print_result(10, 4);  // 160
    print_result(-1, 31); // INT_MIN (-2147483648)

    return 0;
}
