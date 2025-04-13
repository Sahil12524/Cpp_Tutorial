/*
    Find the minimum value in the array.
    Example input: {7, 3, 8, 2, 10} → Output: 2
*/

/*
    1. nasm -f win64 MinInArrayTest.asm -o MinInArrayTest.o
    2. g++ -O2 -std=c++17 MinInArrayTest.cpp MinInArrayTest.o -o MinInArrayTest.exe
    3. MinInArrayTest.exe
*/

#include <iostream>
#include <array>

extern "C" int MinInArray(const int *arr, size_t size);

int main()
{
    constexpr std::array<int, 5> arr = {7, 3, 8, 2, 10};
    int result = MinInArray(arr.data(), arr.size());
    std::cout << "Minimum: " << result;
    return 0;
}