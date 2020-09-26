#include <fstream>

#include "text_file_database.hpp"

TextFileDatabase::TextFileDatabase(std::string file_path):
    _file_path(std::move(file_path))
{}

UserUPtr TextFileDatabase::get_user(int id, std::string password)
{
    int user_id;
    std::string user_password;
    int user_balance;

    std::ifstream users_list_text_file (_file_path);

    while(users_list_text_file >> user_id >> user_password >> user_balance)
    {
        if(id == user_id && password == user_password)
        {
            return std::make_unique<User>(id, password, std::make_unique<Account>(user_balance));
        }
    }
    throw std::runtime_error("Id or password are incorrect.");
}

void TextFileDatabase::update_user(const UserUPtr& user)
{

}


