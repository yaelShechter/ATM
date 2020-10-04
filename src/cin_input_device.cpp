#include <iostream>

#include "login_error.hpp"
#include "input_error.hpp"
#include "id_input_error.hpp"
#include "password_input_error.hpp"
#include "cin_input_device.hpp"

int CinInputDevice::input_id()
{
    int id;
    if (!(std::cin >> id))
    {
        _reset_cin();
        throw IdInputError("CinInputDevice::input_id: Id must be an integer");
    }
    return id;
}

int CinInputDevice::input_number()
{
    int input_number;
    if(!(std::cin >> input_number))
    {
        _reset_cin();
        throw InputError("Exception: input must be an integer");
    }
    return input_number;
}

int CinInputDevice::input_number_with_range(int min_value, int max_value)
{
    int number = input_number();
    if(number < min_value or number > max_value)
    {
        throw InputError("Number is out of range.");
    }
    return number;
}

std::string CinInputDevice::input_password()
{
    std::string password;
    if(!(std::cin >> password))
    {
        throw PasswordInputError("CinInputDevice:input_password: Something went wrong with the password.");
    }
    return password;
}

void CinInputDevice::_reset_cin()
{
   std::cin.clear();
   std::cin.ignore();
}