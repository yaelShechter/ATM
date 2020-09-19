//
// Created by yaels on 17-Sep-20.
//
#pragma once

#include <map>

#include "account.hpp"
#include "menu_option.hpp"

class Menu {
public:
    Menu(std::map<int, MenuOption> menu_options);
    void invoke_menu_option(int key);
    void print_menu_options();

private:
    std::map<int, MenuOption> _menu_options;
};
