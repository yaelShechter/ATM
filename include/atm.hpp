//
// Created by yaels on 18-Sep-20.
//
#pragma once
#include "menu.hpp"
#include "account.hpp"

class ATM {
public:
    ATM();
    void run();

private:
    void show_balance();
    void withdraw_cash();
    void deposit_cash();
    void print_cash_to_modify();
    int modify_cash();
    void exit_atm();
    std::map<int, MenuOption> initialize_menu_options();

private:
    Account _account;
    Menu _menu;
    bool _is_running;
};

