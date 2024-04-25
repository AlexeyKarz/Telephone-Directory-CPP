//
// Created by Karzanov Alexey on 25.04.2024.
//

#ifndef TELDIRECTORY_LINKEDLIST_H
#define TELDIRECTORY_LINKEDLIST_H
#include "Node.h"


template <class List_entry> class LinkedList {
public:
    LinkedList();
    void clear();
    bool empty() const;
    int size() const;
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
