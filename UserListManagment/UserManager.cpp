//
// Created by Karzanov Alexey on 26.04.2024.
//

#include "UserManager.h"
#include <regex>

bool validString(string const &str) {
    regex validString("^[a-zA-Z0-9 '-]+$"); // allowed characters: a-z, A-Z, 0-9, space, hyphen, apostrophe
    return regex_match(str, validString);
}

bool addSubscriber(LinkedList<User> &users) {

    // ask for the name and surname
    string name, surname;
    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the surname: ";
    getline(cin, surname);

    // check whether the input is valid (contains only allowed characters, excluding commas)
    if (!validString(name) || !validString(surname)) {
        cout << "Invalid input. The name and surname should contain only letters, digits, spaces, hyphens, and apostrophes." << endl;
        return false;
    }

    // create a new user
    User user(name, surname);

    // ask for the phone numbers
    string phone;
    cout << "How many phone numbers do you want to add? ";
    int count;
    cin >> count;
    cin.ignore(); // to ignore the newline character
    for (int i = 0; i < count; i++) {
        cout << "Enter the phone number: ";
        getline(cin, phone);
        user.add_phone_number(phone);
    }

    // add the user to the list
    users.insert(user);
    return true;
}

bool addPhoneNumber(LinkedList<User> &users) {

    // ask for the name and surname
    string name, surname;
    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the surname: ";
    getline(cin, surname);

    // check whether the input is valid (contains only allowed characters, excluding commas)
    if (!validString(name) || !validString(surname)) {
        cout << "Invalid input. The name and surname should contain only letters, digits, spaces, hyphens, and apostrophes." << endl;
        return false;
    }

    // initialize the user
    User user(name, surname);

    // try to find the user in the list
    Node<User> *current = users.find_by_key(user);
    if (current == nullptr) {
        cout << "The user was not found. Please, check Name and Surname and try again" << endl;
        return false;
    }

    // ask for the phone number
    string phone;
    cout << "Enter the phone number: ";
    getline(cin, phone);

    // add the phone number
    current->entry.add_phone_number(phone);
    return true;

}
