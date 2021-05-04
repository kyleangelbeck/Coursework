// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include "Node.h"

Node::Node() : parent_(nullptr), leftChild_(nullptr), rightChild_(nullptr) {}

// Recursively delete children.
// This deletes the entire subtree with this node as the root.
Node::~Node() {
    delete leftChild_;
    delete rightChild_;
}

Node * Node::getLeftChild() {
    return leftChild_;
}

Node * Node::getRightChild() {
    return rightChild_;
}

Node * Node::getParent() {
    return parent_;
}

void Node::setLeftChild(Node * n) {
    leftChild_ = n;
}

void Node::setRightChild(Node * n) {
    rightChild_ = n;
}

void Node::setParent(Node * n) {
    parent_ = n;
}
