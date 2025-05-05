/*
    Problem Statement
    Write an ASM function that checks if a number is even or odd using bitwise operation.

    If the number is even, print: Even
    If the number is odd, print: Odd

    Concept:
    Use the bitwise AND operation:
    test rdi, 1

    If LSB is 1, it's odd.
    If LSB is 0, it's even.

    nasm -f win64 CheckEvenOdd.asm -o CheckEvenOdd.o
    g++ -O2 -std=c++17 CheckEvenOdd.cpp CheckEvenOdd.o -o CheckEvenOdd.exe
    CheckEvenOdd.exe
*/

#include <iostream>

extern "C" void CheckEvenOdd(int num);

int main()
{
    int value = 7;
    CheckEvenOdd(value);
    CheckEvenOdd(8);
    CheckEvenOdd(9);
    CheckEvenOdd(10);
    return 0;
}