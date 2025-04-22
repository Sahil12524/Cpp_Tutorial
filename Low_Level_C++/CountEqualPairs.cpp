/*
    CountEqualPairs.cpp
    -------------------
    Given an array of integers, count how many pairs (i, j) exist such that:
        - i < j
        - input[i] == input[j]

    Example:
        Input:  [1, 2, 1, 3, 2]
        Output: 2

        Explanation:
        - Equal pairs are: (0,2) and (1,4)

    1. nasm -f win64 CountEqualPairs.asm -o CountEqualPairs.o
    2. g++ -O2 -std=c++17 CountEqualPairs.cpp CountEqualPairs.o -o CountEqualPairs.exe
    3. CountEqualPairs.exe
*/

#include <iostream>
#include <array>

extern "C" void CountEqualPairs(const int *input, int *output, size_t size);

int main()
{
    constexpr std::array<int, 5> input = {1, 2, 1, 3, 2};
    std::array<int, 1> output = {0};
    std::cout << "Calling ASM function...\n";
    CountEqualPairs(input.data(), output.data(), input.size());

    std::cout << "Equal pairs: " << output[0] << "\n";
    return 0;
}
