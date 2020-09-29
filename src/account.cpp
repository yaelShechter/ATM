#include <iostream>

#include "account.hpp"

Account::Account(int balance):
    _balance(balance)
{}

int Account::balance() const
{
    return _balance;
}

void Account::set_balance(int new_balance)
{
    _balance = new_balance;
}

