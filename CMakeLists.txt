cmake_minimum_required(VERSION 3.1)
project(ATM)

set(CMAKE_CXX_STANDARD 17)

add_executable(atm src/main.cpp src/account.cpp src/menu.cpp src/menu_option.cpp src/atm.cpp)

target_include_directories(atm PRIVATE include)