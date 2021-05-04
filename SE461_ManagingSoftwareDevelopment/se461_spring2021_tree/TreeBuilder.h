// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#ifndef TREEBUILDER_H
#define TREEBUILDER_H

#include "Node.h"

#include <string>       //std::string

class TreeBuilder {
    public:
        // Destructor
        virtual ~TreeBuilder() {}

        // Build the tree
        virtual Node * buildTree(std::string rawInput) = 0;

    protected:
        // Protected Default Constructor
        TreeBuilder() {}
};

#endif
