#pragma once

class Account
{
public:
    Account();
    ~Account() = default;

    Account(const Account& other) = delete;
    Account& operator=(const Account& other) = delete;

    int balance() const;
    void modify_balance(int amount_of_money);

private:
    int _balance;
};