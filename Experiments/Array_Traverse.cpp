/*
    1. nasm -f win64 Array_Traverse.asm -o Array_Traverse.o
    2. g++ -std=c++17 Array_Traverse.cpp Array_Traverse.o -o Array_Traverse.exe
    3. Array_Traverse.exe
*/

#include <iostream>
#include <array>

extern "C" int traverse_array(const int *arr, size_t size, size_t index);

void print_array(const int *arr, const size_t size)
{
    std::cout << "Array elements: ";
    for (size_t i = 0; i < size; ++i)
    {
        const int element = traverse_array(arr, size, i);
        std::cout << element << " ";
        
    }
    std::cout << "\n";
}

int main()
{
    constexpr std::array<int, 5> arr = {10, 20, 30, 40, 50};
    print_array(arr.data(), arr.size());
    return 0;
}
