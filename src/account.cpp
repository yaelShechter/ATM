//
// Created by yaels on 15-Sep-20.
//

#include "../include/account.hpp"

Account::Account()
        :_balance(0)
{}

int Account::get_balance() const
{
    return _balance;
}

void Account::modify_balance(int amount_of_money)
{
    _balance += amount_of_money;
}
