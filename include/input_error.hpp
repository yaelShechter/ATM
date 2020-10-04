#pragma once

#include <stdexcept>

class InputError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

