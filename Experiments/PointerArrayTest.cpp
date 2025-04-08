/*
    Allocates an array in C++
    Uses ASM to read and write to different elements using pointer arithmetic
    Array indexing via pointer math
    Memory addressing and offset calculation in Assembly
*/

/*
    1. nasm -f win64 PointerArrayTest.asm -o PointerArrayTest.o
    2. g++ -O2 -std=c++17 PointerArrayTest.cpp PointerArrayTest.o -o PointerArrayTest.exe
    3. PointerArrayTest.exe
*/
#include <iostream>
#include <array>

extern "C" int ReadArray(const int *arr, size_t size, size_t index);
extern "C" int ModifyArrayElement(const int *arr, size_t size, size_t index, int value);
extern "C" int ZeroFillArray(const int *arr, size_t size, size_t index);

void print_array(const int *arr, const size_t size);
void modify_array_element(const int *arr, const size_t size, size_t index, int value);
void zero_array_elements(const int *arr, const size_t size);

int main()
{
    constexpr std::array<int, 6> arr = {5, 10, 15, 20, 25, 30};

    std::cout << "[Unmodified array]:\n";

    print_array(arr.data(), arr.size());

    std::cout << "\n[Error Test]:\n";

    modify_array_element(arr.data(), arr.size(), 6, 45);

    std::cout << "\n[Modified array]:\n";

    modify_array_element(arr.data(), arr.size(), 2, 45);

    print_array(arr.data(), arr.size());

    std::cout << "\n[Zeroing Elements]:\n";

    zero_array_elements(arr.data(), arr.size());

    print_array(arr.data(), arr.size());

    return 0;
}

void print_array(const int *arr, const size_t size)
{
    std::cout << "Array Elements: ";
    for (size_t i = 0; i < size; ++i)
    {
        const int element = ReadArray(arr, size, i);
        std::cout << element << " ";
    }
    std::cout << "\n";
}

void modify_array_element(const int *arr, const size_t size, size_t index, int value)
{
    int error_code = ModifyArrayElement(arr, size, index, value);

    if (error_code == -1)
    {
        std::cout << "Index out of range\n";
    }
    else
    {
        ModifyArrayElement(arr, size, index, value);
    }
}

void zero_array_elements(const int *arr, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        ZeroFillArray(arr, size, i);
    }
}