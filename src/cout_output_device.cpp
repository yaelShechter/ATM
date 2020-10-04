#include <iostream>

#include "cout_output_device.hpp"

void CoutOutputDevice::prompt_message(std::string message)
{
    std::cout << message << std::endl;
}

void CoutOutputDevice::print_menu(Menu menu)
{
    for (auto const& [key, menu_option] : menu.menu_options())
    {
        std::cout << key << KEY_SEPARATOR << menu_option.description() << std::endl;
    }
}
