// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "LinkedList.h"

// Header File for Insertion class.
template <class T>
class DoubleLinkedList : public LinkedList<T>
{
    // Public Constructors/Destructors/Member Methods
    public:
        // Constructor
		DoubleLinkedList();

        // Destructor
		virtual ~DoubleLinkedList();


        /**
        * Inserts a LinkedNode into the Doubly Linked List.
        *
        * @param[in] LinkedNode * Existing LinkedNode
        * @param[in] Integer Data Element
        */
        virtual void insertNode(T data);

        /**
        * Inserts a new LinkedNode after an existing LinkedNode in
        * the Doubly Linked List.
        *
        * @param[in] LinkedNode * Existing LinkedNode
        * @param[in] Integer Data Element
        */        
        void insertAfter(LinkedNode<T> * node, T data);

        /**
        * Inserts a new LinkedNode before an existing LinkedNode in
        * the Doubly Linked List.
        *
        * @param[in] LinkedNode * Existing LinkedNode
        * @param[in] Integer Data Element
        */
        void insertBefore(LinkedNode<T> * node, T data);
};

#endif
