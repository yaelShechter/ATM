cmake_minimum_required(VERSION 3.2)
project(ATM)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(atm
        src/atm.cpp
        src/menu.cpp
        src/main.cpp
        src/account.cpp
        src/menu_option.cpp
        src/user.cpp
        src/text_file_database.cpp
        src/input_device_cin.cpp include/output_device.hpp src/output_device_cout.cpp include/output_device_cout.hpp)

target_include_directories(atm
        PRIVATE
        include)