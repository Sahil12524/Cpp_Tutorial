#include <iostream>
#include <thread>
#include <future>

void producer(std::promise<int> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    p.set_value(42); // Strore value in promise
}

int main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();   // Link future to promise
    std::thread t(producer, std::move(p)); // Pass promise to thread
    std::cout << "Waiting for value..." << "\n";
    int value = f.get();
    std::cout << "Received Value: " << value << "\n";
    t.join();
    return 0;
}