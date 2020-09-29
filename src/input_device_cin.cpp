#include <iostream>

#include "login_error.hpp"
#include "input_device_cin.hpp"

InputDeviceCin::InputDeviceCin() = default;

int InputDeviceCin::input_id()
{
    int id;
    std::cin >> id;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw LoginError("Id must be an integer");
    }
    return id;
}

int InputDeviceCin::get_number()
{
    int input_number;
    if(!(std::cin >> input_number))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Exception: input must be an integer");
    }
    return input_number;
}

std::string InputDeviceCin::input_password()
{
    std::string password;
    if(!(std::cin >> password))
    {
        throw std::runtime_error("Something went wrong with the password.");
    }
    return password;
}


int InputDeviceCin::input_number_with_range(int min_value, int max_value)
{
    int input_number = get_number();
    if(input_number < min_value or input_number > max_value)
        throw std::runtime_error("Number is out of range.");
    return input_number;
}


