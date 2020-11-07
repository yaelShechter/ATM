#pragma once

#include <map>

#include "menu_option.hpp"

class Menu
{
public:
    explicit Menu(std::map<int, MenuOption> menu_options);
    virtual ~Menu() = default;

    Menu(const Menu& other) = default;
    Menu& operator=(const Menu& other) = delete;

    std::map<int, MenuOption> menu_options();
    void invoke_menu_option(int key);

private:
    std::map<int, MenuOption> _menu_options;
};