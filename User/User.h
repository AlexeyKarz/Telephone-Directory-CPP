//
// Created by Karzanov Alexey on 25.04.2024.
//

#ifndef TELDIRECTORY_USER_H
#define TELDIRECTORY_USER_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;


class User {
public:
    User();
    User(string const name, string const surname, string const phone);
    string get_name() const;
    string get_surname() const;
    void add_phone_number(string phone);
    void print_phone_numbers() const;
    void print() const;
private:
    string name;
    string surname;
    vector<string> phones;
};


#endif //TELDIRECTORY_USER_H
