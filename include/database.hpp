#pragma once

#include <memory>

class Database
{
public:
    Database() = default;
    virtual ~Database() = default;

    Database(const Database& other) = delete;
    Database& operator=(const Database& other) = delete;

    virtual UserUPtr get_user(int id, std::string password) = 0;
    virtual void update_user(const UserUPtr& user) = 0;
};

using DatabaseUPtr = std::unique_ptr<Database>;
