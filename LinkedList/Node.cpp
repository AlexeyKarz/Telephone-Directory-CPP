//
// Created by Karzanov Alexey on 25.04.2024.
//

#include "Node.h"

template <class Node_entry> Node<Node_entry>::Node()
{
    next = nullptr;
}

template <class Node_entry> Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *add_on)
{
    entry = item;
    next = add_on;
}