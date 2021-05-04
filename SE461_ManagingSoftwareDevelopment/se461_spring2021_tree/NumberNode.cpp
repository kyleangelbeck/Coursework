// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "NumberNode.h"

NumberNode::NumberNode(int value) : Node(), value_(value) {}

void NumberNode::Accept(TreeVisitor & v) {
    v.visitNumberNode(*this);
}

int NumberNode::getValue() {
    return value_;
}

NodeType NumberNode::getNodeType() {
    return NUMBER;
}
