/*
    Find the maximum element in an integer array using Assembly.
*/

/*
    1. nasm -f win64 MaxInArrayTest.asm -o MaxInArrayTest.o
    2. g++ -O2 -std=c++17 MaxInArrayTest.cpp MaxInArrayTest.o -o MaxInArrayTest.exe
    3. MaxInArrayTest.exe
*/

#include <iostream>
#include <array>

extern "C" int MaxInArray(const int *arr, const size_t size);

int main()
{
    constexpr std::array<int, 10> arr = {-10, 50, 30, 5, 100, -20, 70, 65, 85, 10};
    int max = MaxInArray(arr.data(), arr.size());
    std::cout << "Max: " << max << "\n";
    return 0;
}