#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false; // Shared flag

void waitForSignal()
{
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Waiting for signal...\n";
    cv.wait(lock, []
            { return ready; }); // Wait until 'ready' is true
    std::cout << "Signal received! Thread resuming...\n";
}

void sendSignal()
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate some work
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        std::cout << "Sending signal...\n";
    }
    cv.notify_one(); // Notify the waiting thread
}

int main()
{
    std::thread t1(waitForSignal);
    std::thread t2(sendSignal);

    t1.join();
    t2.join();

    std::cout << "Main thread exiting.\n";
    return 0;
}