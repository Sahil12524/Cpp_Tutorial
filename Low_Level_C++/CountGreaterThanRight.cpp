/*
    CountGreaterThanRight.cpp
    --------------------------
    Given an array of integers, for each element count how many elements to its right are smaller than it.

    Example:
        Input:  [5, 2, 6, 1]
        Output: [2, 1, 1, 0]

        Explanation:
        - 5 has two smaller elements to its right (2 and 1)
        - 2 has one smaller (1)
        - 6 has one smaller (1)
        - 1 has none

    1. nasm -f win64 CountGreaterThanRight.asm -o CountGreaterThanRight.o
    2. g++ -O2 -std=c++17 CountGreaterThanRight.cpp CountGreaterThanRight.o -o CountGreaterThanRight.exe
    3. CountGreaterThanRight.exe
*/

#include <iostream>
#include <array>

extern "C" void CountGreaterThanRight(const int *input, int *output, size_t size);

int main()
{
    constexpr std::array<int, 4> input = {5, 2, 6, 1};
    std::array<int, 4> output = {0};
    std::cout << "Calling ASM function...\n";
    CountGreaterThanRight(input.data(), output.data(), input.size());
    for (auto val : output)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";
    return 0;
}