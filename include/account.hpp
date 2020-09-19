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