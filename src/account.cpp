//
// Created by yaels on 15-Sep-20.
//

#include "account.h"
#include <iostream>

using namespace std;

account::account() {
    balance = 0;
};

int account::checkBalance() const{
    return balance;
};

void account::cashWithdrawal(int sum){
    if (sum > balance)
        cout << "Sorry, you cannot withdraw more money then you have in you account :(" << endl;
    else
        balance -= sum;
};

void account::cashDeposit(int sum){
    balance += sum;
};