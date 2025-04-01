/*
    This is a Generated Test Question to solve (Exam).

    1. Create a function that performs a time-consuming task (e.g., calculating the sum of a large range).
    2. Use std::async to run it asynchronously.
    3. Use std::future to retrieve the result.

    C++ File Name Suggestion: async_example.cpp
*/

#include <iostream>
#include <thread>
#include <future>

unsigned long int findOdd(const unsigned long int start, const unsigned long int end)
{
    unsigned long int oddSum = 0;
    for (unsigned long int i = start; i <= end; ++i)
    {
        if (i & 1)
        {
            ++oddSum;
        }
    }
    return oddSum;
}

int main()
{
    constexpr unsigned long int start = 0;
    constexpr unsigned long int end = 1'000'000'000;

    std::cout << "Starting async task...\n";

    std::future<unsigned long int> oddSum = std::async(std::launch::deferred, findOdd, start, end);

    std::cout << "Doing other work while waiting...\n";

    unsigned long int value = oddSum.get();

    std::cout << "oddSum = " << value << "\n";
    return 0;
}