/*
    1. nasm -f win64 BubbleSort.asm -o BubbleSort.o
    2. g++ -O2 -std=c++17 BubbleSort.cpp BubbleSort.o -o BubbleSort.exe
    3. BubbleSort.exe
*/

#include <iostream>
#include <array>

extern "C" int BubbleSort(int *arr, size_t size);

void print_array(const int *arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    std::array<int, 5> arr = {1, 5, 3, 2, 4};

    std::cout << "Before swap:\n";
    print_array(arr.data(), arr.size());

    std::cout << "\nAfter swap:\n";
    BubbleSort(arr.data(), arr.size());
    print_array(arr.data(), arr.size());
}
