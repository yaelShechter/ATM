#pragma once

#include <memory>

class Account
{
public:
    Account(int balance);
    ~Account() = default;

    Account(const Account& other) = default;
    Account& operator=(const Account& other) = default;

    int balance() const;
    void set_balance(int new_balance);
    void modify_balance(int amount_of_money);

private:
    int _balance;
};

using AccountPtr = std::shared_ptr<Account>;