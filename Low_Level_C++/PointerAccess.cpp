/*
    1. nasm -f win64 PointerAccess.asm -o PointerAccess.o
    2. g++ -O2 -std=c++17 -pthread PointerAccess.cpp PointerAccess.o -o PointerAccess.exe
    3. PointerAccess.exe
*/

#include <iostream>

extern "C" int ReadValue(int *ptr);

int main()
{
    int x = 42;
    int result = ReadValue(&x);
    std::cout << "Value read from ASM: " << result << "\n";
    return 0;
}