#pragma once

#include <memory>

class InputDevice {
public:
    InputDevice() = default;
    virtual ~InputDevice() = default;

    InputDevice(const InputDevice& other) = delete;
    InputDevice& operator=(const InputDevice& other) = delete;

    virtual int get_number() = 0;
    virtual int input_id() = 0;
    virtual std::string input_password() = 0;
    virtual int input_number_with_range(int min_value, int max_value) = 0;
};
using InputDeviceUPtr = std::unique_ptr<InputDevice>;
