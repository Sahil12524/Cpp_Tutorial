#include <iostream>
#include <thread>

void threadFunction()
{
    std::cout << "Hello from thread!\n";
}

int main()
{
    // threadFunction is used as function callback in thread.
    std::thread t(threadFunction); // Create a thread that runs threadFunction
    t.join();                      // Wait for the thread to finish
    std::cout << "Hello from main thread!\n";
    return 0;
}