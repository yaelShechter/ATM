#include <iostream>

#include "login_error.hpp"
#include "input_device_cin.hpp"
#include "output_device_cout.hpp"
#include "text_file_database.hpp"
#include "atm.hpp"

ATM::ATM():
    _logged_in_user(nullptr),
    _logged_menu(_initialize_logged_menu_options()),
    _is_running(false),
    _database(std::make_unique<TextFileDatabase>(DATABASE_PATH)),
    _input_device(std::make_unique<InputDeviceCin>()),
    _output_device(std::make_unique<OutputDeviceCout>())
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

void ATM::_run_logged_user_screen()
{
    int choice;
    while(nullptr != _logged_in_user)
    {
        try
        {
            _output_device->print_menu(_logged_menu);
            choice = _input_device->input_number_with_range(1, 5);
            _logged_menu.invoke_menu_option(choice);
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

void ATM::_login_user()
{
    while(nullptr == _logged_in_user)
    {
        try
        {
            _output_device->request_for_id();
            int id = _input_device->input_id();
            _output_device->request_for_password();
            std::string password = _input_device->input_password();
            _logged_in_user = _database->get_user(id, password);
        }
        catch (const LoginError& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

void ATM::_show_balance()
{
    _output_device->display_balance(_logged_in_user->account()->balance());
}

void ATM::_withdraw_cash()
{
    int current_balance = _logged_in_user->account()->balance();
    _output_device->request_for_cash_amount();
    int cash_to_withdraw = _input_device->get_number();
    if(current_balance < cash_to_withdraw)
    {
        throw std::runtime_error("Exception: balance can't be negative.");
    }
    _logged_in_user->account()->set_balance(current_balance - cash_to_withdraw);
    _database->update_user(_logged_in_user);
    _show_balance();
}

void ATM::_deposit_cash()
{
    int current_balance = _logged_in_user->account()->balance();
    _output_device->request_for_cash_amount();
    int cash_to_deposit = _input_device->get_number();
    _logged_in_user->account()->set_balance(current_balance + cash_to_deposit);
    _database->update_user(_logged_in_user);
    _show_balance();
}

void ATM::_logout_user()
{
    _logged_in_user = nullptr;
}

void ATM::_change_password()
{
    _output_device->request_for_password();
    std::string new_password = _input_device->input_password();
    _output_device->request_for_repeated_password();
    std::string repeated_password = _input_device->input_password();
    if (new_password == repeated_password)
    {
        _logged_in_user->set_password(new_password);
        _database->update_user(_logged_in_user);
    }
    else
        _output_device->unmatched_passwords();
}

std::map<int, MenuOptionPtr> ATM::_initialize_logged_menu_options()
{
    std::map<int, MenuOptionPtr> map = {};
    map[1] = std::make_shared<MenuOption>("Show balance", [this] { _show_balance(); });
    map[2] = std::make_shared<MenuOption>("Withdraw cash", [this] { _withdraw_cash(); });
    map[3] = std::make_shared<MenuOption>("Deposit cash", [this] { _deposit_cash(); });
    map[4] = std::make_shared<MenuOption>("Change password", [this] { _change_password(); });
    map[5] = std::make_shared<MenuOption>("Exit", [this] { _logout_user(); });
    return map;
}