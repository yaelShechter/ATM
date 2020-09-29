#pragma once

#include <map>
#include <memory>

class OutputDevice
{
public:
    OutputDevice() = default;
    virtual ~OutputDevice() = default;

    OutputDevice(const OutputDevice& other) = delete;
    OutputDevice& operator=(const OutputDevice& other) = delete;

    virtual void request_for_cash_amount() = 0;
    virtual void display_balance(int) = 0;
    virtual void request_for_id() = 0;
    virtual void request_for_password() = 0;
    virtual void request_for_repeated_password() = 0;
    virtual void unmatched_passwords() = 0;
    virtual void print_menu(Menu) = 0;

};
using OutputDeviceUPtr = std::unique_ptr<OutputDevice>;