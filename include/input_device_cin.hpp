#pragma once

#include <memory>

#include "input_device.hpp"

class InputDeviceCin : public InputDevice
{
public:
    InputDeviceCin();
    ~InputDeviceCin() override = default;

    InputDeviceCin(const InputDeviceCin& other) = delete;
    InputDeviceCin& operator=(const InputDeviceCin& other) = delete;

    int input_id() override;
    int get_number() override;
    int input_number_with_range(int min_value, int max_value) override;
    std::string input_password() override;
};
