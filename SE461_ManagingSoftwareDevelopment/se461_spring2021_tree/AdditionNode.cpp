// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "AdditionNode.h"

AdditionNode::AdditionNode() : Node() {}

void AdditionNode::Accept(TreeVisitor & v) {
    v.visitAdditionNode(*this);
}

NodeType AdditionNode::getNodeType() {
    return BINARYOPERATOR;
}
