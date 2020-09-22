#include <iostream>

#include "atm.hpp"

ATM::ATM():
    _account(),
    _menu(_initialize_menu_options()),
    _is_running(false)
{}

void ATM::run()
{
    int choice;
    _is_running = true;
    while(_is_running)
    {
        _menu.print_menu_options();
        std::cin >> choice;
        _menu.invoke_menu_option(choice);
    }
}

void ATM::_display_request_for_cash_amount()
{
    std::cout << "Please enter the desired amount: " << std::endl;
}

void ATM::_show_balance()
{
    std::cout << "Your balance is: " << _account.balance() << std::endl;
}

void ATM::_withdraw_cash()
{
    int cash_to_withdraw = _input_cash();
    _account.modify_balance(-cash_to_withdraw);
    _show_balance();
}

void ATM::_deposit_cash()
{
    int cash_to_deposit = _input_cash();
    _account.modify_balance(cash_to_deposit);
    _show_balance();
}

int ATM::_input_cash()
{
    int amount_of_cash;
    _display_request_for_cash_amount();
    std::cin >> amount_of_cash;
    return amount_of_cash;
}

void ATM::_exit_atm()
{
    _is_running = false;
}

std::map<int, MenuOption> ATM::_initialize_menu_options()
{
    return {
        {1, MenuOption("Show balance", std::bind(&ATM::_show_balance, this))},
        {2, MenuOption("Withdraw cash", std::bind(&ATM::_withdraw_cash, this))},
        {3, MenuOption("Deposit cash", std::bind(&ATM::_deposit_cash, this))},
        {4, MenuOption("Exit", std::bind(&ATM::_exit_atm, this))}
    };
}