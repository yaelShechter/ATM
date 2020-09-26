
#include "account.hpp"
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

AccountPtr User::account()
{
    return _account;
}