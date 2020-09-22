#pragma once

#include "menu.hpp"
#include "account.hpp"

class ATM
{
public:
    ATM();
    ~ATM() = default;

    ATM(const ATM& other) = delete;
    ATM& operator=(const ATM& other) = delete;

    void run();

private:
    static void _display_request_for_cash_amount();

private:
    void _show_balance();
    void _withdraw_cash();
    void _deposit_cash();
    int _input_cash();
    void _exit_atm();
    std::map<int, MenuOption> _initialize_menu_options();

private:
    Account _account;
    Menu _menu;
    bool _is_running;
};