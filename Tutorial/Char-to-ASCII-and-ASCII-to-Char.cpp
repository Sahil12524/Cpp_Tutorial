/*
    Char to ASCII and ASCII to Char
*/

#include <iostream>
int main()
{
    char c1, c2, c3, c4, c5;
    std::cout << "Enter any 5 char: " << "\n";
    std::cin >> c1 >> c2 >> c3 >> c4 >> c5;
    std::cout << "ASCII: " << "\n";
    std::cout << int(c1) << " " << int(c2) << " " << int(c3) << " " << int(c4) << " " << int(c5) << " " << "\n";
    std::cout << "Decode: " << "\n";
    std::cout << char(c1) << char(c2) << char(c3) << char(c4) << char(c5) << "\n";
    return 0;
}