#include <iostream>
#include <thread>
#include <mutex>

std::mutex cout_mutex; // Global mutex for std::cout

void printMessage(int id)
{
    std::lock_guard<std::mutex> lock(cout_mutex); // lock the mutex before printing (Ensure safe output)
    std::cout << "Hello from thread " << id << "!\n";
}

int main()
{
    std::thread t1(printMessage, 1);
    std::thread t2(printMessage, 2);
    std::thread t3(printMessage, 3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Hello from main thread!\n";
    return 0;
}