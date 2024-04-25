

#include <iostream>
#include "User/User.h"
#include "LinkedList/LinkedList.h"
#include <fstream>
#include <sstream>

using namespace std;

void writeToFile(const LinkedList<User> &users, const string &filename);
void readFromFile(LinkedList<User> &users, const string &filename);
void printMenu();


int main() {

    // create a list of users
    LinkedList<User> users;

    // read from file users data and add it to the list
    string filename = "../teldir.txt";
    readFromFile(users, filename);

//     add a sample user
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
                break;
            }
            case 2: {
                // remove the phone from a subscriber
                break;
            }
            case 3: {
                // add a phone to a subscriber
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
                writeToFile(users, filename);
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
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


void writeToFile(const LinkedList<User> &users, const string &filename) {

    ofstream file(filename);

    Node<User> *current = users.get_head();
    while (current != nullptr) {
        file << current->entry.get_name() << "," << current->entry.get_surname();
        vector<string> phones = current->entry.get_phones();

        for (int i = 0; i < phones.size(); i++) {
            file << "," << phones[i];
        }
        file << "\n";
        current = current->next;
    }
    file.close();
}


void readFromFile(LinkedList<User> &users, const string &filename) {

    ifstream file(filename);
    // if the file does not exist, create it
    if (!file) {
        ofstream newFile(filename);
        newFile.close();
        return;
    }

    string line;
    while (getline(file, line)) {
        string name, surname, phone;
        vector<string> phones;
        stringstream ss(line);

        getline(ss, name, ',');    // read name
        getline(ss, surname, ','); // read surname

        // read all phone numbers
        while (getline(ss, phone, ',')) {
            phones.push_back(phone);
        }

        User user(name, surname);
        for (int i = 0; i < phones.size(); i++) {
            user.add_phone_number(phones[i]);
        }
        users.insert(user);

    }
}





