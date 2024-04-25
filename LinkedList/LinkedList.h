//
// Created by Karzanov Alexey on 25.04.2024.
//

#ifndef TELDIRECTORY_LINKEDLIST_H
#define TELDIRECTORY_LINKEDLIST_H
#include "Node.h"

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

#endif //TELDIRECTORY_LINKEDLIST_H


