//
// Created by yaels on 15-Sep-20.
//

#include <iostream>
#include "../include/account.hpp"

Account::Account()
    :_balance(0){}

int Account::get_balance() const
{
    return _balance;
}

void Account::withdraw_cash(int amount)
{
    if (amount > _balance)
        std::cout << "Sorry, you cannot withdraw more money then you have in you account :(" << std::endl;
    else
        _balance -= amount;
}

void Account::deposit_cash(int amount)
{
    _balance += amount;
}