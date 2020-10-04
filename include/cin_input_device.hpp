#pragma once

#include "input_device.hpp"

class CinInputDevice : public InputDevice
{
public:
    using InputDevice::InputDevice;

    CinInputDevice(const CinInputDevice& other) = delete;
    CinInputDevice& operator=(const CinInputDevice& other) = delete;

    int input_id() override;
    int input_number() override;
    int input_number_with_range(int min_value, int max_value) override;
    std::string input_password() override;
    void _reset_cin();
};
