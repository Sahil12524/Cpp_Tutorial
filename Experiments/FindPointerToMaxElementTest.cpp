/*
    FindPointerToMaxElementTest.cpp
    ----------------------
    Given an array of integers, return a pointer to the maximum element.

    Example:
        Input:  [3, 9, 4, 15, 6]
        Output: pointer to 15

        Explanation:
        - Maximum value is 15
        → Return its address (as a pointer)

    1. nasm -f win64 FindPointerToMaxElementTest.asm -o FindPointerToMaxElementTest.o
    2. g++ -O2 -std=c++17 FindPointerToMaxElementTest.cpp FindPointerToMaxElementTest.o -o FindPointerToMaxElementTest.exe
    3. FindPointerToMaxElementTest.exe
*/

#include <iostream>
#include <array>

extern "C" void *FindPointerToMaxElement(const int *input, size_t size);

int main()
{
    constexpr std::array<int, 5> arr = {3, 9, 4, 15, 6};
    int *max_element_address = nullptr;

    max_element_address = (int *)FindPointerToMaxElement(arr.data(), arr.size());

    std::cout << "Address of maximum element: " << max_element_address << "\n";

    if (max_element_address)
        std::cout << "Value on that address: " << *max_element_address;
    else
        std::cout << "Null pointer returned!";
    return 0;
}