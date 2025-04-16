/*
    Check if all elements in the array are positive integers (> 0).
    Return 1 if all elements are positive, otherwise return 0.

    Example input: {1, 2, 3, 4} → Output: 1
    Example input: {1, -2, 3, 4} → Output: 0
*/

/*

    1. nasm -f win64 AllPositiveCheckTest.asm -o AllPositiveCheckTest.o
    2. g++ -O2 -std=c++17 AllPositiveCheckTest.cpp AllPositiveCheckTest.o -o AllPositiveCheckTest.exe
    3. AllPositiveCheckTest.exe
*/

#include <iostream>
#include <array>

extern "C" int AllPositiveCheck(const int *arr, size_t size);

void runTest(const std::array<int, 4> &arr, int testNumber);

int main()
{
    std::array<std::array<int, 4>, 2> testCases = {{{1, 2, 3, 4},
                                                    {1, -2, 3, 4}}};

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        runTest(testCases[i], static_cast<int>(i + 1));
    }

    return 0;
}

void runTest(const std::array<int, 4> &arr, int testNumber)
{
    int result = AllPositiveCheck(arr.data(), arr.size());
    std::cout << "Test Case " << testNumber << ": ";
    if (result == 1)
    {
        std::cout << "1\n";
    }
    else
    {
        std::cout << "0\n";
    }
}