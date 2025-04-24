/*
    NegateWithContext.cpp
    ---------------------
    ASM routine NegateWithContext walks an int array,
    calling   void cb(int* elem, void* ctx).

    Callback:
        - Negates the value at *elem
        - Increments ctx->calls

    After ASM returns we expect:
        • array values all negated
        • ctx.calls == element count

    Build:
        1. nasm -f win64 NegateWithContext.asm -o NegateWithContext.o
        2. g++  -O2 -std=c++17 NegateWithContext.cpp NegateWithContext.o -o NegateWithContext.exe
        3. NegateWithContext.exe
*/

#include <iostream>
#include <array>

struct Counter
{
    int calls = 0; // Initialize counter to 0
};

extern "C" void Negate(int *elem, void *ctx);
extern "C" void NegateWithContext(int *arr, size_t n, void (*cb)(int *, void *), void *ctx);

extern "C" void Negate(int *elem, void *ctx)
{
    // Negate the value in place
    *elem = -*elem;

    // Increment the counter inside ctx
    reinterpret_cast<Counter *>(ctx)->calls++;
}

int main()
{
    Counter c{0};                                // Initialize counter object
    std::array<int, 5> data = {1, -3, 5, -7, 9}; // Example array with 5 elements

    // Call the assembly function to negate array elements and update counter
    NegateWithContext(data.data(), data.size(), &Negate, &c);

    // Print the results
    std::cout << "calls = " << c.calls << "\narray: ";
    for (auto v : data)
        std::cout << v << ' ';
    std::cout << '\n';

    return 0;
}
