/*
    Count how many index pairs (i, j) exist such that i < j and arr[i] == arr[j].

    Example: {1, 2, 1, 3, 2}
    → Matching pairs: (0,2) and (1,4) → count = 2

    1. nasm -f win64 NestedLoop_Pairs.asm -o NestedLoop_Pairs.o
    2. g++ -O2 -std=c++17 NestedLoop_Pairs.cpp NestedLoop_Pairs.o -o NestedLoop_Pairs.exe
    3. NestedLoop_Pairs.exe
*/

#include <iostream>
#include <array>

extern "C" int CountMatchingPairs(const int *arr, size_t size);

void runTest(const std::array<int, 5> &arr, int testNumber);

int main()
{
    constexpr std::array<std::array<int, 5>, 2> testCases = {{{1, 2, 1, 3, 2},
                                                              {4, 5, 6, 7, 8}}};

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        runTest(testCases[i], static_cast<int>(i + 1));
    }
    return 0;
}

void runTest(const std::array<int, 5> &arr, int testNumber)
{
    int result = CountMatchingPairs(arr.data(), arr.size());
    std::cout << "Test Case " << testNumber << " : Matching pairs = " << result << "\n";
}