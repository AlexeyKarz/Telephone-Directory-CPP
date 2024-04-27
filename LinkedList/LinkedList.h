/** \file LinkedList.h
 *  \brief LinkedList class
 *  This file contains the implementation of the LinkedList class.
 *  \author Aleksei Karzanov
 *  \version 1.0
 *  \date 26.04.2024
 *  \since 1.0
 */

#ifndef TELDIRECTORY_LINKEDLIST_H
#define TELDIRECTORY_LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

// Error codes
enum Error_code {success,overflow,underflow,not_found};

/** LinkedList class
 * This class represents a linked list of nodes
 * @tparam List_entry
 */
template <class List_entry> class LinkedList {
public:
    LinkedList();
    void clear();
    bool empty() const;
    int size() const;
    Node<List_entry>* get_head() const;
    Node<List_entry>* find_by_key(const List_entry &key) const;
    Error_code retrieve(int position, List_entry &x) const;
    Error_code remove(const List_entry &item);
    Error_code insert(const List_entry &item);
    void print() const;
    // Safequards
    ~LinkedList();
    LinkedList(const LinkedList<List_entry> &copy);
    void operator = (const LinkedList<List_entry> &original);
protected:
    Node<List_entry> *head;
};

/* Since LinkedList is a template class, I have to include the implementation in the header file.
 * Otherwise, I will get a linker error
 */

// Constructor
template <class List_entry> LinkedList<List_entry>::LinkedList()
{
    head = nullptr;
}

/** Function Clear()
 *  @details This function deletes all nodes in the list
 */
template <class List_entry> void LinkedList<List_entry>::clear()
{
    Node<List_entry> *temp;

    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

/** Function Empty()
 *  @details This function checks whether the list is empty
 *  @return Returns true if the list is empty, false otherwise
 */
template <class List_entry> bool LinkedList<List_entry>::empty() const
{
    return head == nullptr;
}

/** Function Size()
 *  @details This function returns the number of nodes in the list
 *  @return Returns the number of nodes in the list
 */
template <class List_entry> int LinkedList<List_entry>::size() const
{
    int count = 0;
    Node<List_entry> *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

/** Function Retrieve()
 *  @details This function retrieves the element at the specified position
 *  @param position the position of the element to be retrieved
 *  @param x the element to be retrieved, passed by reference
 *  @return Returns success if the element was retrieved successfully, underflow if the list is empty, not_found if the position is out of range
 */
template <class List_entry> Error_code LinkedList<List_entry>::retrieve(int position, List_entry &x) const
{
    if (empty()) return underflow;
    if (position < 0 || position >= size()) return not_found;
    Node<List_entry> *current = head;
    for (int i = 0; i < position; i++)
    {
        current = current->next;
    }
    x = current->entry;
    return success;
}

/** Function get_head()
 *  @details This function returns the head of the list
 *  @return Returns the head of the list
 */
template <class List_entry> Node<List_entry>* LinkedList<List_entry>::get_head() const {
    return head;
}

/** Function find_by_key()
 *  @details This function finds the node with the specified key (entry)
 *  @param key the key to be found
 *  @return Returns the node with the specified key if it was found, nullptr otherwise
 */
template <class List_entry> Node<List_entry>* LinkedList<List_entry>::find_by_key(const List_entry &key) const {
    Node<List_entry> *current = head;
    // Traverse the list
    while (current != nullptr) {
        if (current->entry == key) { // the operator == must be implemented in the class List_entry
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

/** Function Insert()
 *  @details This function inserts an element into the list
 *  @param item the element to be inserted
 *  @return Returns success if the element was inserted successfully, overflow if the list is full
 */
template <class List_entry> Error_code LinkedList<List_entry>::insert(const List_entry &item)
{
    Node<List_entry> *new_entry = new Node<List_entry>(item);

    if (new_entry == nullptr) return overflow; // If full memory

    else if (empty()) // If the list is empty
        head = new_entry;
    else if (item < head->entry) // If the item is less than the head
    {
        new_entry->next = head;
        head = new_entry;
    }
    else // If the item is greater than the head
    {
        Node<List_entry> *previous = head, *current = head->next;
        // Traverse the list
        while (current != nullptr)
        {
            if (item < current->entry)
            {
                new_entry->next = current;
                break;
            }
            previous = current;
            current = current->next;
        }
        previous->next = new_entry;
    }
    return success;
}

/** Function Remove()
 *  @details This function removes an element from the list
 *  @param item the element to be removed
 *  @return Returns success if the element was removed successfully, underflow if the list is empty, not_found if the element was not found
 */
template <class List_entry> Error_code LinkedList<List_entry>::remove(const List_entry &item)
{
    Node<List_entry> *current = head;
    if (empty()) return underflow;
    if (item < head->entry) return not_found;
    if (item == head->entry) // If the item is the head
    {
        head = head->next;
        delete current;
        return success;
    }
    Node<List_entry> *previous = current;
    current = current->next;
    // Traverse the list
    while (current != nullptr)
    {
        if (item < head->entry) break;
        if (item == current->entry)
        {
            previous->next = current->next;
            delete current;
            return success;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    return not_found;
}

/** Function Print()
 *  @details This function prints the list
 */
template <class List_entry> void LinkedList<List_entry>::print() const
{
    if (empty())
        cout << "Empty List" << endl;
    else {
        Node<List_entry> *temp = head;
        while (temp != NULL) {
            temp->entry.print(); // method print() must be implemented in the class List_entry
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

// ------- Safeguards ----------

/** Destructor
 *  @details This function deletes all nodes in the list
 */
template <class List_entry> LinkedList<List_entry>::~LinkedList()
{
    Node<List_entry> *tmp;


    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

/** Copy constructor
 *  @details This function creates a copy of the list
 */
template <class List_entry> LinkedList<List_entry>::LinkedList(const LinkedList<List_entry> &original)
{
    Node<List_entry> *new_copy, *original_node = original.head;
    if (original_node == NULL) head = NULL;
    else
    {
        head = new_copy = new Node<List_entry>(original_node->entry);
        while (original_node->next != NULL)
        {
            original_node = original_node->next;
            new_copy->next = new Node<List_entry>(original_node->entry);
            new_copy = new_copy->next;
        }
    }
}

/** Operator =
 *  @details This function assigns the list to another list
 */
template <class List_entry>void LinkedList<List_entry>::operator=(const LinkedList<List_entry> &original)
{
    Node<List_entry> *new_head,*new_copy, *original_node = original.head;
    if (original_node == NULL) head = NULL;
    else
    {
        new_copy = new_head = new Node<List_entry>(original_node->entry);
        while (original_node->next != NULL)
        {
            original_node = original_node->next;
            new_copy->next = new Node<List_entry>(original_node->entry);
            new_copy = new_copy->next;
        }
    }
    clear();
    head = new_head;
}


#endif //TELDIRECTORY_LINKEDLIST_H


