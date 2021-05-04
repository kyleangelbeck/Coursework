// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef ADDITIONNODE_H
#define ADDITIONNODE_H

#include "Node.h"

class AdditionNode : public Node {
    public:
        // Constructor
        AdditionNode();
        // Destructor
        virtual ~AdditionNode() {}

        // Accept Visitor
        virtual void Accept(TreeVisitor & v);

        // Node Type
        virtual NodeType getNodeType();
};

#endif
