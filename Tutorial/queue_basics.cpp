#include <iostream>
#include <queue>

int main()
{
    std::queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front element: " << q.front() << "\n";
    std::cout << "Back element: " << q.back() << "\n";

    // Pop elements from the queue
    q.pop();
    std::cout << "After popping, front element: " << q.front() << "\n";
    return 0;
}