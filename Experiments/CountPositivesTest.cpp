/*
    Problem: Loop through an array of integers and count how many elements are positive (> 0).
    Input: int arr[] = {-5, 10, -3, 7, 0, 15};
    Output: 3 (positive numbers are 10, 7, 15)
*/

/*
    1. nasm -f win64 CountPositivesTest.asm -o CountPositivesTest.o
    2. g++ -O2 -std=c++17 CountPositivesTest.cpp CountPositivesTest.o -o CountPositivesTest.exe
    3. CountPositivesTest.exe
*/

#include <iostream>
#include <array>

extern "C" int CountPositives(const int *arr, const size_t size);

int main()
{
    constexpr std::array<int, 6> arr = {-5, 10, -3, 7, 0, 15};
    int result = CountPositives(arr.data(), arr.size());
    std::cout << result;
    return 0;
}