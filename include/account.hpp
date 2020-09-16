//
// Created by yaels on 15-Sep-20.
//

#ifndef ATM_ACCOUNT_HPP
#define ATM_ACCOUNT_HPP

class Account
{
public:
    Account();
    int get_balance() const;
    void withdraw_cash(int amount);
    void deposit_cash(int amount);

private:
    int _balance;
};

#endif //ATM_ACCOUNT_HPP
