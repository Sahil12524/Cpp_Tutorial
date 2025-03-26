#include <iostream>
#include <thread>

void threadFunc(int x)
{
    std::cout << "Thread received value: " << x << "\n";
}

int main()
{
    int num = 42;
    std::thread t(threadFunc, num); // Pass num as an argument to the thread
    t.join();                       // Wait for the thread to finish
    std::cout << "Main thread finished.\n";
    return 0;
}