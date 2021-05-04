// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef DIVISIONNODE_H
#define DIVISIONNODE_H

#include "Node.h"

class DivisionNode : public Node {

    public:
        // Constructor
        DivisionNode();
        // Destructor
        virtual ~DivisionNode() {}

        // Accept Visitor
        virtual void Accept(TreeVisitor & v);

        // Node Type
        virtual NodeType getNodeType();
};

#endif
