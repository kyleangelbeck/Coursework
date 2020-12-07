// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include <cstddef>      // NULL
#include "Node.h"

Node::Node(int data) : data_(data) {}
Node::Node() : data_(0) {}
Node::~Node() {}

int Node::getData() { return data_; }
void Node::setData(int data) { data_ = data; }
