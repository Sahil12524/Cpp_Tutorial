/*
    Problem Statement:
    Perform a shift operation on a signed integer based on the selected mode.
    The mode can be SAR, SAL, SHL, or SHR.

    op = 0 => SAR (Arithmetic right shift)
    op = 1 => SAL (Arithmetic left shift)
    op = 2 => SHL (Logical left shift)
    op = 3 => SHR (Logical right shift)

    Compile:
    nasm -f win64 UnifiedShiftDemo.asm -o UnifiedShiftDemo.o^
    && g++ -O2 -std=c++17 UnifiedShiftDemo.cpp UnifiedShiftDemo.o -o UnifiedShiftDemo.exe^
    && UnifiedShiftDemo.exe
*/

#include <iostream>
#include <string>

extern "C" int UnifiedShiftDemo(int num, int shift, int op);

// Utility to convert op code to readable name
std::string op_name(int op)
{
    switch (op)
    {
    case 0:
        return "SAR";
    case 1:
        return "SAL";
    case 2:
        return "SHL";
    case 3:
        return "SHR";
    default:
        return "UNKNOWN";
    }
}

void print_result(int num, int shift, int op)
{
    int result = UnifiedShiftDemo(num, shift, op);
    std::cout << "Input: " << num << ", Shift(k): " << shift
              << ", Op: " << op_name(op)
              << " => Result: " << result << '\n';
}

int main()
{
    // SAR tests
    print_result(8, 1, 0);  // SAR: 4
    print_result(-7, 1, 0); // SAR: -4

    // SAL tests (multiply by power of 2)
    print_result(5, 2, 1);  // SAL: 20
    print_result(-3, 3, 1); // SAL: -24

    // SHL tests (unsigned-style left shift)
    print_result(2, 3, 2);       // SHL: 16
    print_result(1 << 28, 2, 2); // SHL: big value (could overflow)

    // SHR tests (unsigned-style right shift)
    print_result(128, 3, 3); // SHR: 16
    print_result(-1, 4, 3);  // SHR: 0x0FFFFFFF or 268435455

    return 0;
}
