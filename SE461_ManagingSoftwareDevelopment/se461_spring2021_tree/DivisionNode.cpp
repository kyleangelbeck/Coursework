// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "DivisionNode.h"

DivisionNode::DivisionNode() : Node() {}

void DivisionNode::Accept(TreeVisitor & v) {
    v.visitDivisionNode(*this);
}

NodeType DivisionNode::getNodeType() {
    return BINARYOPERATOR;
}
