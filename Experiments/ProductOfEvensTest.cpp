/*
    Multiply all even numbers in an array (excluding zero).
    Example input: {2, 3, 4, 5} → Output: 8 (2 * 4)
*/

/*
    1. nasm -f win64 ProductOfEvensTest.asm -o ProductOfEvensTest.o
    2. g++ -O2 -std=c++17 ProductOfEvensTest.cpp ProductOfEvensTest.o -o ProductOfEvensTest.exe
    3. ProductOfEvensTest.exe
*/

#include <iostream>
#include <array>

extern "C" int ProductOfEvens(const int *arr, size_t size);

int main()
{
    constexpr std::array<int, 4> arr = {2, 3, 4, 5};
    int result = ProductOfEvens(arr.data(), arr.size());
    std::cout << result;
    return 0;
}