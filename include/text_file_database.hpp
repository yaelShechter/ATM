#pragma once

#include <vector>

#include "user.hpp"
#include "database.hpp"

class TextFileDatabase : public Database
{
public:
    explicit TextFileDatabase(std::string file_path);
    ~TextFileDatabase() override = default;

    TextFileDatabase(const TextFileDatabase& other) = delete;
    TextFileDatabase& operator=(const TextFileDatabase& other) = delete;

    UserUPtr get_user(int id, std::string password) override;
    void update_user(const UserUPtr &user) override;

private:
    std::vector<UserUPtr> _copy_users_into_vector();
    void _update_user_in_vector(const std::vector<UserUPtr>& users, const UserUPtr& user);
    void _copy_users_vector_to_file(const std::vector<UserUPtr>& users);

private:
    std::string _file_path;
};