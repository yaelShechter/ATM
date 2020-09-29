#pragma once

#include "menu.hpp"
#include "output_device.hpp"

class OutputDeviceCout : public OutputDevice
{
public:
    OutputDeviceCout() = default;
    ~OutputDeviceCout() override = default;

    OutputDeviceCout(const OutputDeviceCout& other) = delete;
    OutputDeviceCout& operator=(const OutputDeviceCout& other) = delete;

    void request_for_cash_amount() override;
    void request_for_number() override;
    void display_balance(int) override;
    void request_for_id() override;
    void request_for_password() override;
    void request_for_repeated_password() override;
    void unmatched_passwords() override;
    void print_menu(Menu) override;

private:
    static const inline std::string KEY_SEPARATOR = ") ";
};
