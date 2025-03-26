/*
    Explanation
    std::mutex mtx; → A mutex (lock) is used to ensure only one thread modifies counter at a time.
    std::lock_guard<std::mutex> lock(mtx); → Automatically locks and unlocks mtx.
    Locks mtx at the start of the scope.
    Unlocks mtx at the end (even if an exception occurs).
*/

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex cout_mutex;

void incrementCounter()
{
    for (int i = 0; i < 1000000; ++i)
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        ++counter;
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