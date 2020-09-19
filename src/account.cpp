//
// Created by yaels on 15-Sep-20.
//
#include <iostream>
#include "account.hpp"

Account::Account()
        :_balance(0)
{}

int Account::get_balance() const
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
