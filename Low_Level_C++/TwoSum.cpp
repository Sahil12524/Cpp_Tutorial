/*
    Check if any pair in the array adds up to a given target.
    Uses nested loops (brute force).

    Example:
    {1, 3, 5, 7}, target = 8 → Output: 1 (found)
    {2, 4, 6}, target = 13 → Output: 0 (not found)

    1. nasm -f win64 TwoSum.asm -o TwoSum.o
    2. g++ -O2 -std=c++17 TwoSum.cpp TwoSum.o -o TwoSum.exe
    3. TwoSum.exe
*/

#include <iostream>
#include <array>

extern "C" int TwoSum(const int *arr, size_t size, int target);

int main()
{
    // std::array<int, 4> arr = {1, 3, 5, 7};
    std::array<int, 4> arr = {2, 4, 6};
    int target = 13;
    int result = TwoSum(arr.data(), arr.size(), target);

    if (result == 1)
    {
        std::cout << "Two numbers found that sum to " << target << "!\n";
    }
    else
    {
        std::cout << "No two numbers found that sum to " << target << ".\n";
    }

    return 0;
}