//
// Created by Karzanov Alexey on 17.05.2024.
//

#include "gtest/gtest.h"
#include "../User/User.h"
#include "../FileIO/FileManager.h"
#include "../UserListManagement/UserManager.h"
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

// Test the writeToFile and readFromFile functions
TEST(FileManagement, writeAndReadToFile) {
    // create a list of users
    LinkedList<User> users;
    // add a sample user for testing
    User user("John", "Smith");
    user.add_phone_number("123456789");
    users.insert(user);
    // write to file
    FileManager::writeToFile(users, "testfile.txt");

    // read from file
    FileManager::readFromFile(users, "testfile.txt");
    Node<User> *current = users.get_head();
    vector<string> phones = current->entry.get_phones();
    // check the data
    ASSERT_EQ("John", current->entry.get_name());
    ASSERT_EQ("Smith", current->entry.get_surname());
    ASSERT_EQ("123456789", phones[0]);
}

// Test the add_phone_number function
TEST(User, addPhoneNumber) {
    User user("John", "Smith");
    user.add_phone_number("123456789");
    user.add_phone_number("987654321");
    vector<string> phones = user.get_phones();
    ASSERT_EQ("123456789", phones[0]);
    ASSERT_EQ("987654321", phones[1]);
}

// Test the delete_phone_number function
TEST(User, deletePhoneNumber) {
    User user("John", "Smith");
    user.add_phone_number("123456789");
    user.add_phone_number("987654321");
    user.delete_phone_number("123456789");
    vector<string> phones = user.get_phones();
    ASSERT_EQ("987654321", phones[0]);
}

// Test the findSubscriber function
TEST(UserManager, findSubscriber) {
    LinkedList<User> users;
    User user("John", "Smith");
    user.add_phone_number("123456789");
    users.insert(user);
    Node<User> *current;
    current = users.get_head();
    Node<User> *found;
    found = users.find_by_key(current->entry);
    ASSERT_TRUE(found != nullptr);
}
