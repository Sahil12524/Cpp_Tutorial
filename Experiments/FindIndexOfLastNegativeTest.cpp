/*
    FindIndexOfLastNegativeTest.cpp
    ----------------------
    Given an array of integers, return the index of the last negative number.
    If no negative number exists, return -1.

    Example:
        Input:  [4, -2, 7, -5, 9]
        Output: 3

        Explanation:
        - Last negative is -5 at index 3

    1. nasm -f win64 FindIndexOfLastNegativeTest.asm -o FindIndexOfLastNegativeTest.o
    2. g++ -O2 -std=c++17 FindIndexOfLastNegativeTest.cpp FindIndexOfLastNegativeTest.o -o FindIndexOfLastNegativeTest.exe
    3. FindIndexOfLastNegativeTest.exe
*/

#include <iostream>
#include <array>

extern "C" int FindIndexOfLastNegative(const int *input, size_t size);

int main()
{
    constexpr std::array<int, 5> arr = {4, -2, 7, -5, 9};
    int index = FindIndexOfLastNegative(arr.data(), arr.size());
    if (index == -1)
    {
        std::cout << "No negatives found!";
    }
    else
    {
        std::cout << "Last negative index: " << index;
    }
    return 0;
}