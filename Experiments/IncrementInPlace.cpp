/*
    IncrementInPlace.cpp
    --------------------
    Calls an Assembly routine that forwards the address of
    an integer to a callback. The callback increments the value
    in‑place.

    Prototype implemented in IncrementInPlace.asm:
        extern "C" void IncrementInPlace(int* value,
                                         void (*cb)(int*));

    Callback example:
        extern "C" void Inc(int* p) { (*p)++; }

    After the call:
        • The original integer should be increased by 1.

    Build (Windows x64):
        1. nasm -f win64 IncrementInPlace.asm -o IncrementInPlace.o
        2. g++  -O2 -std=c++17 IncrementInPlace.cpp IncrementInPlace.o -o IncrementInPlace.exe
        3. IncrementInPlace.exe
*/

#include <iostream>

extern "C" void Increment(int *num);

extern "C" void IncrementInPlace(int *value, void (*cb)(int *));

void Increment(int *num)
{
    (*num)++;
}

int main()
{
    int num = 7;
    IncrementInPlace(&num, Increment);
    std::cout << num;
    return 0;
}