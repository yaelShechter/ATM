#pragma once

#include "input_error.hpp"

class PasswordInputError : public InputError
{
public:
    using InputError::InputError;
};