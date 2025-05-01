/*
    LEAStaticCallback_ArraySum.cpp
    ------------------------------
    Demonstrates an Assembly callback with a static array.

    Prototype (implemented in LEAStaticCallback_ArraySum.asm):
        extern "C" void LEAStaticCallback_ArraySum(void (*cb)(int*, int*, int*));

    Callback example:
        extern "C" void SumArray(int* arr, int* count, int* total)
        {
            *total = 0;
            for (int i = 0; i < *count; ++i)
                *total += arr[i];
            std::cout << *total;
        }

    Expected Output:
        15

    Build (Windows x64):
        1. nasm -f win64 LEAStaticCallback_ArraySum.asm -o LEAStaticCallback_ArraySum.o
        2. g++  -O2 -std=c++17 LEAStaticCallback_ArraySum.cpp LEAStaticCallback_ArraySum.o -o LEAStaticCallback_ArraySum.exe
        3. LEAStaticCallback_ArraySum.exe
*/

#include <iostream>

extern "C" void SumArray(int *arr, int *count, int *total);

extern "C" void LEAStaticCallback_ArraySum(void (*cb)(int *, int *, int *));

void SumArray(int *arr, int *count, int *total)
{
    *total = 0;
    for (size_t i = 0; i < *count; ++i)
    {
        *total += arr[i];
    }
    std::cout << *total;
}

int main()
{
    LEAStaticCallback_ArraySum(SumArray);
    return 0;
}