#include <iostream>
int main()
{
    float weight, height, bmi;

    std::cout << "Weight (kg) and Height (m): ";
    std::cin >> weight >> height;

    bmi = weight / (height * height);

    std::cout << "Your BMI is " << bmi << " so you are ";

    if (bmi < 18.5)
        std::cout << "Underweight" << "\n";
    else if (bmi > 25)
        std::cout << "Overweight" << "\n";
    else
        std::cout << "Normal weight" << "\n";
}