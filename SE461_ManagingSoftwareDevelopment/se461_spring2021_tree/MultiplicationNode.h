// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef MULTIPLICATIONNODE_H
#define MULTIPLICATIONNODE_H

#include "Node.h"

class MultiplicationNode : public Node {
    public:
        // Constructor
        MultiplicationNode();
        // Destructor
        virtual ~MultiplicationNode() {}

        // Accept Visitor
        virtual void Accept(TreeVisitor & v);

        // Node Type
        virtual NodeType getNodeType();
};

#endif
