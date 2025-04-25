/*
    SquareAndLog.cpp
    ----------------
    Passes 3 integers and a callback to an Assembly routine.
    The callback squares each value in-place and prints it.

    Prototype (implemented in SquareAndLog.asm):
        extern "C" void Apply3(int* a, int* b, int* c,
                               void (*cb)(int*));

    Callback example:
        extern "C" void SquareAndPrint(int* p)
        {
            *p = (*p) * (*p);
            std::cout << *p << ' ';
        }

    Expected Output (for input 2, 3, 4):
        4 9 16

    Build (Windows x64):
        1. nasm -f win64 SquareAndLog.asm -o SquareAndLog.o
        2. g++  -O2 -std=c++17 SquareAndLog.cpp SquareAndLog.o -o SquareAndLog.exe
        3. SquareAndLog.exe
*/

#include <iostream>

extern "C" void SquareAndPrint(int *p);

extern "C" void Apply3(int *a, int *b, int *c, void (*cb)(int *));

void SquareAndPrint(int *p)
{
    *p = (*p) * (*p);
    std::cout << *p << ' ';
}

int main()
{
    int a = 2, b = 3, c = 4;
    Apply3(&a, &b, &c, SquareAndPrint);
    return 0;
}