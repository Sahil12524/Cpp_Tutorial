#include <iostream>
int main()
{
    int a = 5, b = 4;
    std::cout << a + (b++) << std::endl;
    std::cout << (--a) + b << std::endl;

    std::cout << !(true && false) << std::endl;
    std::cout << (true && false || true) << std::endl;

    int x = 7;
    std::cout << (++x <= 9 && x + 2 >= 10) << std::endl;

    int y = 3;
    std::cout << (y == y++) << std::endl;

    float z = 8;
    z += 2;
    std::cout << z << std::endl;
    z /= 2;
    std::cout << z << std::endl;
}