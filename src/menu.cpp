#include <map>
#include <iostream>

#include "menu_option.hpp"
#include "menu.hpp"

Menu::Menu(std::map<int, MenuOption> menu_options):
    _menu_options(menu_options)
{}

void Menu::invoke_menu_option(int key)
{
    _menu_options.at(key).handle();
}

void Menu::print_menu_options()
{
    for (auto const& [key, menu_option] : _menu_options)
    {
        std::cout << key << ") " << menu_option.description() << std::endl;
    }
}