cmake_minimum_required(VERSION 3.1)
project(ATM)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(atm
        src/atm.cpp
        src/menu.cpp
        src/main.cpp
        src/account.cpp
        src/menu_option.cpp)

target_include_directories(atm
        PRIVATE
        include)