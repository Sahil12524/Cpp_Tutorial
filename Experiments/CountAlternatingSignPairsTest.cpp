/*
    CountAlternatingSignPairsTestTest.cpp
    ----------------------
    Given an array of integers, count how many adjacent elements have opposite signs.

    Example:
        Input:  [1, -2, 3, -4, 5]
        Output: 4

        Explanation:
        - (1, -2): opposite signs ✔
        - (-2, 3): opposite signs ✔
        - (3, -4): opposite signs ✔
        - (-4, 5): opposite signs ✔
        → Total = 4 alternating sign pairs

    1. nasm -f win64 CountAlternatingSignPairsTest.asm -o CountAlternatingSignPairsTest.o
    2. g++ -O2 -std=c++17 CountAlternatingSignPairsTest.cpp CountAlternatingSignPairsTest.o -o CountAlternatingSignPairsTest.exe
    3. CountAlternatingSignPairsTest.exe
*/

#include <iostream>
#include <array>

extern "C" void CountAlternatingSignPairs(const int *input, int *output, size_t size);

int main()
{
    constexpr std::array<int, 5> input = {1, -2, 3, -4, 5};
    std::array<int, 1> output = {0};

    std::cout << "Calling ASM function...\n";
    CountAlternatingSignPairs(input.data(), output.data(), input.size());

    std::cout << "Alternating sign pairs: " << output[0] << "\n";
    return 0;
}
