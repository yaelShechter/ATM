#pragma once

#include <memory>
#include <ostream>

#include "account.hpp"

class User {
public:
    User(int id, std::string password, AccountPtr account);
    virtual ~User() = default;

    User(const User& other) = default;
    User& operator=(const User& other) = default;

    int id() const;
    std::string password() const;
    void set_password(std::string new_password);
    AccountPtr account();

private:
    int _id;
    std::string _password;
    AccountPtr _account;
};

using UserUPtr = std::unique_ptr<User>;

inline std::ostream& operator<<(std::ostream& user_string, const UserUPtr& user)
{
    user_string << user->id() << " " << user->password() << " " << user->account()->balance();
    return user_string;
}
