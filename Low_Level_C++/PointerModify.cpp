/*
    1. nasm -f win64 PointerModify.asm -o PointerModify.o
    2. g++ -O2 -std=c++17 PointerModify.cpp PointerModify.o -o PointerModify.exe
    3. PointerModify.exe
*/

#include <iostream>

extern "C" void ModifyValue(int *ptr);

int main()
{
    int value = 42;
    std::cout << "Before: " << value << "\n";
    ModifyValue(&value);
    std::cout << "After: " << value << "\n";
    return 0;
}