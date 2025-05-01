/*
    LEAHybridCallback_ArraySum.cpp
    ------------------------------
    Demonstrates hybrid callback:
    - Array and count come from main
    - Assembly defines result variable
    - Assembly passes all to callback using LEA

    extern "C" void LEAHybridCallback_ArraySum(int* arr, int* count, void (*cb)(int*, int*, int*));

    Callback:
        extern "C" void SumArray(int* arr, int* count, int* total)
        {
            *total = 0;
            for (int i = 0; i < *count; ++i)
                *total += arr[i];
            std::cout << *total;
        }

    Expected Output:
        15

    Build:
        1. nasm -f win64 LEAHybridCallback_ArraySum.asm -o LEAHybridCallback_ArraySum.o
        2. g++  -O2 -std=c++17 LEAHybridCallback_ArraySum.cpp LEAHybridCallback_ArraySum.o -o LEAHybridCallback_ArraySum.exe
        3. LEAHybridCallback_ArraySum.exe
*/

#include <iostream>
#include <array>

extern "C" void SumArray(int *arr, int *count, int *total);

extern "C" void LEAHybridCallback_ArraySum(int *arr, int *count, void (*cb)(int *, int *, int *));

void SumArray(int *arr, int *count, int *total)
{
    *total = 0;
    for (int i = 0; i < *count; ++i)
        *total += arr[i];
    std::cout << *total;
}

int main()
{
    std::array<int, 3> arr = {4, 5, 6};
    int count = arr.size();
    LEAHybridCallback_ArraySum(arr.data(), &count, SumArray);

    return 0;
}