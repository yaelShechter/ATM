#pragma once

#include <vector>

#include "menu.hpp"
#include "user.hpp"
#include "account.hpp"
#include "database.hpp"
#include "login_error.hpp"
#include "text_file_database.hpp"


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
    void _run_logged_user_screen();
    void _login_user();
    void _show_balance();
    void _withdraw_cash();
    void _deposit_cash();
    int _input_cash();
    void _logout_user();
    std::map<int, MenuOption> _initialize_logged_menu_options();

    int _get_id();
    std::string _get_password();
    Account& _get_account();

private:
    UserUPtr _logged_in_user;
    Menu _logged_menu;
    bool _is_running;
    bool _is_user_logged_in;
    DatabaseUPtr _database;
};