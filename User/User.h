/** \file User.h
 *  \brief Declaration of the User class.
 *  \author Aleksei Karzanov
 *  \version 1.0
 *  \date 26.04.2024
 *  \since 1.0
 */

#ifndef TELDIRECTORY_USER_H
#define TELDIRECTORY_USER_H

#include <string>
#include <iostream>
#include <vector>


using namespace std;

/** User class represents a user with a name, surname and a list of phone numbers
 * @author Aleksei Karzanov
 * @created 26.04.2024
 * @version 1.0
 * @since 1.0
 */
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
