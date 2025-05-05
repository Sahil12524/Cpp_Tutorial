/*
    Problem Statement:
    Use Brian Kernighan's algorithm to count the number of 1s in a number's binary form.

    Concept:
    Each iteration clears the lowest set bit:
    n = n & (n - 1)

    Compile with:
    nasm -f win64 CountSetBitsKernighan.asm -o CountSetBitsKernighan.o
    g++ -O2 -std=c++17 CountSetBitsKernighan.cpp CountSetBitsKernighan.o -o CountSetBitsKernighan.exe
    CountSetBitsKernighan.exe
*/

#include <iostream>

extern "C" int CountSetBitsKernighan(int num);

int main()
{
    // TODO: Call CountSetBitsKernighan with test values and print results
    std::cout << CountSetBitsKernighan(5) << '\n';
    std::cout << CountSetBitsKernighan(1023) << '\n';
    std::cout << CountSetBitsKernighan(13) << '\n';
    return 0;
}
