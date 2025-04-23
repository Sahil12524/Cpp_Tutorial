/*
    ApplyCallback.cpp
    -----------------
    Demonstrates passing a C++ callback into pure Assembly.
    The ASM routine iterates through the array and calls the callback
    on every element.

    Build steps (Windows x64, NASM + g++):
        1. nasm -f win64 ApplyCallback.asm -o ApplyCallback.o
        2. g++  -O2 -std=c++17 ApplyCallback.cpp ApplyCallback.o -o ApplyCallback.exe
        3. ApplyCallback.exe
*/

#include <iostream>
#include <array>

// ----- Callback prototype -----
extern "C" void DoubleElement(int *value);

// ----- ASM routine -----
extern "C" void ApplyCallback(int *arr, size_t size, void (*cb)(int *));

void DoubleElement(int *p)
{
    *p *= 2;
}

int main()
{
    std::array<int, 5> data = {1, 2, 3, 4, 5};
    std::cout << "Before: ";
    for (int v : data)
        std::cout << v << ' ';
    std::cout << '\n';

    // Call the ASM routine
    ApplyCallback(data.data(), data.size(), &DoubleElement);

    std::cout << "After: ";
    for (int v : data)
        std::cout << v << ' ';
    std::cout << '\n';
    return 0;
}