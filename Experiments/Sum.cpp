/*
    Compile & Run:
    1. nasm -f win64 Sum.asm -o Sum.o
    2. g++ -O2 -fno-inline Sum.cpp Sum.o -o Sum.exe
    3. Sum.exe
*/

#include <iostream>

extern "C" int sum_array(const int *arr, const size_t size);

int main()
{
    const int arr[] = {1, 2, 3, 4, 5};
    const size_t size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array elements: ";
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    const int result = sum_array(arr, size);

    std::cout << "Sum of array elements: " << result << "\n";
    return 0;
}
