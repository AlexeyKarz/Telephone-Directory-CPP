/** \file UserManager.cpp
 * \brief Implementation of the functions for managing the user list.
 * Contains the implementation of the functions for managing the user list.
 * \author Karzanov Alexey
 * \version 1.0
 * \date 26.04.2024
 */

#include "UserManager.h"
#include <regex>

/** Function <code>validString</code> checks whether the string contains only allowed characters.
 * <BR>
 * @param str the string to be checked
 * @return true if the string contains only allowed characters, false otherwise
 */
bool validString(string const &str) {
    // allowed characters: a-z, A-Z, 0-9, space, hyphen, apostrophe
    regex validString("^[a-zA-Z0-9 '-]+$");
    return regex_match(str, validString);
}

/** Function <code>addSubscriber</code> adds a new subscriber to the list.
 * <BR>
 * @param users the list of users
 * @return true if the subscriber was added successfully, false otherwise
 */
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

    // check whether the user already exists
    Node<User> *found = users.find_by_key(user);
    if (found != nullptr) {
        cout << "The user already exists. Do you want to add a phone number? (y/n) ";
        char choice;
        cin >> choice;
        cin.ignore(); // to ignore the newline character
        if (choice == 'n' || choice == 'N') {
            return false;
        }
        else if (choice != 'y' && choice != 'Y') {
            cout << "Invalid input." << endl;
            return false;
        }
        else {
            // add the phone number
            string phone;
            cout << "Enter the phone number: ";
            getline(cin, phone);
            found->entry.add_phone_number(phone);
            cout << "The phone number was added successfully." << endl;
            return false; // the user was not added
        }
    }

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

/** Function <code>findSubscriber</code> finds a subscriber in the list.
 * <BR>
 * @param users the list of users
 * @param found the found user
 * @return true if the subscriber was found, false otherwise
 */
bool findSubscriber(LinkedList<User> &users, Node<User> *&found) {

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

        // create a user
        User user(name, surname);

        // find the user in the list
        found = users.find_by_key(user);
        if (found == nullptr) {
            cout << "The user was not found. Please, check Name and Surname and try again." << endl;
            return false;
        }

        return true;

}

/** Function <code>addPhoneNumber</code> adds a phone number to the subscriber.
 * <BR>
 * @param users the list of users
 * @return true if the phone number was added successfully, false otherwise
 */
bool addPhoneNumber(LinkedList<User> &users) {

    Node<User> *current;
    // find the subscriber
    if (!findSubscriber(users, current)) {
        return false; // the user was not found
    }

    // ask for the phone number
    string phone;
    cout << "Enter the phone number: ";
    getline(cin, phone);

    // add the phone number
    current->entry.add_phone_number(phone);
    return true;

}

/** Function <code>deletePhoneNumber</code> deletes a phone number from the subscriber.
 * <BR>
 * @param users the list of users
 * @return true if the phone number was deleted successfully, false otherwise
 */
bool deletePhoneNumber(LinkedList<User> &users) {

    Node<User> *current;
    // find the subscriber
    if (!findSubscriber(users, current)) {
        return false; // the user was not found
    }

    // ask for the phone number
    string phone;
    cout << "Enter the phone number: ";
    getline(cin, phone);

    // delete the phone number
    if (!current->entry.delete_phone_number(phone)) {
        cout << "The phone number was not found." << endl;
        return false;
    }
    return true;
}

/** Function <code>deleteSubscriber</code> deletes a subscriber from the list.
 * <BR>
 * @param users the list of users
 * @return true if the subscriber was deleted successfully, false otherwise
 */
bool deleteSubscriber(LinkedList<User> &users) {

    Node<User> *current;
    // find the subscriber
    if (!findSubscriber(users, current)) {
        return false; // the user was not found
    }

    // delete the subscriber
    users.remove(current->entry);
    return true;
}

/** Function <code>displayPhoneNumbers</code> displays the phone numbers of the subscriber.
 * <BR>
 * @param users the list of users
 */
void displayPhoneNumbers(LinkedList<User> &users) {

        Node<User> *current;
        // find the subscriber
        if (!findSubscriber(users, current)) {
            return; // the user was not found
        }

        // display the phone numbers
        cout << "Phone Numbers:" << endl;
        current->entry.print_phone_numbers();
}