/*
    CountGreaterAfter.cpp
    ----------------------
    For each element in the array, this program counts how many elements to its right are greater than it.

    Example:
        Input:  [3, 1, 4, 2]
        Output: [1, 2, 0, 0]

    1. nasm -f win64 CountGreaterAfter.asm -o CountGreaterAfter.o
    2. g++ -O2 -std=c++17 CountGreaterAfter.cpp CountGreaterAfter.o -o CountGreaterAfter.exe
    3. CountGreaterAfter.exe
*/

#include <iostream>
#include <array>

extern "C" void CountGreaterAfter(int *arr, int *out, size_t size);

int main()
{
    std::array<int, 4> arr = {3, 1, 4, 2};
    std::array<int, 4> result = {0};
    CountGreaterAfter(arr.data(), result.data(), arr.size());
    std::cout << "Input: \n";
    for (int x : arr)
        std::cout << x << " ";
    std::cout << "\nResult: \n";
    for (int x : result)
        std::cout << x << " ";
    std::cout << "\n";
    return 0;
}