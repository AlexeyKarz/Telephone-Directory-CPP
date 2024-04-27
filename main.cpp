/**
 * \file main.cpp
 * \brief Main file for the telephone directory program.
 * This file contains the main function for the telephone directory program.
 * \details The program allows to add, delete, display subscribers and their phone numbers.
 * The data is stored in a linked list and is read from and written to a file.
 * \author Karzanov Alexey
 * \version 1.0
 * \date 26.04.2024
 * \copyright University of Nicosia.
 * The program is for educational purposes only.
 */

#include <iostream>
#include "User/User.h"
#include "LinkedList/LinkedList.h"
#include "FileIO/FileManager.h"
#include "UserListManagement/UserManager.h"

using namespace std;

// function prototypes
void printMenu();

/** Main function. Entry point of the program
 * @return 0 if the program exits successfully
 */
int main() {

    // create a list of users
    LinkedList<User> users;

    // read from file users data and add it to the list
    string filename = "../teldir.txt";
    FileManager::readFromFile(users, filename); // read from file by calling the static method

//    add a sample user for testing
//    uncomment the following lines to add a sample user
//    User user("John", "Doe");
//    user.add_phone_number("123456789");
//    user.add_phone_number("987654321");
//    users.insert(user);

    cout << "Welcome to the telephone directory!" << endl;
    int choice;

    do {
        printMenu();
        cin >> choice;
        cin.ignore(); // to ignore the newline character

        // process the choice
        switch (choice) {
            case 1: {
                // add a new subscriber
                if(addSubscriber(users)) {
                    cout << "The subscriber was added successfully." << endl;
                }
                else {
                    cout << "The subscriber was not added." << endl;
                }
                break;
            }
            case 2: {
                // remove the phone from a subscriber
                if (deletePhoneNumber(users)) {
                    cout << "The phone number was removed successfully." << endl;
                }
                else {
                    cout << "The phone number was not removed." << endl;
                }
                break;
            }
            case 3: {
                // add a phone to a subscriber
                if (addPhoneNumber(users)) {
                    cout << "The phone number was added successfully." << endl;
                }
                else {
                    cout << "The phone number was not added." << endl;
                }
                break;
            }
            case 4: {
                // display a subscriber's phone numbers
                displayPhoneNumbers(users);
                break;
            }
            case 5: {
                // delete a subscriber
                if (deleteSubscriber(users)) {
                    cout << "The subscriber was deleted successfully." << endl;
                }
                else {
                    cout << "The subscriber was not deleted." << endl;
                }
                break;
            }
            case 6: {
                // display the directory
                users.print();
                break;
            }
            case 7: {
                // exit
                FileManager::writeToFile(users, filename);
                break;
            }
            default: {
                // handle invalid choice
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << "Invalid choice!" << endl;
                } else {
                    cout << "Invalid choice!" << endl;
                }
            }
        }
    } while (choice != 7);

    return 0;
}

/**
 * Function <code>printMenu</code> prints the menu of the program
 */
void printMenu() {
    cout << "1. Add a new subscriber" << endl;
    cout << "2. Remove the phone from a subscriber" << endl;
    cout << "3. Add a phone to a subscriber" << endl;
    cout << "4. Display a subscriber's phone numbers" << endl;
    cout << "5. Delete a subscriber" << endl;
    cout << "6. Display the directory" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}
