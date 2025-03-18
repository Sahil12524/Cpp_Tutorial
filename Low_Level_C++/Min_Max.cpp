/*
    Compile & Run:
    1. nasm -f win64 Min_Max.asm -o Min_Max.o
    2. g++ Min_Max.cpp Min_Max.o -o Min_Max.exe
    3. Min_Max.exe
*/

#include <iostream>

extern "C" void minmax(int *arr, size_t size, int &max_value, int &min_value);

int main()
{
    int arr[] = {10, 20, 30, 40, 50, -5};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int max_value, min_value;

    asm volatile(
        "call minmax"
        : "=a"(max_value), "=d"(min_value)
        : "c"(arr), "d"(size));

    std::cout << "Maximum Value: " << max_value << std::endl;
    std::cout << "Minimum Value: " << min_value << std::endl;

    return 0;
}