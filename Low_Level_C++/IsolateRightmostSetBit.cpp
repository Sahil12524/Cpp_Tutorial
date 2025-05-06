/*
    IsolateRightmostSetBit.cpp
    --------------------------
    Given a number, return only the rightmost set bit using Assembly.

    Example:
    Input:  20   (Binary: 00010100)
    Output: 4    (Binary: 00000100)

    Logic:
    - Bit trick: n & (-n)
    - Only the rightmost bit remains set, others are cleared.

    Compile with:
    nasm -f win64 IsolateRightmostSetBit.asm -o IsolateRightmostSetBit.o
    g++ -O2 -std=c++17 IsolateRightmostSetBit.cpp IsolateRightmostSetBit.o -o IsolateRightmostSetBit.exe
    IsolateRightmostSetBit.exe
*/

#include <iostream>

extern "C" int IsolateRightmostSetBit(int num);

int main()
{
    // TODO: Call the function with test values and print results
    std::cout << IsolateRightmostSetBit(20) << '\n'; // should be 4
    std::cout << IsolateRightmostSetBit(18) << '\n'; // should be 2
    std::cout << IsolateRightmostSetBit(8) << '\n';  // should be 8
    return 0;
}
