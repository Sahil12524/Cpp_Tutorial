/*
    Compile & Run:
    1. nasm -f win64 Compare.asm -o Compare.o
    2. g++ Compare.cpp Compare.o -o Compare.exe
    3. Compare.exe
*/
#include <iostream>

extern "C" int compare_integers(const int a, const int b);

int main()
{
    constexpr int num1 = -40, num2 = 32;

    // std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;

    const int result = compare_integers(num1, num2);

    if (result == 1)
        std::cout << num1 << " is greater than " << num2 << "\n";

    else if (result == -1)
        std::cout << num1 << " is less than " << num2 << "\n";

    else
        std::cout << num1 << " is equal to " << num2 << "\n";

    return 0;
}