/*
    Problem Statement:
    Perform arithmetic shift right (SAR) on a signed integer and clamp the result
    between min_val and max_val.

    Example:
    Input:  val = -100, shift = 2, min_val = -20, max_val = 20 → Output: -20
            val = 60,   shift = 2, min_val = -10, max_val = 10 → Output: 10
            val = -7,   shift = 1, min_val = -10, max_val = 10 → Output: -4

    Compile:
    nasm -f win64 ClampShiftedSigned.asm -o ClampShiftedSigned.o^
    && g++ -O2 -std=c++17 ClampShiftedSigned.cpp ClampShiftedSigned.o -o ClampShiftedSigned.exe^
    && ClampShiftedSigned.exe
*/

#include <iostream>

extern "C" int ClampShiftedSigned(int val, int shift, int min_val, int max_val);

void print_result(int val, int shift, int min_val, int max_val)
{
    int result = ClampShiftedSigned(val, shift, min_val, max_val);
    std::cout << "Input: " << val << ", Shift: " << shift
              << ", Clamp(" << min_val << ", " << max_val << ")"
              << " => Result: " << result << "\n";
}

int main()
{
    print_result(-100, 2, -20, 20); // -25 → clamp to -20
    print_result(60, 2, -10, 10);   // 15  → clamp to 10
    print_result(-7, 1, -10, 10);   // -4  → in range
    print_result(30, 1, -20, 20);   // 15  → in range
    print_result(-128, 3, -16, 16); // -16 → exact clamp
    return 0;
}
