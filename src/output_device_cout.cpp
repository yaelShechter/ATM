#include "output_device_cout.hpp"

void OutputDeviceCout::request_for_cash_amount()
{
    std::cout << "Please enter the desired amount: " << std::endl;
}

void OutputDeviceCout::request_for_number()
{
    std::cout << "Please enter number: " << std::endl;
}

void OutputDeviceCout::display_balance(int balance)
{
    std::cout << "Your balance is: " << balance << std::endl;
}

void OutputDeviceCout::request_for_id()
{
    std::cout << "Please enter your id: " << std::endl;

}

void OutputDeviceCout::request_for_password()
{
    std::cout << "Please enter password: " << std::endl;

}

void OutputDeviceCout::request_for_repeated_password()
{
    std::cout << "Please repeat your password: " << std::endl;

}

void OutputDeviceCout::unmatched_passwords()
{
    std::cout << "Passwords don't match." << std::endl;
}

void OutputDeviceCout::print_menu(Menu menu)
{
    for (auto const& [key, menu_option] : menu.map())
    {
        std::cout << key << KEY_SEPARATOR << menu_option.description() << std::endl;
    }
}
