/*
** EPITECH PROJECT, 2026
** MyCat
** File description:
** StupidUnitConverter
*/

#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

int convert_fareinheit_to_celcius(float value)
{
    std::ostringstream string_result;
    float result = 5.0 / 9.0 * (value - 32);

    std::cout << std::setfill(' ') << std::setw(16) << std::fixed << std::setprecision(3) << result;
    std::cout << std::setfill(' ') << std::setw(16) << std::fixed << std::setprecision(3) << "Celsius" << std::endl;
    return 0;
}

int convert_celcius_to_fahrenheit(float value)
{
    float result = value * 9.0 / 5.0 + 32;

    std::cout << std::setfill(' ') << std::setw(16) << std::fixed << std::setprecision(3) << result;
    std::cout << std::setfill(' ') << std::setw(16) << std::fixed << std::setprecision(3) << "Fahrenheit" << std::endl;
    return 0;
}

int main(void)
{
    std::stringstream buffer;
    std::string buffer_string;
    float temperature;
    std::string unit;

    while (std::getline(std::cin, buffer_string)) {
        buffer = std::stringstream(buffer_string);
        if (buffer.fail())
            continue;
        if (!(buffer >> temperature))
            continue;
        if (!(buffer >> unit))
            continue;
        if (unit == "Celsius")
            convert_celcius_to_fahrenheit(temperature);
        if (unit == "Fahrenheit")
            convert_fareinheit_to_celcius(temperature);
    }
}
