/*
    1. nasm -f win64 LoopingArrayTest.asm -o LoopingArrayTest.o
    2. g++ -O2 -std=c++17 LoopingArrayTest.cpp LoopingArrayTest.o -o LoopingArrayTest.exe
    3. LoopingArrayTest.exe
*/

#include <iostream>
#include <array>

extern "C" int ReadArray(const int *arr, const size_t size, size_t index);
extern "C" void DoubleElements(const int *arr, const size_t size);

void print_array(const int *arr, const size_t size);

int main()
{
    constexpr std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "[Unmodified]:\n";
    print_array(arr.data(), arr.size());

    std::cout << "\n[Modified]:\n";
    DoubleElements(arr.data(), arr.size());
    print_array(arr.data(), arr.size());

    return 0;
}
void print_array(const int *arr, const size_t size)
{
    std::cout << "Array Elements: ";
    for (size_t i = 0; i < size; ++i)
    {
        int elements = ReadArray(arr, size, i);
        std::cout << elements << " ";
    }
    std::cout << "\n";
}