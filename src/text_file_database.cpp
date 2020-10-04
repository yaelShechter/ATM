#include <memory>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "db_error.hpp"
#include "text_file_database.hpp"

TextFileDatabase::TextFileDatabase(std::string file_path):
    _file_path(std::move(file_path))
{}

UserUPtr TextFileDatabase::get_user(int id, std::string password)
{
    std::vector<UserUPtr> users = _get_user_list_from_file();
    auto user_iterator = std::find_if(
            users.begin(),
            users.end(),
            [id, password] (const UserUPtr& user)
            {
                return user->id() == id and user->password() == password;
            });

    if(user_iterator == users.end())
    {
        throw DBError("TextFileDatabase:get_user: User was not found.");
    }
    return std::move(*user_iterator);
}

void TextFileDatabase::update_user(const UserUPtr& user)
{
    std::vector<UserUPtr> users = _get_user_list_from_file();
    _update_user_in_vector(users, user);
    _copy_users_vector_to_file(users);
}

UserUPtr TextFileDatabase::_parse_line_to_user(std::string line)
{
    std::istringstream line_string(line);

    int user_id;
    int user_balance;
    std::string user_password;

    if(!(line_string >> user_id >> user_password >> user_balance))
    {
        throw DBError("TextFileDatabase:_parse_line_to_user: Database needs fixing."); //DBerror;
    }
    return std::make_unique<User>(user_id, user_password, std::make_shared<Account>(user_balance));
}

std::vector<UserUPtr> TextFileDatabase::_get_user_list_from_file()
{
    std::string line;
    std::ifstream users_list_text_file(_file_path);
    std::vector<UserUPtr> users;
    while(std::getline(users_list_text_file, line))
    {
        users.push_back(_parse_line_to_user(line));
    }
    return users;
}

void TextFileDatabase::_update_user_in_vector(const std::vector<UserUPtr>& users, const UserUPtr& user)
{
    for(const auto& user_in_users : users)
    {
        if(user->id() == user_in_users->id())
        {
            user_in_users->set_password(user->password());
            user_in_users->account()->set_balance(user->account()->balance());
        }
    }
}

void TextFileDatabase::_copy_users_vector_to_file(const std::vector<UserUPtr>& users)
{
    std::ofstream new_users_list_text_file(_file_path, std::fstream::trunc);
    for (const auto &user : users)
    {
        new_users_list_text_file << user << std::endl;
    }
}