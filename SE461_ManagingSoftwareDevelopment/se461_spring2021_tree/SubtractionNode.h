// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef SUBTRACTIONNODE_H
#define SUBTRACTIONNODE_H

#include "Node.h"

class SubtractionNode : public Node {
    public:
        // Constructor
        SubtractionNode();
        // Destructor
        virtual ~SubtractionNode() {}
        
        // Accept Visitor
        virtual void Accept(TreeVisitor & v);

        // Node Type
        virtual NodeType getNodeType();
};

#endif
