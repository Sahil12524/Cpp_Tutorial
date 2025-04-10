/*
    In C++, define an array of integers.
    Call the Assembly function CountEvens(arr, size).
    In ASM, loop through the array and count how many elements are even.
    Return the count to C++.
*/

/*
    1. nasm -f win64 CountEvensTest.asm -o CountEvensTest.o
    2. g++ -O2 -std=c++17 CountEvensTest.cpp CountEvensTest.o -o CountEvensTest.exe
    3. CountEvensTest.exe
*/

#include <iostream>
#include <array>

extern "C" int CountEvens(const int *arr, const size_t size);

int main()
{
    constexpr std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int result = CountEvens(arr.data(), arr.size());
    std::cout << result;
    return 0;
}