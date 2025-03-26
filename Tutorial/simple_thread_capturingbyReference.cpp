#include <iostream>
#include <thread>

int main()
{
    int x = 100;
    std::cout << "Value of x before modification: " << x << "\n";
    std::thread t([&x]()
                  {
        x += 50;
        std::cout << "Thread modified x: " << x << "\n"; });
    t.join();
    std::cout << "Final value of x: " << x << "\n";
    return 0;
}