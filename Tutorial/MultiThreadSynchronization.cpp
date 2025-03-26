#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void waitForSignal(int id)
{
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Thread " << id << " waiting...\n";
    cv.wait(lock, []
            { return ready; }); // Wait until ready == true
    std::cout << "Thread " << id << " received signal and resumes.\n";
}

void sendSignal()
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    std::cout << "Sending signal...\n";
    cv.notify_all(); // Wake up ALL waiting threads
}

int main()
{
    std::vector<std::thread> threads;

    // Create multiple waiting threads
    for (int i = 1; i <= 3; ++i)
    {
        threads.emplace_back(waitForSignal, i);
    }

    std::thread t4(sendSignal); // Thread to send signal

    // Join all threads
    for (auto &t : threads)
    {
        t.join();
    }
    t4.join();

    return 0;
}