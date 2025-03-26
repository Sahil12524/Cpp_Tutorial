/*
    ⚠️ Expected vs. Actual Output
    Expected Output: Final Counter Value: 2000000
    Actual Output: ❌ Random Incorrect Values (e.g., 1839472, 1920483, etc.)

    This happens because ++counter is not an atomic operation—it consists of multiple steps:
    1. Read counter from memory.
    2. Increment it.
    3. Write back the new value.

    Since both threads run in parallel, they can read the same old value before updating it,
    causing data corruption.
*/

#include <iostream>
#include <thread>

int counter = 0; // Shared resources

void incrementCounter()
{
    for (int i = 0; i < 1000000; ++i)
    {
        ++counter; // Unsafe: Multiple threads modifying the same variable
    }
}

int main()
{
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout << "Final Counter Value: " << counter << "\n";
    return 0;
}