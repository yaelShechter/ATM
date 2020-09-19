#pragma once

#include "menu.hpp"
#include "account.hpp"

class ATM
{
public:
    ATM();

    void run();

private:
    static void _print_cash_to_modify();

private:
    void _show_balance();
    void _withdraw_cash();
    void _deposit_cash();
    int _modify_cash();
    void _exit_atm();
    std::map<int, MenuOption> _initialize_menu_options();

private:
    Account _account;
    Menu _menu;
    bool _is_running;
};