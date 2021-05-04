// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "MultiplicationNode.h"

MultiplicationNode::MultiplicationNode() : Node() {}

void MultiplicationNode::Accept(TreeVisitor & v) {
    v.visitMultiplicationNode(*this);
}

NodeType MultiplicationNode::getNodeType() {
    return BINARYOPERATOR;
}
