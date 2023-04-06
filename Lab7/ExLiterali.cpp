#include <iostream>

float operator"" _Kelvin(unsigned long long kelvin)
{
    return (float)(kelvin - 273.15);
}

float operator"" _Fahrenheit(unsigned long long fahrenheit)
{
    return ((float)((fahrenheit-32)*5))/9.0f;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin is " << a << " degrees Celsius." << std::endl;
    std::cout << "120 Fahrenheit is " << b << " degrees Celsius." << std::endl;

    return 0;
}