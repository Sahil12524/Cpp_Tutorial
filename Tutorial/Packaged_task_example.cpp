#include <iostream>
#include <thread>
#include <future>
#include <chrono>

// Function that simulate work
int computeValue(int x)
{
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate delay
    return x * 2;
}

int main()
{
    // Step 1: Create a package_task with the computeValue function
    std::packaged_task<int(int)> task(computeValue); // Wraps the function

    // Step 2: Get the future from ther packaged_task
    std::future<int> result = task.get_future();

    // Step 3: Run the task asynchronously in a separate thread
    std::thread t(std::move(task), 10); // Move the task into the thread

    // Step 4: Do something else while the task runs
    std::cout << "Main thread is doing other work...\n";

    // Step 5: Wait for the resutlt and get the value
    int value = result.get();

    // Step 6: Display the result
    std::cout << "Compared value: " << value << "\n";
    t.join();

    return 0;
}