/*
    LEAStaticCallback_Add.cpp
    -------------------------
    Demonstrates an Assembly function calling a C++ callback using LEA.

    Prototype (implemented in LEAStaticCallback_Add.asm):
        extern "C" void LEAStaticCallback_Add(void (*cb)(int*, int*, int*));

    Callback example:
        extern "C" void AddAndLog(int* a, int* b, int* sum)
        {
            *sum = (*a) + (*b);
            std::cout << *sum;
        }

    Expected Output:
        15

    Build (Windows x64):
        1. nasm -f win64 LEAStaticCallback_Add.asm -o LEAStaticCallback_Add.o
        2. g++  -O2 -std=c++17 LEAStaticCallback_Add.cpp LEAStaticCallback_Add.o -o LEAStaticCallback_Add.exe
        3. LEAStaticCallback_Add.exe
*/

#include <iostream>

extern "C" void AddAndLog(int *a, int *b, int *sum);

extern "C" void LEAStaticCallback_Add(void (*cb)(int *, int *, int *));

void AddAndLog(int *a, int *b, int *sum)
{
    *sum = (*a) + (*b);
    std::cout << *sum;
}

int main()
{
    LEAStaticCallback_Add(AddAndLog);
    return 0;
}