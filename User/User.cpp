/** \file User.cpp
 * \brief Implementation of the User class.
 * Contains the implementation of the User class.
 * \author Aleksei Karzanov
 * \version 1.0
 * \date 26.04.2024
 * \since 1.0
 */

#include "User.h"

// Constructor
User::User()
{
    name = "";
    surname = "";
}

// Constructor with parameters
User::User(string const& name, string const& surname)
{
    this->name = name;
    this->surname = surname;
}

/** Method <code>get_name</code> gets the name of the user
 * @param name the name of the user
 */
string User::get_name() const
{
    return name;
}

/** Method <code>get_surname</code> gets the surname of the user
 * @param surname the surname of the user
 */
string User::get_surname() const
{
    return surname;
}

/** Method add_phone_number adds a new phone number to the list of phone numbers
 * @param phone the phone number to be added
 */
void User::add_phone_number(string const& phone)
{
    phones.push_back(phone);
}

/** Method <code>delete_phone_number</code> deletes a phone number from the list of phone numbers
 * @param phone the phone number to be deleted
 * @return true if the phone number was deleted successfully, false otherwise
 */
bool User::delete_phone_number(string const& phone) {
    for (int i = 0; i < phones.size(); i++) {
        if (phones[i] == phone) {
            phones.erase(phones.begin() + i);
            return true;
        }
    }
    return false;
}

/** Method <code>get_phones</code> gets the list of phone numbers
 * @return the list of phone numbers (vector of strings)
 */
vector<string> User::get_phones() const
{
    return phones;
}

/** Method <code>print_phone_numbers</code> prints the list of phone numbers
 */
void User::print_phone_numbers() const
{
    for (int i = 0; i < phones.size(); i++)
    {
        cout << phones[i] << endl;
    }
}

/** Method <code>print</code> prints the user's name, surname and phone numbers
 */
void User::print() const
{
    cout << name << " " << surname << endl;
}

/** Operator < compares two users by their surnames and names
 * @param otherUser the user to compare with
 * @return true if the user is less than the other user, false otherwise
 */
bool User::operator < (const User &otherUser) const {
    if (surname < otherUser.surname) {
        return true;
    } else if (surname == otherUser.surname) {
        return name < otherUser.name;
    }
    return false;
}

/** Operator == compares two users by their surnames and names
 * @param otherUser the user to compare with
 * @return true if the users are equal, false otherwise
 */
bool User::operator == (const User &otherUser) const {
    return name == otherUser.name && surname == otherUser.surname;
}