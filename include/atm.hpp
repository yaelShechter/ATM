#pragma once

#include <map>

#include "menu.hpp"
#include "user.hpp"
#include "database.hpp"
#include "menu_option.hpp"
#include "input_device.hpp"
#include "output_device.hpp"

class ATM
{
private:
    static inline const std::string DATABASE_PATH = "/home/yael/users.txt";

public:
    ATM();
    virtual ~ATM() = default;

    ATM(const ATM& other) = delete;
    ATM& operator=(const ATM& other) = delete;

    void run();

private:
    void _run_logged_user_screen();
    void _show_balance();
    void _withdraw_cash();
    void _deposit_cash();
    void _logout_user();
    void _change_password();
    UserUPtr _login_user();
    std::map<int, MenuOption> _initialize_logged_menu_options();

private:
    UserUPtr _logged_in_user;
    Menu _logged_menu;
    bool _is_running;
    DatabaseUPtr _database;
    InputDeviceUPtr _input_device;
    OutputDeviceUPtr _output_device;
};