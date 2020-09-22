#include <iostream>

#include "account.hpp"

Account::Account():
    _balance(0)
{}

int Account::balance() const
{
    return _balance;
}

void Account::modify_balance(int amount_of_money)
{
    if(_balance + amount_of_money >= 0)
        _balance += amount_of_money;
    else
        std::cout << "Balance can't be negative" << std::endl;
}
