/*
    SumCallback.cpp
    ----------------
    Demonstration of passing a callback from C++ to pure Assembly.

    Goal:
        •  Assembly routine SumCallback walks an integer array.
        •  For each element it calls a callback:  int cb(int value);
        •  It adds every callback return to a running total.
        •  It returns the final total to C++.

    Assembly prototype (implemented in SumCallback.asm):
        extern "C" int SumCallback(const int* arr,
                                   size_t       size,
                                   int        (*cb)(int));

    Example usage:
        // Callback that squares its input value
        int Square(int x) { return x * x; }

        int data[3] = {2, 3, 4};
        int total = SumCallback(data, 3, &Square);
        // total = 2² + 3² + 4² = 4 + 9 + 16 = 29

    Build steps (Windows x64 – NASM + g++):
        1. nasm -f win64 SumCallback.asm -o SumCallback.o
        2. g++  -O2 -std=c++17 SumCallback.cpp SumCallback.o -o SumCallback.exe
        3. SumCallback.exe
*/

#include <iostream>
#include <array>

extern "C" int Square(int x);                                         // example callback
extern "C" int ApplyAndSum(const int *arr, size_t n, int (*cb)(int)); // ASM

int Square(int x) { return x * x; }

int main()
{
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    int sum = ApplyAndSum(arr.data(), arr.size(), &Square);

    std::cout << "summation of squared array elements: " << sum;
    return 0;
}