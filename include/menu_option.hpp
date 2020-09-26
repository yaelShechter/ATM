#pragma once

#include <string>
#include <iostream>
#include <functional>

class MenuOption
{
public:
    MenuOption(std::string description, std::function<void()> handler);
    ~MenuOption() = default;

    MenuOption(const MenuOption& other) = default;
    MenuOption& operator=(const MenuOption& other) = default;

    void handle() const;
    std::string description() const;

private:
    std::string _description;
    std::function<void()> _handler;
};