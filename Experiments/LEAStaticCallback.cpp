/*
    LEAStaticCallback.cpp
    ---------------------
    Demonstrates a callback where the address of static integers
    is generated using LEA in Assembly.

    Prototype (implemented in LEAStaticCallback.asm):
        extern "C" void LEAStaticCallback(void (*cb)(int*, int*, int*));

    Callback example:
        extern "C" void MultiplyAndLog(int* a, int* b, int* result)
        {
            *result = (*a) * (*b);
            std::cout << *result;
        }

    Expected Output:
        12

    Build (Windows x64):
        1. nasm -f win64 LEAStaticCallback.asm -o LEAStaticCallback.o
        2. g++  -O2 -std=c++17 LEAStaticCallback.cpp LEAStaticCallback.o -o LEAStaticCallback.exe
        3. LEAStaticCallback.exe
*/

#include <iostream>

extern "C" void MultiplyAndLog(int *a, int *b, int *result);

extern "C" void LEAStaticCallback(void (*cb)(int *, int *, int *));

void MultiplyAndLog(int *a, int *b, int *result)
{
    *result = (*a) * (*b);
    std::cout << *result;
}

int main()
{
    LEAStaticCallback(MultiplyAndLog);
    return 0;
}