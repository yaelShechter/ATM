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
    void modify_balance(int amount_of_money);

private:
    int _balance;
};

#endif //ATM_ACCOUNT_HPP
