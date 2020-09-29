#pragma once

#include <stdexcept>

class LoginError : public std::runtime_error
{
public:
    explicit LoginError(const std::string& error_message):
        std::runtime_error(error_message)
    {}
};
