// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include "LinkedNode.h"
#include <string>

// Header File for Insertion class.
template <class T>
class LinkedList : public List<T>
{
    // Protected Attributes
    protected:
        LinkedNode<T> * head_;
        LinkedNode<T> * tail_;
    // Public Constructors/Destructors/Member Methods
    public:
		LinkedList();
		virtual ~LinkedList();
        virtual void insert(T element);
        virtual int getLength();
        virtual bool isEmpty();
        virtual void printList();
        virtual LinkedNode<T> * getHead();
        virtual LinkedNode<T> * getTail();
        virtual void setHead(LinkedNode<T> * head);
        virtual void setTail(LinkedNode<T> * tail);
        virtual std::string getString();
};

#endif
