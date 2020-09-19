//
// Created by yaels on 15-Sep-20.
//
#pragma once

class Account
{
public:
    Account();
    int balance() const;
    void modify_balance(int amount_of_money);

private:
    int _balance;
};