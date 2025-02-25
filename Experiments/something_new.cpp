#include <iostream>
#include <cstdint>
int main()
{
    uint32_t location = 37, alignment = 16, result;
    result = (location + (alignment - 1)) & ~(alignment - 1);
    std::cout << result;
    return 0;
}