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

void Account::modify_balance(int amount_of_money)
{
    try
    {
        if(_balance + amount_of_money < 0)
        {
            throw amount_of_money;
        }
        _balance += amount_of_money;
    }
    catch (int)
    {
        std::cout << "Exception: balance can't be negative." << std::endl;
    }
}
