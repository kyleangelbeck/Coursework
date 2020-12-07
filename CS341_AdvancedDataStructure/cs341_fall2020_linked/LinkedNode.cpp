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
template <class T>
LinkedNode<T>::LinkedNode(T data, LinkedNode<T> * nextNode, LinkedNode<T> * prevNode) : Node<T>(data), nextNode_(nextNode), prevNode_(prevNode) {}
template <class T>
LinkedNode<T>::LinkedNode() : Node<T>(), nextNode_(nullptr), prevNode_(nullptr) {}

template <class T>
LinkedNode<T>::~LinkedNode(){
    if (prevNode_!=NULL){
        prevNode_->setNext(nextNode_);
    }
    if (nextNode_!=NULL){
        nextNode_->setPrev(prevNode_);
    }
}

// getters and setters
template <class T>
LinkedNode<T> * LinkedNode<T>::getNext() { return nextNode_; }
template <class T>
void LinkedNode<T>::setNext(LinkedNode<T> * nextNode) { nextNode_ = nextNode; }

template <class T>
LinkedNode<T> * LinkedNode<T>::getPrev() { return prevNode_; }
template <class T>
void LinkedNode<T>::setPrev(LinkedNode<T> * prevNode) { prevNode_ = prevNode; }
