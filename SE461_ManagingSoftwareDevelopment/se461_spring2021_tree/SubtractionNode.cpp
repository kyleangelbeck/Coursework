// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "SubtractionNode.h"

SubtractionNode::SubtractionNode() : Node() {}

void SubtractionNode::Accept(TreeVisitor & v) {
    v.visitSubtractionNode(*this);
}

NodeType SubtractionNode::getNodeType() {
    return BINARYOPERATOR;
}
