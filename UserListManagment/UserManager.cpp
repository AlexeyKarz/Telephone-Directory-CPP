//
// Created by Karzanov Alexey on 26.04.2024.
//

#include "UserManager.h"
#include <regex>

bool addSubscriber(LinkedList<User> &users) {

    // ask for the name and surname
    string name, surname;
    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the surname: ";
    getline(cin, surname);

    // check whether the input is valid (contains only allowed characters, excluding commas)
    regex validString("^[a-zA-Z0-9 '-]+$"); // allowed characters: a-z, A-Z, 0-9, space, hyphen, apostrophe
    if (!regex_match(name, validString) || !regex_match(surname, validString)) {
        cout << "Invalid name or surname!" << endl;
        cout << "Allowed characters: a-z, A-Z, 0-9, space, hyphen, apostrophe" << endl;
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
