

#include <iostream>
#include "User/User.h"
#include "LinkedList/LinkedList.h"
#include "FileIO/FileManager.h"
#include "UserListManagment/UserManager.h"

using namespace std;

void printMenu();


int main() {

    // create a list of users
    LinkedList<User> users;

    // read from file users data and add it to the list
    string filename = "../teldir.txt";
    FileManager fileManager;
    fileManager.readFromFile(users, filename);

//    add a sample user
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
                addSubscriber(users);
                break;
            }
            case 2: {
                // remove the phone from a subscriber
                break;
            }
            case 3: {
                // add a phone to a subscriber
                addPhoneNumber(users);
                break;
            }
            case 4: {
                // display a subscriber's phone numbers
                // for test display one
                Node<User> *current = users.get_head();
                current->entry.print();
                break;
            }
            case 5: {
                // delete a subscriber
                break;
            }
            case 6: {
                // display the directory
                users.print();
                break;
            }
            case 7: {
                // exit
                fileManager.writeToFile(users, filename);
                break;
            }
            default: {
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
