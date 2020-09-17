#include <iostream>
#include <string>
#include "../include/account.hpp"

static const std::string MENU_OPTIONS = "To check balance please press 1\n"
                                        "To withdraw cash from your account please press 2\n"
                                        "To deposit cash into your account please press 3\n"
                                        "To exit please press -1";

void show_menu_options()
{
    std::cout << MENU_OPTIONS << std::endl;
}

void show_balance(Account account)
{
    std::cout << "Your balance is: " << account.get_balance() << std::endl;
}

int amount_to_modify()
{
    int amount_of_cash;
    std::cout << "Please enter the amount you would like to modify: " << std::endl;
    std::cin >> amount_of_cash;
    return amount_of_cash;
}

enum action_choice
{
    QUIT = -1,
    GET_BALANCE = 1,
    WITHDRAW = 2,
    DEPOSIT = 3
};

void choose_from_menu(Account account) {
    int choice;
    show_menu_options();
    std::cin >> choice;
    do
    {
        switch (choice)
        {
            case GET_BALANCE:
                show_balance(account);
                break;
            case WITHDRAW:
            {
                int amount_of_cash = amount_to_modify();
                account.modify_balance(-amount_of_cash);
                show_balance(account);
                break;
            }
            case DEPOSIT:
                int amount_of_cash = amount_to_modify();
                account.modify_balance(amount_of_cash);
                show_balance(account);
                break;
        }
        show_menu_options();
        std::cin >> choice;
    } while (QUIT != choice);
}

int main()
{
    Account account;
    choose_from_menu(account);

    return 0;
}
