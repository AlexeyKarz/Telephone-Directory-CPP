/** \file UserManager.h
 *  \author Aleksei Karzanov
 *  \created 26.04.2024
 *  \version 1.0
 *  \since 1.0
 */

#ifndef TELDIRECTORY_USERMANAGER_H
#define TELDIRECTORY_USERMANAGER_H

#include "../LinkedList/LinkedList.h"
#include "../User/User.h"

// Function prototypes
bool validString(const string &str);
bool addSubscriber(LinkedList<User> &users);
bool findSubscriber(LinkedList<User> &users, Node<User> *&found);
bool deleteSubscriber(LinkedList<User> &users);
bool addPhoneNumber(LinkedList<User> &users);
bool deletePhoneNumber(LinkedList<User> &users);
void displayPhoneNumbers(LinkedList<User> &users);

#endif //TELDIRECTORY_USERMANAGER_H
