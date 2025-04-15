/*
    Find the index of the first zero in the array.
    Example input: {5, -1, 0, 3, 0} → Output: 2 (first 0 is at index 2)
    Return -1 if no zero exists in the array.
*/

/*
    1. nasm -f win64 FindIndexOfFirstZeroTest.asm -o FindIndexOfFirstZeroTest.o
    2. g++ -O2 -std=c++17 FindIndexOfFirstZeroTest.cpp FindIndexOfFirstZeroTest.o -o FindIndexOfFirstZeroTest.exe
    3. FindIndexOfFirstZeroTest.exe
*/

#include <iostream>
#include <array>

extern "C" int FindIndexOfFirstZero(const int *arr, size_t size);

void runTest(const std::array<int, 5> &arr, int testNumber);

int main()
{
    std::array<std::array<int, 5>, 3> testCases = {{{5, -1, 0, 3, 0},
                                                    {7, 8, 6, 3, 9},
                                                    {0, 1, 2, 3, 4}}};

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        runTest(testCases[i], static_cast<int>(i + 1));
    }

    return 0;
}

void runTest(const std::array<int, 5> &arr, int testNumber)
{
    int index = FindIndexOfFirstZero(arr.data(), arr.size());
    std::cout << "Test Case " << testNumber << ": ";
    if (index == -1)
    {
        std::cout << "Zero not found.\n";
    }
    else
    {
        std::cout << "First zero found at index " << index << ".\n";
    }
}