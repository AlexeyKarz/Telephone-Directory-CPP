/** \file FileManager.h
 *  \author Aleksei Karzanov
 *  \created 26.04.2024
 *  \version 1.0
 *  \since 1.0
 */

#include "FileManager.h"
#include <fstream>
#include <sstream>

/** Writes the data from the list to the file
 * @param users - list of users
 * @param filename - name of the file
 */
void FileManager::writeToFile(const LinkedList<User> &users, const string &filename) {

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

/** Reads the data from the file and inserts it into the list
 * @param users - list of users
 * @param filename - name of the file
 */
void FileManager::readFromFile(LinkedList<User> &users, const string &filename) {

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
