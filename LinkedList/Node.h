//
// Created by Karzanov Alexey on 25.04.2024.
//

#ifndef TELDIRECTORY_NODE_H
#define TELDIRECTORY_NODE_H



template <class Node_entry> class Node {
public:
    // data members
    Node_entry entry;
    Node<Node_entry> *next;
    // constructors
    Node();
    Node(Node_entry item, Node<Node_entry> *link = nullptr);
};

/* Since Node is a template class, I have to include the implementation in the header file.
 * Otherwise, I will get a linker error
 */

template <class Node_entry> Node<Node_entry>::Node()
{
    next = nullptr;
}

template <class Node_entry> Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *add_on)
{
    entry = item;
    next = add_on;
}

#endif //TELDIRECTORY_NODE_H
