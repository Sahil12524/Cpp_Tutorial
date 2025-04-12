/*
    Return: Total sum of all odd numbers → in RAX
*/

/*
    1. nasm -f win64 SumOfOddsTest.asm -o SumOfOddsTest.o
    2. g++ -O2 -std=c++17 SumOfOddsTest.cpp SumOfOddsTest.o -o SumOfOddsTest.exe
    3. SumOfOddsTest.exe
*/

#include <iostream>
#include <array>

extern "C" int SumOfOdds(const int *arr, size_t size);

int main()
{
    constexpr std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    int result = SumOfOdds(arr.data(), arr.size());
    std::cout << result;
    return 0;
}