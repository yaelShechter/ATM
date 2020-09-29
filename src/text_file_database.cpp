#include <memory>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "login_error.hpp"
#include "text_file_database.hpp"

TextFileDatabase::TextFileDatabase(std::string file_path):
    _file_path(std::move(file_path))
{}

UserUPtr TextFileDatabase::get_user(int id, std::string password)
{
    std::vector<UserUPtr> users = _copy_users_into_vector();
    std::vector<UserUPtr>::iterator user_iterator;
    user_iterator = std::find_if(users.begin(), users.end(), [id, password] (const UserUPtr& user)
        {
            return user->id() == id and user->password() == password;
        });
    if(user_iterator == users.end())
    {
        throw LoginError("User was not found.");
    }
    return std::make_unique<User>(id, password, std::make_unique<Account>((*user_iterator)->account()->balance()));
}

void TextFileDatabase::update_user(const UserUPtr& user)
{
    std::vector<UserUPtr> users = _copy_users_into_vector();;
    _update_user_in_vector(users, user);
    std::ofstream clear_file(_file_path);
    clear_file.close();
    _copy_users_vector_to_file(users);
}

std::vector<UserUPtr> TextFileDatabase::_copy_users_into_vector()
{
    std::string line;
    std::ifstream users_list_text_file(_file_path);
    std::vector<UserUPtr> users;
    while(std::getline(users_list_text_file, line))
    {
        int user_id;
        int user_balance;
        std::string user_password;
        std::istringstream iss(line);
        if(!(iss >> user_id >> user_password >> user_balance))
        {
            throw std::runtime_error("Database needs fixing.");
        }
        users.push_back(std::make_unique<User>(user_id, user_password, std::make_shared<Account>(user_balance)));
    }
    users_list_text_file.close();
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
    std::ofstream new_users_list_text_file(_file_path);
    for (const auto &user : users)
    {
        new_users_list_text_file << user << std::endl;
    }
    new_users_list_text_file.close();
}