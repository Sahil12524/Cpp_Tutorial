/*
    Count the number of matching pairs (i, j) such that:
    - i < j
    - arr[i] == arr[j]

    Example:
    Input:  [3, 1, 4, 3, 1]
    Pairs:  (0,3), (1,4)
    Output: 2

    1. nasm -f win64 MatchingPairs.asm -o MatchingPairs.o
    2. g++ -O2 -std=c++17 MatchingPairs.cpp MatchingPairs.o -o MatchingPairs.exe
    3. MatchingPairs.exe
*/

#include <iostream>
#include <array>

extern "C" int MatchingPairs(const int *arr, size_t size);

int main()
{
    std::array<int, 5> arr = {3, 1, 4, 3, 1};
    int result = MatchingPairs(arr.data(), arr.size());
    std::cout << "Matching pairs: " << result << "\n";
    return 0;
}