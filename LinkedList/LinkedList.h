//
// Created by Karzanov Alexey on 25.04.2024.
//

#ifndef TELDIRECTORY_LINKEDLIST_H
#define TELDIRECTORY_LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

enum Error_code {success,overflow,underflow,not_found};

template <class List_entry> class LinkedList {
public:
    LinkedList();
    void clear();
    bool empty() const;
    int size() const;
    Node<List_entry>* get_head() const;
    Error_code retrieve(int position, List_entry &x) const;
    Error_code remove(const List_entry &item);
    Error_code insert(const List_entry &item);
    void print() const;
//    // Safequards
//    ~LinkedList();
//    LinkedList(const LinkedList<List_entry> &copy);
//    void operator = (const LinkedList<List_entry> &original);
protected:
    Node<List_entry> *head;
};

/* Since LinkedList is a template class, I have to include the implementation in the header file.
 * Otherwise, I will get a linker error
 */

template <class List_entry> LinkedList<List_entry>::LinkedList()
{
    head = nullptr;
}

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

template <class List_entry> bool LinkedList<List_entry>::empty() const
{
    return head == nullptr;
}

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

template <class List_entry> Node<List_entry>* LinkedList<List_entry>::get_head() const {
    return head;
}

template <class List_entry> Error_code LinkedList<List_entry>::insert(const List_entry &item)
{
    Node<List_entry> *new_entry = new Node<List_entry>(item);

    if (new_entry == nullptr) return overflow;   // IF FULL

    else if (empty())
        head = new_entry;
    else if (item < head->entry)
    {
        new_entry->next = head;
        head = new_entry;
    }
    else
    {
        Node<List_entry> *previous = head, *current = head->next;

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

template <class List_entry> Error_code LinkedList<List_entry>::remove(const List_entry &item)
{
    Node<List_entry> *current = head;
    if (empty()) return underflow;
    if (item < head->entry) return not_found;
    if (item == head->entry)
    {
        head = head->next;
        delete current;
        return success;
    }
    Node<List_entry> *previous = current;
    current = current->next;
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


template <class List_entry> void LinkedList<List_entry>::print() const
{
    if (empty())
        cout << "Empty List" << endl;
    else {
        Node<List_entry> *temp = head;
        while (temp != NULL) {
            temp->entry.print();
            temp = temp->next;
        }
    }
    cout << endl << endl;
}



#endif //TELDIRECTORY_LINKEDLIST_H


