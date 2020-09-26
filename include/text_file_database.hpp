#pragma once

#include <vector>
#include <fstream>

#include "user.hpp"
#include "database.hpp"

class TextFileDatabase : public Database
{
public:
    TextFileDatabase(std::string file_path);

    UserUPtr get_user(int id, std::string password) override;
    void update_user(const UserUPtr &user) override;

private:

private:
    std::string _file_path;
};


