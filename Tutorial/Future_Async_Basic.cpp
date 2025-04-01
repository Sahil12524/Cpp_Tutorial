#include <iostream>
#include <future>
#include <thread>

// Function to compute a value
int computeValue()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 100;
}

int main()
{
    std::cout << "Starting async task...\n";

    // Launch async task
    std::future<int> result = std::async(std::launch::async, computeValue);

    std::cout << "Doing other work while waiting...\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Still waiting...\n";

    // Get result (this will block until computeValue() finishes)
    int value = result.get();

    std::cout << "Result: " << value << "\n";
    return 0;
}