// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef MODULONODE_H
#define MODULONODE_H

#include "Node.h"

class ModuloNode : public Node {
    public:
        // Constructor
        ModuloNode();
        // Destructor
        virtual ~ModuloNode() {}
        
        // Accept Visitor
        virtual void Accept(TreeVisitor & v);

        // Node Type
        virtual NodeType getNodeType();
};

#endif
