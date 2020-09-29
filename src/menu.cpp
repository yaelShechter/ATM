#include <map>

#include "menu.hpp"

Menu::Menu(std::map<int, MenuOptionPtr> menu_options):
    _menu_options(std::move(menu_options))
{}

std::map<int, MenuOptionPtr> Menu::menu_options()
{
    return _menu_options;
}

void Menu::invoke_menu_option(int key)
{
    _menu_options.at(key)->handle();
}