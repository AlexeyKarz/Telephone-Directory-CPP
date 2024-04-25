//
// Created by Karzanov Alexey on 25.04.2024.
//

#include "User.h"


User::User()
{
    name = "";
    surname = "";
}

User::User(string const name, string const surname)
{
    this->name = name;
    this->surname = surname;
}

string User::get_name() const
{
    return name;
}

string User::get_surname() const
{
    return surname;
}

void User::add_phone_number(string phone)
{
    phones.push_back(phone);
}

vector<string> User::get_phones() const
{
    return phones;
}

void User::print_phone_numbers() const
{
    for (int i = 0; i < phones.size(); i++)
    {
        cout << phones[i] << endl;
    }
}

void User::print() const
{
    cout << name << " " << surname << endl;
    cout << "Phone numbers:" << endl;
    print_phone_numbers();
}

bool User::operator < (const User &otherUser) const {
    if (surname < otherUser.surname) {
        return true;
    } else if (surname == otherUser.surname) {
        return name < otherUser.name;
    }
    return false;
}