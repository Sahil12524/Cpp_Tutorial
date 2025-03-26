#include <iostream>
#include <thread>

int main()
{
    std::thread t([]()
                  { std::cout << "Hello from lambda thread.\n"; });

    t.join();
    std::cout << "Hello from main thread!\n";
    return 0;
}