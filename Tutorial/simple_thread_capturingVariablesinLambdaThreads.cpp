#include <iostream>
#include <thread>

int main()
{
    int x = 100;
    std::thread t([x]()
                  { std::cout << "Thread received value: " << x << "\n"; });
    t.join();
    std::cout << "Main thread finished.\n";
    return 0;
}