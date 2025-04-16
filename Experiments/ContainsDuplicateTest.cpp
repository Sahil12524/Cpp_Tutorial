/*
    Check if the array contains any duplicate integers.
    A simple brute-force O(n^2) solution using two nested loops.

    Example input: {4, 2, 1, 3, 2} → Output: 1 (duplicate found)
    Example input: {1, 2, 3, 4, 5} → Output: 0 (all unique)
*/

/*
    1. nasm -f win64 ContainsDuplicateTest.asm -o ContainsDuplicateTest.o
    2. g++ -O2 -std=c++17 ContainsDuplicateTest.cpp ContainsDuplicateTest.o -o ContainsDuplicateTest.exe
    3. ContainsDuplicateTest.exe
*/

#include <iostream>
#include <array>

extern "C" int ContainsDuplicate(const int *arr, size_t size);

void runTest(const std::array<int, 5> &arr, int testNumber);

int main()
{
    constexpr std::array<std::array<int, 5>, 2> testCases = {{{4, 2, 1, 3, 2},
                                                              {1, 2, 3, 4, 5}}};

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        runTest(testCases[i], static_cast<int>(i + 1));
    }

    return 0;
}

void runTest(const std::array<int, 5> &arr, int testNumber)
{
    int result = ContainsDuplicate(arr.data(), arr.size());
    std::cout << "Test Case " << testNumber << ": ";
    if (result == 1)
    {
        std::cout << "Duplicate found!\n";
    }
    else
    {
        std::cout << "All unique!\n";
    }
}