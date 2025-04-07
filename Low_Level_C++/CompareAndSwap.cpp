/*
    1. nasm -f win64 CompareAndSwap.asm -o CompareAndSwap.o
    2. g++ -O2 -std=c++17 -pthread CompareAndSwap.cpp CompareAndSwap.o -o CompareAndSwap.exe
    3. CompareAndSwap.exe
*/

#include <iostream>

extern "C" bool CompareAndSwap(int *ptr, int expected, int newVal);

int main()
{
    int value = 10;
    std::cout << "Original value: " << value << "\n";

    if (CompareAndSwap(&value, 10, 20))
    {
        std::cout << "Swap succeeded! New value: " << value << "\n";
    }
    else
    {
        std::cout << "Swap failed. Current value: " << value << "\n";
    }
    return 0;
}