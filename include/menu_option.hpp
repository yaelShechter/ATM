#pragma once

#include <memory>
#include <string>
#include <functional>

class MenuOption
{
public:
    MenuOption(std::string description, std::function<void()> handler);
    virtual ~MenuOption() = default;

    MenuOption(const MenuOption& other) = delete;
    MenuOption& operator=(const MenuOption& other) = delete;

    void handle() const;
    std::string description() const;

private:
    std::string _description;
    std::function<void()> _handler;
};
using MenuOptionPtr = std::shared_ptr<MenuOption>;