/*
    Count how many elements in an array are strictly greater than a given threshold.
    Example input: {1, 5, 7, 3, 9}, threshold = 4 → Output: 3 (5, 7, 9)
*/

/*
    1. nasm -f win64 CountAboveThresholdTest.asm -o CountAboveThresholdTest.o
    2. g++ -O2 -std=c++17 CountAboveThresholdTest.cpp CountAboveThresholdTest.o -o CountAboveThresholdTest.exe
    3. CountAboveThresholdTest.exe
*/

#include <iostream>
#include <array>

extern "C" int CountAboveThreshold(const int *arr, size_t size, int threshold);

int main()
{
    constexpr std::array<int, 9> arr = {1, 5, 7, 3, 9, 10, 11, 12, 50};
    int result = CountAboveThreshold(arr.data(), arr.size(), 4);
    std::cout << result;
    return 0;
}