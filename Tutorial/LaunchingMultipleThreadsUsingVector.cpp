/*
    Avoids manually creating variables like t1, t2, t3.
    Works for any number of threads dynamically.
    Uses std::vector<std::thread> for better management.
*/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex cout_mutex;

void printMessage(int id)
{
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Hello from thread " << id << "!\n";
}

int main()
{
    const int numThreads = 5; // Can change dynamically
    std::vector<std::thread> threads;
    for (int i = 1; i <= numThreads; i++)
    {
        threads.emplace_back(printMessage, i);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << "Hello from main thread!\n";
    return 0;
}