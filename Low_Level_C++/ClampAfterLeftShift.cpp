/*
    Problem Statement:
    Multiply a signed integer by 2^k using shift arithmetic left (SAL),
    and clamp the result within [min_val, max_val].

    Example:
    Input:  num = 3,  k = 3, min = -50, max = 30   → Output: 24
            num = 3,  k = 4, min = -50, max = 30   → Output: 30 (clamped)
            num = -7, k = 2, min = -20, max = 20   → Output: -20 (clamped)
            num = -3, k = 4, min = -50, max = -10  → Output: -48

    Compile:
    nasm -f win64 ClampAfterLeftShift.asm -o ClampAfterLeftShift.o^
    && g++ -O2 -std=c++17 ClampAfterLeftShift.cpp ClampAfterLeftShift.o -o ClampAfterLeftShift.exe^
    && ClampAfterLeftShift.exe
*/

#include <iostream>

extern "C" int ClampAfterLeftShift(int num, int k, int minVal, int maxVal);

void print_result(int num, int k, int minVal, int maxVal)
{
    int result = ClampAfterLeftShift(num, k, minVal, maxVal);
    std::cout << "Input: " << num << ", Shift(k): " << k
              << ", Min: " << minVal << ", Max: " << maxVal
              << " => Result: " << result << '\n';
}

int main()
{
    print_result(3, 3, -50, 30);          // 24
    print_result(3, 4, -50, 30);          // 30 (clamped)
    print_result(-7, 2, -20, 20);         // -20 (clamped)
    print_result(-3, 4, -50, -10);        // -48
    print_result(1, 31, -100000, 100000); // 0x80000000 → clamped to 100000 (if needed)

    return 0;
}