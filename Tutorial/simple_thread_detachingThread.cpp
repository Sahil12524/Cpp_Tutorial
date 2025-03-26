/*
    ⚠️ Warning:
    1. A detached thread runs independently,
       so the main program must not exit before it finishes.

    2. If main() exits before the detached thread completes,
       undefined behavior can occur.
*/
#include <iostream>
#include <thread>

void printMessage()
{
    std::cout << "Hello from detached thread!\n";
}

int main()
{
    std::thread t(printMessage);
    t.detach(); // Thread runs independently
    std::cout << "Hello from main thread!\n";
    return 0;
}