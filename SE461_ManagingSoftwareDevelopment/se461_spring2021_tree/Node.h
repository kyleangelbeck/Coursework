// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef NODE_H
#define NODE_H

class TreeVisitor;

enum NodeType { BINARYOPERATOR, NUMBER };

class Node {
    public:
        // Destructor
        virtual ~Node();

        // Accept Visitor
        virtual void Accept(TreeVisitor & v) = 0;

        // Getters
        Node * getLeftChild();
        Node * getRightChild();
        Node * getParent();

        // Setters
        void setLeftChild(Node * n);
        void setRightChild(Node * n);
        void setParent(Node * n);

        // Node Type
        //TODO: Could move precedence into this class and combine it with this.
        virtual NodeType getNodeType() = 0;

    protected:
        // Non-Public Default Constructor
        Node();

        // Protected Tree Pointers
        Node * parent_;
        Node * leftChild_;
        Node * rightChild_;
};

#include "TreeVisitor.h"

#endif
