/*
    Count how many elements in the array fall within a given inclusive range [min, max].
    Example input: {1, 5, 7, 3, 9}, min = 4, max = 9 → Output: 3 (5, 7, 9)
*/

/*
    1. nasm -f win64 CountRangeMatchesTest.asm -o CountRangeMatchesTest.o
    2. g++ -O2 -std=c++17 CountRangeMatchesTest.cpp CountRangeMatchesTest.o -o CountRangeMatchesTest.exe
    3. CountRangeMatchesTest.exe
*/

#include <iostream>
#include <array>

extern "C" int CountRangeMatches(const int *arr, size_t size, int min, int max);

int main()
{
    constexpr std::array<int, 5> arr = {1, 5, 7, 3, 9};
    int result = CountRangeMatches(arr.data(), arr.size(), 4, 9);
    std::cout << result;
    return 0;
}