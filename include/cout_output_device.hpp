#pragma once

#include "menu.hpp"
#include "output_device.hpp"

class CoutOutputDevice: public OutputDevice
{
private:
    static const inline std::string KEY_SEPARATOR = ") ";

public:
    using OutputDevice::OutputDevice;

    CoutOutputDevice(const CoutOutputDevice& other) = delete;
    CoutOutputDevice& operator=(const CoutOutputDevice& other) = delete;

    void prompt_message(std::string message) override;
    void print_menu(Menu menu) override;
};
