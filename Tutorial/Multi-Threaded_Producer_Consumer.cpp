#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <vector>

std::queue<int> dataQueue;  // Shared queue
std::mutex mtx;             // Mutex for synchronization
std::condition_variable cv; // Condition variable
bool finished = false;      // Signals when all producers are done

const int NUM_PRODUCERS = 2;      // Number of producers
const int NUM_CONSUMERS = 3;      // Number of consumers
const int ITEMS_PER_PRODUCER = 5; // Items produced per producer

void producer(int id)
{
    for (int i = 1; i <= ITEMS_PER_PRODUCER; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));
        std::lock_guard<std::mutex> lock(mtx);
        int item = id * 100 + i; // Unique item for each producer
        dataQueue.push(item);
        std::cout << "Producer " << id << " produced: " << item << "\n";
        cv.notify_one(); // Notify consumers
    }

    // After last producer finishes, set the finished flag
    static int finished_producers = 0;
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (++finished_producers == NUM_PRODUCERS)
        {
            finished = true;
            cv.notify_all(); // Wake up all consumers
        }
    }
}

void consumer(int id)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []
                { return !dataQueue.empty() || finished; });
        while (!dataQueue.empty()) // Consume all available items
        {
            int value = dataQueue.front();
            dataQueue.pop();
            std::cout << "Consumer " << id << " consumed: " << value << "\n";
        }

        if (finished && dataQueue.empty())
        {
            break; // Exit when production is finished and queue is empty
        }
    }
}

int main()
{
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    // Start multiple producer threads
    for (int i = 1; i <= NUM_PRODUCERS; ++i)
    {
        producers.emplace_back(producer, i);
    }

    // Start multiple consumer threads
    for (int i = 1; i <= NUM_CONSUMERS; ++i)
    {
        consumers.emplace_back(consumer, i);
    }

    // Join producer threads
    for (auto &t : producers)
    {
        t.join();
    }

    // Join consumer threads
    for (auto &t : consumers)
    {
        t.join();
    }

    std::cout << "Processing complete!\n";
    return 0;
}