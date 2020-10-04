#include <iostream>

#include "error.hpp"
#include "atm.hpp"

int main()
{
    try
    {
        ATM atm;
        atm.run();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return static_cast<int>(ERROR::RUNTIME_ERROR);
    }
    catch (...)
    {
        std::cout << "Unknown exception." << std::endl;
        return static_cast<int>(ERROR::UNKNOWN_ERROR);
    }
    return 0;
}
