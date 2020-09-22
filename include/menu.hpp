#pragma once

#include <map>

#include "account.hpp"
#include "menu_option.hpp"

class Menu
{
public:
    Menu(std::map<int, MenuOption> menu_options);
    ~Menu() = default;

    Menu(const Menu& other) = delete;
    Menu& operator=(const Menu& other) = delete;

    void invoke_menu_option(int key);
    void print_menu_options();

private:
    std::map<int, MenuOption> _menu_options;
};
