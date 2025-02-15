#include <iostream>
int main()
{
    double num1, num2, result;
    char op;
    std::cout << "Example x operator y\n";
    std::cin >> num1;
    std::cin >> op;
    std::cin >> num2;
    switch (op)
    {
    case '+':
        result = num1 + num2;
        std::cout << num1 << " + " << num2 << " = " << result;
        break;

    case '-':
        result = num1 - num2;
        std::cout << num1 << " - " << num2 << " = " << result;
        break;

    case '*':
        result = num1 * num2;
        std::cout << num1 << " * " << num2 << " = " << result;
        break;

    case '/':
        result = num1 / num2;
        std::cout << num1 << " / " << num2 << " = " << result;
        break;

    case '%':
        bool isnum1INT, isnum2INT;
        isnum1INT = ((int)num1 == num1); // 5 == 5.0 -> true
        isnum2INT = ((int)num2 == num2); // 1 == 1.0 -> true
        if (isnum1INT && isnum2INT)
        {
            result = (int)num1 % (int)num2;
        }
        else
        {
            std::cout << "Not valid!\n";
            break;
        }
        std::cout << num1 << " % " << num2 << " = " << result;
        break;
    }
    return 0;
}