// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

// Header File for LinkedNode class.
template <class T>
class LinkedNode : public Node<T>
{
    // Public Constructors/Destructors/Member Methods
    public:
        /**
        * Constructor
        * takes in the next node and the previous node, as well as this node's data
        */
		LinkedNode(T data, LinkedNode<T> * nextNode, LinkedNode<T> * prevNode);
		// destructor
		virtual ~LinkedNode();

        /**
        * Getter for the next node
        * @return LinkedNode
        */
        virtual LinkedNode<T> * getNext();
        /**
        * Setter for the next node
        */
        virtual void setNext(LinkedNode<T> * n);
        /**
        * Getter for the previous node
        * @return LinkedNode
        */
        virtual LinkedNode<T> * getPrev();
        /**
        * Setter for the next node
        */
        virtual void setPrev(LinkedNode<T> * n);
    private:
       // private attributes
       LinkedNode<T> * nextNode_;
       LinkedNode<T> * prevNode_;
    protected:
        // attempt to prevent creating a blank linkednode
        LinkedNode();
};

#endif
