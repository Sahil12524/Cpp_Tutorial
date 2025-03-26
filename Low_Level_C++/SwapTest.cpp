/*
    1. nasm -f win64 SwapTest.asm -o SwapTest.o
    2. g++ -O2 -std=c++17 -pthread SwapTest.cpp SwapTest.o -o SwapTest.exe
    3. SwapTest.exe
*/

#include <iostream>
#include <thread>
#include <vector>

extern "C" void SwapAtomic(int *a, int val);

void threadFunc(int *sharedVar, int val)
{
    SwapAtomic(sharedVar, val);
}

int main()
{
    int sharedVar = 10;
    std::cout << "Before Swap: " << sharedVar << "\n";
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++i)
    {
        threads.emplace_back(threadFunc, &sharedVar, 100 + i);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << "After Swap: " << sharedVar << "\n";

    return 0;
}