#include <iostream>
#include <string>
#include "../include/account.hpp"

static const std::string welcome_message = "To check balance please press 1\n"
                             "To withdraw money out of your account please press 2\n"
                             "To deposit money into your account please press 3\n"
                             "To exit please press -1";
void show_first_welcome_message()
{
    std::cout << "Hi there!\n" << welcome_message << std::endl;

}

void show_welcome_message()
{
    std::cout << welcome_message << std::endl;

}

void show_balance(Account acc, std::string new_or_old)
{
    std::cout << new_or_old << ": " << acc.get_balance() << std::endl;

}

int amount_to_withdraw_or_deposit(std::string withdraw_or_deposit)
{
    int amount;
    std::cout << "Please enter the amount you would like to " << withdraw_or_deposit << ": "  << std::endl;
    std::cin >> amount;
    return amount;
}

enum action_choice {quit = -1, get_balance = 1, withdraw = 2, deposit = 3};

int initialize_choice()
{
    int choice;
    show_first_welcome_message();
    std::cin >> choice;
    return choice;
}

void choose_from_menu(int choice, Account acc) {
    while (choice != quit) {
        int amount;
        switch (choice) {
            case get_balance:
                show_balance(acc, "Your balance is");
                break;
            case withdraw:
                amount = amount_to_withdraw_or_deposit("withdraw");
                acc.withdraw_cash(amount);
                show_balance(acc, "New balance");
                break;
            case deposit:
                amount = amount_to_withdraw_or_deposit("deposit");
                acc.deposit_cash(amount);
                show_balance(acc, "New balance");
                break;
        }
        show_welcome_message();
        std::cin >> choice;
    }
}

int main() {
    int choice = initialize_choice();
    Account acc;

    choose_from_menu(choice, acc);

    return 0;
}
