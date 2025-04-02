#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

std::queue<int> dataQueue;
std::mutex mtx;
std::condition_variable cv;
bool finished = false; // Signals when the producer is done producing

void producer()
{
    for (int i = 1; i <= 5; ++i) // Producing 5 items
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
        std::lock_guard<std::mutex> lock(mtx);
        dataQueue.push(i);
        std::cout << "Produced: " << i << "\n";
        cv.notify_one(); // Notify consumer
    }

    // Notify consumer that production is finished
    {
        std::lock_guard<std::mutex> lock(mtx);
        finished = true;
    }
    cv.notify_one();
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []
                { return !dataQueue.empty() || finished; });

        while (!dataQueue.empty()) // Process all available items
        {
            int value = dataQueue.front();
            dataQueue.pop();
            std::cout << "Consumed: " << value << "\n";
        }

        if (finished && dataQueue.empty())
            break; // Exit if production is done and queue is empty
    }
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    std::cout << "Processing complete!\n";
    return 0;
}
