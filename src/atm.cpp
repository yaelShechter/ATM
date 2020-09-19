//
// Created by yaels on 18-Sep-20.
//

#include "atm.hpp"

ATM::ATM():
        _account(),
        _menu(initialize_menu_options()),
        _is_running(false)
{}

void ATM::show_balance()
{
    std::cout << "Your balance is: " << _account.balance() << std::endl;
}

void ATM::withdraw_cash()
{
    int cash_to_withdraw = modify_cash();
    if(_account.balance() < cash_to_withdraw)
        _account.modify_balance(cash_to_withdraw);
    else
        std::cout << "Balance can't be negative" << std::endl;
}

void ATM::deposit_cash()
{
    int cash_to_deposit = modify_cash();
    _account.modify_balance(cash_to_deposit);
}

void ATM::exit_atm()
{
    _is_running = false;
}

void ATM::print_cash_to_modify()
{
    std::cout << "Please enter the amount you would like to modify: " << std::endl;
}

int ATM::modify_cash()
{
    int amount_of_cash;
    print_cash_to_modify();
    std::cin >> amount_of_cash;
    return amount_of_cash;
}


std::map<int, MenuOption> ATM::initialize_menu_options()
{
    return {
            {1, MenuOption("show balance", std::bind(&ATM::show_balance, this))},
            {2, MenuOption("withdraw cash", std::bind(&ATM::withdraw_cash, this))},
            {3, MenuOption("deposit cash", std::bind(&ATM::deposit_cash, this))},
            {4, MenuOption("exit", std::bind(&ATM::exit_atm, this))}
    };
}

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
