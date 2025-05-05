/*
    Problem Statement:
    Write an ASM function that returns 1 if a number has an even number of 1s in its binary form,
    or 0 if it has an odd number of 1s.

    Logic:
    - Use parity flipping (toggle a bool each time a set bit is removed).
    - Uses: n = n & (n - 1) to iterate through set bits.

    Expected:
    IsParityEven(5);    // 5 = 101 → 2 bits → even → returns 1
    IsParityEven(7);    // 7 = 111 → 3 bits → odd  → returns 0

    Compile with:
    nasm -f win64 IsParityEven.asm -o IsParityEven.o
    g++ -O2 -std=c++17 IsParityEven.cpp IsParityEven.o -o IsParityEven.exe
    IsParityEven.exe
*/

#include <iostream>

extern "C" int IsParityEven(int num);

int main()
{
    std::cout << IsParityEven(5) << '\n';          // 2 bits → even → expect 1
    std::cout << IsParityEven(7) << '\n';          // 3 bits → odd  → expect 0
    std::cout << IsParityEven(0xFFFFFFFF) << '\n'; // 32 bits → even → expect 1
    std::cout << IsParityEven(0x80000000) << '\n'; // 1 bit   → odd  → expect 0
    return 0;
}
