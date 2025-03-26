/*
    No need to define a separate function.
    Makes code shorter & more readable.
    Helps in temporary, small tasks where defining functions is overkill.
*/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex cout_mutex;

int main()
{
    const int numThreads = 5;
    std::vector<std::thread> threads;
    for (int i = 1; i <= numThreads; i++)
    {
        threads.emplace_back([i]()
                             {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << "Hello from thread " << i << "!\n"; });
    }

    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << "Hello from main thread!\n";
    return 0;
}