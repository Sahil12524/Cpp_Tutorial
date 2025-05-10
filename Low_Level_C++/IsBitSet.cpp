/*
    IsBitSet.cpp
    ------------
    Problem:
    Given a number and a bit index 'k', check if the k-th bit is set (1).

    Concept:
    Use a bitmask:
        mask = (1 << k);
        result = (num & mask) != 0;

    Example:
    Input:  num = 10 (1010), k = 1
    Output: true (bit 1 is set)

    Assembly version takes:
    - ECX = number
    - EDX = index
    Returns:
    - 1 if bit is set
    - 0 if not

    Compile:
    nasm -f win64 IsBitSet.asm -o IsBitSet.o
    g++ -O2 -std=c++17 IsBitSet.cpp IsBitSet.o -o IsBitSet.exe
    IsBitSet.exe
*/

#include <iostream>

extern "C" int IsBitSet(int num, int index);

int main()
{
    std::cout << IsBitSet(10, 1) << '\n';       // 10 = 1010, bit 1 is set → 1
    std::cout << IsBitSet(10, 2) << '\n';       // bit 2 is not set → 0
    std::cout << IsBitSet(255, 7) << '\n';      // 255 = 11111111, bit 7 is set → 1
    std::cout << IsBitSet(0, 0) << '\n';        // no bits set → 0
    std::cout << IsBitSet(1 << 30, 30) << '\n'; // large bit set → 1
    return 0;
}