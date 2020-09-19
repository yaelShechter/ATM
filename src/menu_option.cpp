//
// Created by yaels on 17-Sep-20.
//

#include <iostream>
#include "menu_option.hpp"


MenuOption::MenuOption(std::string description, std::function<void()> handler):
    _description(description),
    _handler(handler)
{}


void MenuOption::handle() const
{
    _handler();
}

std::string MenuOption::description() const
{
    return _description;
}
