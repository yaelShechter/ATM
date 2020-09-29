#pragma once

#include <vector>
#include <map>

#include "menu.hpp"
#include "user.hpp"
#include "database.hpp"
#include "menu_option.hpp"
#include "input_device.hpp"
#include "output_device.hpp"

class ATM
{
public:
    ATM();
    virtual ~ATM() = default;

    ATM(const ATM& other) = delete;
    ATM& operator=(const ATM& other) = delete;

    void run();

private:
    static void _display_request_for_cash_amount();
    static inline const std::string DATABASE_PATH = "/home/yael/users.txt";

private:
    void _run_logged_user_screen();
    void _login_user();
    void _show_balance();
    void _withdraw_cash();
    void _deposit_cash();
    void _logout_user();
    void _change_password();
    std::map<int, MenuOption> _initialize_logged_menu_options();

private:
    UserUPtr _logged_in_user;
    Menu _logged_menu;
    bool _is_running;
    DatabaseUPtr _database;
    InputDeviceUPtr _input_device;
    OutputDeviceUPtr _output_device;
};