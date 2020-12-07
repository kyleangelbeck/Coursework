// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "List.h"
#include "LinkedNode.h"

// Header File for Insertion class.
class LinkedList : public List
{
    // Protected Attributes
    protected:
        LinkedNode * head_;
        LinkedNode * tail_;

    public:
        // Constructor
		LinkedList();
        // Destructor
		virtual ~LinkedList();

        /**
         * Search the list for a given key
         * @param int
         */
        virtual int search(int key);

        /**
        * Assignment operation
        *
        * @param[in] element Data Element (Integer)
        */
        virtual void insert(int key, int value);

        /**
        * Deletion operation
        *
        * @param[in] key of hash to be removed
        */
        virtual void remove(int key);

        /**
        * Gets the length of the List.
        *
        * @return Integer
        */
        virtual int getLength();

        /**
        * Check to see if the List is empty.
        *
        * @return T/F
        */
        virtual bool isEmpty();

        /**
         * Prints LinkedList
         */
        virtual void printList();

        /**
         * Getter of LinkedNode's head
         * @return LinkedNode
         */
        virtual LinkedNode * getHead();

        /**
         * Getter of LinkedNode's tail
         * @return LinkedNode
         */
        virtual LinkedNode * getTail();

        /**
         * Setter of LinkedNode's head
         * @param LinkedNode
         */
        virtual void setHead(LinkedNode * head);

        /**
         * Setter of LinkedNode's tail
         * @param LinkedNode
         */
        virtual void setTail(LinkedNode * tail);
};

#endif
