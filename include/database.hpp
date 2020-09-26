#pragma once

#include <memory>

#include "user.hpp"

class Database
{
public:
    Database();

    virtual UserUPtr get_user(int id, std::string password) = 0;
    virtual void update_user(const UserUPtr& user) = 0;
};

using DatabaseUPtr = std::unique_ptr<Database>;
