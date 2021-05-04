// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "Node.h"

class NumberNode : public Node {
    public:
        // Constructor
        NumberNode(int value);
        // Destructor
        virtual ~NumberNode() {}

        // Accept Visitor
        virtual void Accept(TreeVisitor & v);

        // Node Type
        virtual NodeType getNodeType();

        int getValue();
    
    private:
        // Non-Public Default Constructor
        NumberNode() {}
        // Value of this number
        int value_;
};

#endif
