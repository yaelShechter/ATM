#include "user.hpp"

User::User(int id, std::string password, AccountPtr account):
    _id(id),
    _password(std::move(password)),
    _account(account)
{}

int User::id() const
{
    return _id;
}

std::string User::password() const
{
    return _password;
}

void User::set_password(std::string new_password)
{
    _password = std::move(new_password);
}

AccountPtr User::account()
{
    return _account;
}
