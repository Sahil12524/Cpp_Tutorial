/*
    CountDistinctPairs.cpp
    ----------------------
    Given an array of integers, count how many distinct pairs (i, j) exist such that:
        - i < j
        - input[i] != input[j]

    Example:
        Input:  [1, 2, 1]
        Output: 2

        Explanation:
        - (0,1): 1 != 2 ✔
        - (0,2): 1 == 1 ✘
        - (1,2): 2 != 1 ✔
        → Total = 2 distinct pairs

    1. nasm -f win64 CountDistinctPairs.asm -o CountDistinctPairs.o
    2. g++ -O2 -std=c++17 CountDistinctPairs.cpp CountDistinctPairs.o -o CountDistinctPairs.exe
    3. CountDistinctPairs.exe
*/

#include <iostream>
#include <array>

extern "C" void CountDistinctPairs(const int *input, int *output, size_t size);

int main()
{
    constexpr std::array<int, 3> input = {1, 2, 1};
    std::array<int, 1> output = {0};

    std::cout << "Calling ASM function...\n";
    CountDistinctPairs(input.data(), output.data(), input.size());

    std::cout << "Distinct pairs (i < j, values unequal): " << output[0] << "\n";
    return 0;
}
