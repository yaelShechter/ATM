//
// Created by yaels on 17-Sep-20.
//
#pragma once

#include <functional>
#include <iostream>

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