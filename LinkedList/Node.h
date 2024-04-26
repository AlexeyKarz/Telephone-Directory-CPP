/** \file Node.h
 *  \brief Declaration of the Node class.
 *  \author Aleksei Karzanov
 *  \version 1.0
 *  \date 26.04.2024
 *  \since 1.0
 */

#ifndef TELDIRECTORY_NODE_H
#define TELDIRECTORY_NODE_H

/** Node class represents a node in a linked list
 * @tparam Node_entry
 */
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

// Constructor
template <class Node_entry> Node<Node_entry>::Node()
{
    next = nullptr;
}

// Constructor with parameters
template <class Node_entry> Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *add_on)
{
    entry = item;
    next = add_on;
}

#endif //TELDIRECTORY_NODE_H
