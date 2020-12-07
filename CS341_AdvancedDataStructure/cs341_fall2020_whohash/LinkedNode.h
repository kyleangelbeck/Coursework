// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "HashEntry.h"

// Header File for LinkedNode class.
class LinkedNode : public HashEntry
{
    // Public Constructors/Destructors/Member Methods
    public:
        /**
        * Constructor
        * takes in the next node and the previous node, as well as this node's data
        */
		LinkedNode(int key, int value);
		// destructor
		virtual ~LinkedNode();

        /**
        * Getter for the next node
        * @return LinkedNode
        */
        virtual LinkedNode * getNext();
        /**
        * Setter for the next node
        */
        virtual void setNext(LinkedNode * n);
        /**
        * Getter for the previous node
        * @return LinkedNode
        */
        virtual LinkedNode * getPrev();
        /**
        * Setter for the next node
        */
        virtual void setPrev(LinkedNode * n);
    private:
       // private attributes
       LinkedNode * nextNode_;
       LinkedNode * prevNode_;
    protected:
        // attempt to prevent creating a blank linkednode
        LinkedNode();
};

#endif
