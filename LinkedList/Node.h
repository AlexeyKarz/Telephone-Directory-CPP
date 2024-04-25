//
// Created by Karzanov Alexey on 25.04.2024.
//

#ifndef TELDIRECTORY_NODE_H
#define TELDIRECTORY_NODE_H


enum Error_code {success,overflow,underflow,not_found};

template <class Node_entry> class Node {
public:
    // data members
    Node_entry entry;
    Node<Node_entry> *next;
    // constructors
    Node();
    Node(Node_entry item, Node<Node_entry> *link = nullptr);
};



#endif //TELDIRECTORY_NODE_H
