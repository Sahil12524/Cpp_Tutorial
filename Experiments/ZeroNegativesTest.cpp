/*
    Set all negative numbers in the array to 0
*/

/*
    1. nasm -f win64 ZeroNegativesTest.asm -o ZeroNegativesTest.o
    2. g++ -O2 -std=c++17 ZeroNegativesTest.cpp ZeroNegativesTest.o -o ZeroNegativesTest.exe
    3. ZeroNegativesTest.exe
*/

#include <iostream>
#include <array>

extern "C" void ZeroNegatives(int *arr, const size_t size);

int main()
{
    std::array<int, 6> arr = {-5, 4, -3, -2, 1, -6};
    ZeroNegatives(arr.data(), arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}