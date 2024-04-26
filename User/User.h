//
// Created by Karzanov Alexey on 25.04.2024.
//

#ifndef TELDIRECTORY_USER_H
#define TELDIRECTORY_USER_H

#include <string>
#include <iostream>
#include <vector>

/* I have to include LinkedList.cpp and Node.cpp here because
 * they are a template classes, and template is declared here */
//#include "../LinkedList/LinkedList.cpp"
//#include "../LinkedList/Node.cpp"
//#include "../FileIO/FileManager.cpp"
//#include "../UserListManagment/UserManager.cpp"

using namespace std;


class User {
public:
    User();
    User(string const name, string const surname);
    string get_name() const;
    string get_surname() const;
    void add_phone_number(string const phone);
    bool delete_phone_number(string const phone);
    vector<string> get_phones() const;
    void print_phone_numbers() const;
    void print() const;
    // overload < and == operators
    bool operator < (const User &otherUser) const;
    bool operator == (const User &otherUser) const;
private:
    string name;
    string surname;
    vector<string> phones;
};


#endif //TELDIRECTORY_USER_H
