// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include <cstddef>      // NULL
#include "LinkedNode.h"

// constructor and destructor
LinkedNode::LinkedNode(int key, int value) : HashEntry(key, value), nextNode_(nullptr), prevNode_(nullptr) {}
LinkedNode::LinkedNode() : HashEntry(), nextNode_(nullptr), prevNode_(nullptr) {}

LinkedNode::~LinkedNode(){
    if (prevNode_!=NULL){
        prevNode_->setNext(nextNode_);
    }
    if (nextNode_!=NULL){
        nextNode_->setPrev(prevNode_);
    }
}

// getters and setters
LinkedNode * LinkedNode::getNext() { return nextNode_; }
void LinkedNode::setNext(LinkedNode * nextNode) { nextNode_ = nextNode; }

LinkedNode * LinkedNode::getPrev() { return prevNode_; }
void LinkedNode::setPrev(LinkedNode * prevNode) { prevNode_ = prevNode; }
