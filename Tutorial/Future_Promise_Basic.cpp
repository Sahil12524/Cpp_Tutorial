#include <iostream>
#include <thread>
#include <future>

// Function that sets the value in the promise
void setValue(std::promise<int> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    p.set_value(42); // Set the value in the promise
}

int main()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future(); // Get the future from the promise..
    std::thread t(setValue, std::move(promiseObj));       // Pass promise to thread
    std::cout << "Waiting for the value..." << "\n";
    int result = futureObj.get();
    std::cout << "Received value: " << result << "\n";
    t.join();
    return 0;
}