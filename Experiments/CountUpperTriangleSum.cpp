/*
    CountUpperTriangleSum.cpp
    --------------------------
    Given a square matrix of integers stored in row-major order as a 1D array,
    calculate the **sum of the upper triangle**, excluding the diagonal.

    That means for all elements where column index `j > i`.

    Example (3x3 matrix):
        [ 1,  2,  3,
          4,  5,  6,
          7,  8,  9 ]

        Upper triangle (excluding diagonal): 2, 3, 6
        Sum = 11

    1. nasm -f win64 CountUpperTriangleSum.asm -o CountUpperTriangleSum.o
    2. g++ -O2 -std=c++17 CountUpperTriangleSum.cpp CountUpperTriangleSum.o -o CountUpperTriangleSum.exe
    3. CountUpperTriangleSum.exe
*/

#include <iostream>
#include <array>

extern "C" int CountUpperTriangleSum(const int *matrix, size_t size);

int main()
{
    constexpr std::array<int, 9> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int result = CountUpperTriangleSum(arr.data(), 3); // 3x3
    std::cout << result;
    return 0;
}