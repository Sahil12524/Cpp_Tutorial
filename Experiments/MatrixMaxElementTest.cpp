/*
    MatrixMaxElementTest.cpp
    --------------------------
    Given a 2D matrix stored in row-major order as a 1D array,
    find the maximum element in the matrix using nested loops.

    The matrix is of size (rows x cols).
    Return the maximum integer value found.

    Example input (2x3): { 3, 8, 1, 5, 6, 2 } → Output: 8

    1. nasm -f win64 MatrixMaxElementTest.asm -o MatrixMaxElementTest.o
    2. g++ -O2 -std=c++17 MatrixMaxElementTest.cpp MatrixMaxElementTest.o -o MatrixMaxElementTest.exe
    3. MatrixMaxElementTest.exe
*/

#include <iostream>
#include <array>

extern "C" int MatrixMaxElement(const int *matrix, size_t rows, size_t cols);

typedef struct
{
    /* data */
    const int *data;
    size_t rows;
    size_t cols;
} MatrixView;

int main()
{
    constexpr std::array<int, 6> arr = {3, 8, 1, 5, 6, 2};
    MatrixView mat = {arr.data(), 2, 3};
    int result = MatrixMaxElement(mat.data, mat.rows, mat.cols);
    std::cout << result;
    return 0;
}