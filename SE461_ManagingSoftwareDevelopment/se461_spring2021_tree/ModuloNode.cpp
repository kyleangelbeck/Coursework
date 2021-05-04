// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "ModuloNode.h"

ModuloNode::ModuloNode() : Node() {}

void ModuloNode::Accept(TreeVisitor & v) {
    v.visitModuloNode(*this);
}

NodeType ModuloNode::getNodeType() {
    return BINARYOPERATOR;
}
