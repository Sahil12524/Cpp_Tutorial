#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex cout_mutex; // Global mutex for std::cout

void printMessage(int id)
{
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Hello from thread " << id << "!\n";
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 1; i <= 5; ++i)
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