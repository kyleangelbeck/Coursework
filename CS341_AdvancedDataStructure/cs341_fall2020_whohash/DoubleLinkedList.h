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
class DoubleLinkedList : public LinkedList
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
        virtual void insertNode(int key, int value);

        /**
         * Prints DoubleLinkedList
         */
        virtual void printList();
};

#endif
