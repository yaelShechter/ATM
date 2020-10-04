#pragma once

#include <memory>

#include "menu.hpp"

class OutputDevice
{
public:
    OutputDevice() = default;
    virtual ~OutputDevice() = default;

    OutputDevice(const OutputDevice& other) = delete;
    OutputDevice& operator=(const OutputDevice& other) = delete;

    virtual void prompt_message(std::string message) = 0;
    virtual void print_menu(Menu menu) = 0;

};
using OutputDeviceUPtr = std::unique_ptr<OutputDevice>;