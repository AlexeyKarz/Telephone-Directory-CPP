//
// Created by Karzanov Alexey on 25.04.2024.
//

#include "User.h"


//User();
//User(string name, string phone);
//string get_name() const;
//string get_surname() const;
//void add_phone_number(string phone);
//void print_phone_numbers() const;
//void print() const;


User::User()
{
    name = "";
    surname = "";
}

User::User(string const name, string const surname, string const phone)
{
    this->name = name;
    this->surname = surname;
    this->surname = "";
    phones.push_back(phone);
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