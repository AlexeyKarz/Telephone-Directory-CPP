//
// Created by Karzanov Alexey on 26.04.2024.
//

#ifndef TELDIRECTORY_USERMANAGER_H
#define TELDIRECTORY_USERMANAGER_H

#include "../LinkedList/LinkedList.h"
#include "../User/User.h"

bool validString(const string &str);
bool addSubscriber(LinkedList<User> &users);
bool deleteSubscriber(LinkedList<User> &users);
bool addPhoneNumber(LinkedList<User> &users);
bool deletePhoneNumber(LinkedList<User> &users);



#endif //TELDIRECTORY_USERMANAGER_H
