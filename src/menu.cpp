#include <map>
#include <iostream>

#include "menu_option.hpp"
#include "menu.hpp"

Menu::Menu(std::map<int, MenuOption> menu_options):
    _menu_options(menu_options)
{}

std::map<int, MenuOption> Menu::map()
{
    return _menu_options;
}

void Menu::invoke_menu_option(int key)
{
    _menu_options.at(key).handle();
}