#pragma once

#include <memory>
#include <iostream>

#include "account.hpp"

class User {
public:
    User(int id, std::string password, AccountPtr account);
    ~User() = default;

    User(const User& other) = default;
    User& operator=(const User& other) = default;

    void change_password(std::string password);
    int id() const;
    std::string password() const;
    AccountPtr account();

private:
    int _id;
    std::string _password;
    AccountPtr _account;
};

using UserUPtr = std::unique_ptr<User>;