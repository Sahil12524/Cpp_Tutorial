#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex cout_mutex;

void modifyValue(int &num)
{
    std::lock_guard<std::mutex> lock(cout_mutex);
    num += 10;
    std::cout << "Modified value inside thread: " << num << "\n";
}

int main()
{
    int value = 5;
    std::thread t1(modifyValue, std::ref(value));
    t1.join();

    std::cout << "Value in main after thread execution: " << value << "\n";
    return 0;
}