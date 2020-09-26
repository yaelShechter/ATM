#include <iostream>
#include <algorithm>

#include "user.hpp"
#include "atm.hpp"

ATM::ATM():
        _logged_in_user(nullptr),
        _logged_menu(_initialize_logged_menu_options()),
        _is_running(false),
        _is_user_logged_in(false),
        _database(std::make_unique<TextFileDatabase>("users.txt"))
{}

void ATM::run()
{
    _is_running = true;
    while(_is_running)
    {
        try
        {
            _login_user();
            _run_logged_user_screen();
        }
        catch (const LoginError& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

void ATM::_display_request_for_cash_amount()
{
    std::cout << "Please enter the desired amount: " << std::endl;
}

void ATM::_run_logged_user_screen()
{
    int choice;
    while(_is_user_logged_in)
    {
        _logged_menu.print_menu_options();
        std::cin >> choice;
        _logged_menu.invoke_menu_option(choice);
    }
}

void ATM::_login_user()
{
    int id = _get_id();
    std::string password = _get_password();
    _logged_in_user = _database->get_user(id, password);
}

void ATM::_show_balance()
{
    std::cout << "Your balance is: " << _logged_in_user->account()->balance() << std::endl;
}

void ATM::_withdraw_cash()
{
    int cash_to_withdraw = _input_cash();
    _logged_in_user->account()->modify_balance(-cash_to_withdraw);
    _show_balance();
}

void ATM::_deposit_cash()
{
    int cash_to_deposit = _input_cash();
    _logged_in_user->account()->modify_balance(cash_to_deposit);
    _show_balance();
}

int ATM::_input_cash()
{
    int amount_of_cash;
    _display_request_for_cash_amount();
    std::cin >> amount_of_cash;
    try
    {
        if(std::cin.fail())
        {
            std::cin.clear();
            throw std::runtime_error("Exception: input must be an integer");
        }
    }
    catch (std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return amount_of_cash;
}

void ATM::_logout_user()
{
    _logged_in_user = nullptr;
    _is_user_logged_in = false;
}

std::map<int, MenuOption> ATM::_initialize_logged_menu_options()
{
    return {
        {1, MenuOption("Show balance", std::bind(&ATM::_show_balance, this))},
        {2, MenuOption("Withdraw cash", std::bind(&ATM::_withdraw_cash, this))},
        {3, MenuOption("Deposit cash", std::bind(&ATM::_deposit_cash, this))},
        {4, MenuOption("Exit", std::bind(&ATM::_logout_user, this))}
    };
}

int ATM::_get_id()
{
    int id;
    std::cout << "Please enter your id: " << std::endl;
    std::cin >> id;
    return id;
}

std::string ATM::_get_password()
{
    std::string password;
    std::cout << "Please enter your password: " << std::endl;
    std::cin >> password;
    return password;
}
