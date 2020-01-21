#pragma once

#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <iostream>
#include "node.hpp"

template<class T>
class DLL{
private:
    Node<T> *head;          // the pointer to the front of the list
    Node<T> *tail;          // the pointer to the back of the list
    int count;
public:
    // desc: Inializes a new, empty list
	DLL();

    // desc:  Adds new data to the begining of the list
    // param: data The data to add to the list
	void prepend(T &data);

    // desc:  Adds new data to the end of the list
    // param: data The data to add to the list
	void append(T &data);   

    // desc:    Searches the list for the node that contains data and removes it
    //          from the list
    // param:   data The data to be searched for and removed
    // returns: true if the node was found and removed, false if not
    bool remove(T data); 

    // desc:    Removes the node at the front of the list
    // returns: true if the node was successfully removed, false if not
	bool removeFront(void);

    // desc:    Removes the node at the back of the list
    // returns: true if the node was successfully removed, false if not
	bool removeBack(void);

    // desc:    Searches the list for a node containing the specified data
    // param:   data The data to be searched for
    // returns: A pointer to the node containing the data or NULL if a node
    //          cannot be found
	Node<T> *search(T data);

    // desc::   Returns the data found at the front of the list
    // returns: The data at the front of the list
    T getFront(void);

    // desc::   Returns the data found at the back of the list
    // returns: The data at the back of the list. Return 0 if empty
    T getBack(void);

    // desc: Prints the contents of the list from front to back
	void print();
};


template<class T>
DLL<T>::DLL()
{
	head = NULL;
    tail = NULL;
    count = 0;
}

template<class T>
void DLL<T>::prepend(T &data)
{
    // create a new node
    Node<T> *new_node = new Node<T>(data);

    // check to see if head is null, point head and tail to the new node
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else // otherwise the list is not empty so we tied them together
    {
        new_node->set_next(head);
        head = new_node;
    }

    return;
}

template<class T>
void DLL<T>::append(T &data)
{
    // create a new node
    Node<T> *new_node = new Node<T>(data);

    // check to see if head is null, point head and tail to the new node
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else // otherwise the list is not empty so we tied them together
    {
        tail->set_next(new_node);
        new_node->set_prev(tail);
        tail = new_node;
    }
    return;
}

template<class T>
bool DLL<T>::removeFront()
{
    // create a pointer
    Node<T> *itr;

    // check to see if the list is empty
    if (head == NULL)
    {
        return false;
    }
    else
    {
        itr = head;
        head = head->get_next();

        // check to see if head is NULL, then set tail to NULL
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->set_prev(NULL);
        }
        
        delete(itr);
    }
    
    return true;
}

template<class T>
bool DLL<T>::removeBack()
{
    return false;
}

template<class T>
Node<T> *DLL<T>::search(T target)
{
    return NULL;
}

template<class T>
void DLL<T>::print()
{
    Node<T> *itr = head;

    std::cout << "Your List: ";
	while (itr != NULL)
	{
        std::cout << itr->get_data() << " -> ";
        itr = itr->get_next();
	}
    std::cout << "NULL" << std::endl;
}

template<class T>
bool DLL<T>::remove(T target)
{
    return false;
}

template<class T>
T DLL<T>::getFront(void)
{
    // check if list is empty then return zero, otherwise return head(data)
    if (head == NULL)
    {
        return 0;
    }
    else 
    {
        return head->get_data();
    }
}

template<class T>
T DLL<T>::getBack(void)
{
    // check if list is empty then return zero, otherwise return tail(data)
    if (tail == NULL)
    {
        return 0;
    }
    else 
    {
        return tail->get_data();
    }
    
}
