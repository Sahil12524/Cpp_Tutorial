/*
    In C++, define an array of integers.
    Call an Assembly function: SumArray(arr, size).
    In Assembly, loop through each element of the array, add them all up,
    and return the total sum.
    C++ will print the returned total.
*/

/*
    1. nasm -f win64 SumArrayTest.asm -o SumArrayTest.o
    2. g++ -O2 -std=c++17 SumArrayTest.cpp SumArrayTest.o -o SumArrayTest.exe
    3. SumArrayTest.exe
*/

#include <iostream>
#include <array>

extern "C" int SumArray(const int *arr, const size_t size);

int main()
{
    constexpr std::array<int, 10> arr = {10, 20, 30, 40, 50, 50, 60, 70, 80, 90};
    int result = SumArray(arr.data(), arr.size());
    std::cout << result;
    return 0;
}