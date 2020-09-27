#include <iostream>
#include <stdexcept>

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
        return 1;
    }
    catch (...)
    {
        std::cout << "Unknown exception." << std::endl;
        return 2;
    }
    return 0;
}
