#include <memory>
#include <fstream>
#include <string>

#include "login_error.hpp"
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
            users_list_text_file.close();
            return std::make_unique<User>(id, password, std::make_unique<Account>(user_balance));
        }
    }
    throw LoginError("user not found.");
}

void TextFileDatabase::update_user(const UserUPtr& user)
{
    std::vector<UserUPtr> users = _copy_users_into_vector();;
    _update_user_in_vector(users, user);
    _clear_path_file();
    _copy_users_vector_to_file(users);
}

std::vector<UserUPtr> TextFileDatabase::_copy_users_into_vector()
{
    int user_id;
    std::string user_password;
    int user_balance;
    std::vector<UserUPtr> users;
    std::ifstream users_list(_file_path);
    while(users_list >> user_id >> user_password >> user_balance)
    {
        users.push_back(std::make_unique<User>(user_id, user_password, std::make_shared<Account>(user_balance)));
    }
    users_list.close();
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

void TextFileDatabase::_clear_path_file()
{
    std::ofstream file;
    file.open(_file_path, std::ofstream::out | std::ofstream::trunc);
    file.close();
}

void TextFileDatabase::_copy_users_vector_to_file(const std::vector<UserUPtr>& users)
{
    std::ofstream new_users_list_text_file (_file_path);
    for (const auto &user : users)
    {
        new_users_list_text_file << _parse_user_into_string(user) << std::endl;
    }
    new_users_list_text_file.close();
}

std::string TextFileDatabase::_parse_user_into_string(const UserUPtr& user)
{
    std::string line;
    line = std::to_string(user->id()) + " " + user->password() + " " + std::to_string(user->account()->balance());
    return line;
}