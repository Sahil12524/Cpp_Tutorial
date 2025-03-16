/*
    nasm -f win64 ArrayHandling.asm -o ArrayHandling.o
    g++ -O0 ArrayHandling.cpp ArrayHandling.o -o ArrayHandling.exe -lm
    ArrayHandling.exe
*/

#include <iostream>
extern "C" float sum_array(const float *arr, const size_t size);
int main()
{
    const float arr[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    const size_t size = sizeof(arr) / sizeof(arr[0]);
    const float result = sum_array(arr, size);
    std::cout << "Sum of array elements: " << result << "\n";
    return 0;
}