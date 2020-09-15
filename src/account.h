//
// Created by yaels on 15-Sep-20.
//

#ifndef ATM_ACCOUNT_H
#define ATM_ACCOUNT_H

class account
{
public:
    account();
    int checkBalance() const;
    void cashWithdrawal(int sum);
    void cashDeposit(int sum);

private:
    int balance;

};


#endif //ATM_ACCOUNT_H
