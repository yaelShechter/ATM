#include "menu_option.hpp"

MenuOption::MenuOption(std::string description, std::function<void()> handler):
    _description(std::move(description)),
    _handler(std::move(handler))
{}

void MenuOption::handle() const
{
    _handler();
}

std::string MenuOption::description() const
{
    return _description;
}
