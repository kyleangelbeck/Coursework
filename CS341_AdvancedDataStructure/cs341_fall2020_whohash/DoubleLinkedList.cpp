// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "DoubleLinkedList.h"
#include <iostream>

// Call LinkedList constructor to set head_ and tail_ to be nullptr
DoubleLinkedList::DoubleLinkedList() : LinkedList() {}
DoubleLinkedList::~DoubleLinkedList() {}

void DoubleLinkedList::insertNode(int key, int value) {
    LinkedNode * n = new LinkedNode(key, value);

    // If the LL is empty, then the head and tail will be set to new node
    // Else, Append node after tail and set tail to be new node.
    if(LinkedList::isEmpty()) {
        head_ = n;
        tail_ = n;
    } else {
        tail_->setNext(n);
        n->setPrev(tail_);
        tail_ = n;
    }
}

void DoubleLinkedList::printList() {
    LinkedNode * currentNode = head_;

    while(currentNode != nullptr) {
        std::cout << currentNode->getKey();
        if(currentNode->getNext() != nullptr) std::cout << " <--> ";
        currentNode = currentNode->getNext();
    }
}
