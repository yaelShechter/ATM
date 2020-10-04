#pragma once

#include <memory>

class Account
{
public:
    explicit Account(int balance);
    ~Account() = default;

    Account(const Account& other) = delete;
    Account& operator=(const Account& other) = delete;

    int balance() const;
    void set_balance(int new_balance);

private:
    int _balance;
};

using AccountPtr = std::shared_ptr<Account>;