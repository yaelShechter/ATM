#include <iostream>

#include "db_error.hpp"
#include "login_error.hpp"
#include "id_input_error.hpp"
#include "cin_input_device.hpp"
#include "cout_output_device.hpp"
#include "text_file_database.hpp"
#include "password_input_error.hpp"
#include "atm.hpp"

ATM::ATM():
    _logged_in_user(nullptr),
    _logged_menu(_initialize_logged_menu_options()),
    _is_running(false),
    _database(std::make_unique<TextFileDatabase>(DATABASE_PATH)),
    _input_device(std::make_unique<CinInputDevice>()),
    _output_device(std::make_unique<CoutOutputDevice>())
{}

void ATM::run()
{
    _is_running = true;
    while(_is_running)
    {
        try
        {
            _logged_in_user = _login_user();
            _run_logged_user_screen();
        }
        catch (const LoginError& e)
        {}
    }
}

void ATM::_run_logged_user_screen()
{
    while(nullptr != _logged_in_user)
    {
        try
        {
            _output_device->print_menu(_logged_menu);
            int choice = _input_device->input_number();
            _logged_menu.invoke_menu_option(choice);
        }
        catch (const InputError& e)
        {
            _output_device->prompt_message("Input must be a number");
        }
        catch (const std::out_of_range& e)
        {
            _output_device->prompt_message("Invalid menu option");
        }
    }
}

UserUPtr ATM::_login_user()
{
    UserUPtr user;
    try
    {
        _output_device->prompt_message("Please enter id: ");
        int id = _input_device->input_id();
        _output_device->prompt_message("Please Enter Password: ");
        std::string password = _input_device->input_password();
        user = _database->get_user(id, password);
    }
    catch(const IdInputError& e)
    {
        _output_device->prompt_message("Id must be an integer.");
        throw LoginError("ATM:login_user: Bad id input.");
    }
    catch(const PasswordInputError& e)
    {
        _output_device->prompt_message("Bad password input");
        throw LoginError("ATM:login_user: Bad password input.");
    }
    catch(const DBError& e)
    {
        _output_device->prompt_message("Wrong credentials");
        throw LoginError("ATM:login_user: Bad password input.");
    }
    return user;
}

void ATM::_show_balance()
{
    _output_device->prompt_message("Your balance is: " + std::to_string(_logged_in_user->account()->balance()));
}

void ATM::_withdraw_cash()
{
    try {
        _output_device->prompt_message("Please enter the desired amount: ");
        int current_balance = _logged_in_user->account()->balance();
        int cash_to_withdraw = _input_device->input_number_with_range(0, std::numeric_limits<int>::max()); //may throw
        if (current_balance < cash_to_withdraw) {
            _output_device->prompt_message("balance can't be negative.");
        } else {
            _logged_in_user->account()->set_balance(current_balance - cash_to_withdraw);
            _database->update_user(_logged_in_user);
            _show_balance();
        }
    }
    catch (const InputError &e) {
        _output_device->prompt_message("Please enter a positive number");
        throw InputError("ATM:_deposit_cash: input was invalid");
    }
    catch (const DBError &e) {
        _output_device->prompt_message("Database could not be updated");
        throw DBError("ATM:_deposit_cash: something went wrong with the database");
    }
}

void ATM::_deposit_cash()
{
    try
    {
        int current_balance = _logged_in_user->account()->balance();
        _output_device->prompt_message("Please enter the desired amount: ");
        int cash_to_deposit = _input_device->input_number_with_range(0, std::numeric_limits<int>::max()); //may throw
        _logged_in_user->account()->set_balance(current_balance + cash_to_deposit);
        _database->update_user(_logged_in_user);
        _show_balance();
    }
    catch (const InputError& e)
    {
        _output_device->prompt_message("Please enter a positive number");
        throw InputError("ATM:_deposit_cash: input was invalid");
    }
    catch(const DBError& e)
    {
        _output_device->prompt_message("Database could not be updated");
        throw DBError("ATM:_deposit_cash: something went wrong with the database");
    }
}

void ATM::_logout_user()
{
    _logged_in_user = nullptr;
}

void ATM::_change_password()
{
    _output_device->prompt_message("Please enter password: ");
    std::string new_password = _input_device->input_password();// may throw

    _output_device->prompt_message("Please repeat password: ");
    std::string repeated_password = _input_device->input_password(); //may throw

    if (new_password == repeated_password)
    {
        _logged_in_user->set_password(new_password);
        _database->update_user(_logged_in_user);
    }
    else
    {
        _output_device->prompt_message("Passwords don't match");
    }
}

std::map<int, MenuOption> ATM::_initialize_logged_menu_options()
{
    return {
            {1, MenuOption("Show balance", [this] { _show_balance(); })},
            {2, MenuOption("Withdraw cash", [this] { _withdraw_cash(); })},
            {3, MenuOption("Deposit cash", [this] { _deposit_cash(); })},
            {4, MenuOption("Change password", [this] { _change_password(); })},
            {5, MenuOption("Exit", [this] { _logout_user(); })}
    };
}
