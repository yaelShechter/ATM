#include <iostream>
#include "account.h"
#include <string>
using namespace std;

int main() {
    account acc;
    acc.cashDeposit(100);
    int choice;
    int sum;
    string welcomeMessage = "To check balance please press 1\n"
                            "To withdraw money out of your account please press 2\n"
                            "To deposit money in your account please press 3\n"
                            "To exit please press -1";
    cout << "Hi there!\n" << welcomeMessage << endl;

    cin >> choice;

    while(choice != -1) {
        switch (choice) {
            case 1:
                cout << "Your balance is:" << acc.checkBalance() << endl;
                break;
            case 2:
                cout << "Please enter the sum you would like to withdraw: " << endl;
                cin >> sum;
                acc.cashWithdrawal(sum);
                cout << "New balance:" << acc.checkBalance() << endl;
                break;
            case 3:
                cout << "Please enter the sum you would like to deposit: " << endl; //duplicated code, needs fixing
                cin >> sum;
                acc.cashDeposit(sum);
                cout << "New balance:" << acc.checkBalance() << endl;
                break;
        }
        cout << welcomeMessage << endl;
        cin >> choice;
    }
    return 0;
}
