#pragma once

#include <iostream>
#include <functional>

class MenuOption
{
public:
    MenuOption(std::string description, std::function<void()> handler);

    void handle() const;
    std::string description() const;

private:
    std::string _description;
    std::function<void()> _handler;
};