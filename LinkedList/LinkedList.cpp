//
// Created by Karzanov Alexey on 25.04.2024.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

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
            cout << temp->entry << "  ";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}



// ------- Safeguards ----------
/*
template <class List_entry> LinkedList<List_entry>::~List()
{
    Node<List_entry> *tmp;


    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}


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

template <class List_entry> void LinkedList<List_entry>::operator=(const LinkedList<List_entry> &original)
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


*/