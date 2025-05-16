/*
    Problem Statement:
    Simulate division by 2^k using arithmetic shift (SAR) on a signed integer.
    This mimics floor division behavior like C++ integer division for both positive and negative numbers.

    Example:
    Input:  num = 7,  k = 1   → Output: 3   (7 / 2)
            num = -7, k = 1   → Output: -4  (-7 / 2)
            num = 20, k = 2   → Output: 5   (20 / 4)
            num = -33, k = 3  → Output: -5  (-33 / 8)

    Compile:
    nasm -f win64 TruncateDivideByPowerOfTwo.asm -o TruncateDivideByPowerOfTwo.o^
    && g++ -O2 -std=c++17 TruncateDivideByPowerOfTwo.cpp TruncateDivideByPowerOfTwo.o -o TruncateDivideByPowerOfTwo.exe^
    && TruncateDivideByPowerOfTwo.exe
*/

#include <iostream>
#include <bitset>

extern "C" int TruncateDivideByPowerOfTwo(int num, int k);

void print_result(int num, int k)
{
    int result = TruncateDivideByPowerOfTwo(num, k);
    std::cout << "Input: " << num << ", Shift(k): " << k
              << " => Result: " << result << "\n";
}

int main()
{
    print_result(7, 1);     // 3
    print_result(-7, 1);    // -4
    print_result(20, 2);    // 5
    print_result(-33, 3);   // -5
    print_result(1024, 5);  // 32
    print_result(-1024, 5); // -32
    return 0;
}
