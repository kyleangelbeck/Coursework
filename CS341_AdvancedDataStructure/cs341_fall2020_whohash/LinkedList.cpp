// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
}

LinkedList::~LinkedList() {
    LinkedNode * next = head_;
    // LinkedNode deconstructor will handle pointer rearrangement
    while(next != nullptr){
        LinkedNode * toDelete = next;
        next = next->getNext();
        delete toDelete;
    }
    delete next;

}

int LinkedList::search(int key) {
    LinkedNode * head = head_;

    while(head != nullptr) {
        if(head->getKey() == key) {
            return head->getValue();
        }
        head = head->getNext();
    }

    return -1;
}

void LinkedList::insert(int key, int value) {
    LinkedNode * n = new LinkedNode(key, value);
    // If the LinkedList is empty, then the head and tail should be the new node.
    // Else, set the tail's next pointer to the new node and set tail_ to the new node.
    if(isEmpty()) {
        head_ = n;
        tail_ = n;
    } else {
        tail_->setNext(n);
        tail_ = n;
    }
}

void LinkedList::remove(int key) {
    LinkedNode * head = head_;

    while(head != nullptr) {
        if(head->getKey() == key) {
            // If we are deleting the head of the linked list, update head_
            if(head == head_) head_=head->getNext();
            // delete head should deal with pointers
            delete head;
            std::cout << "Key " << key << " removed." << std::endl;
            return;
        }
        head = head->getNext();
    }

    std::cout << "Key " << key << " not found." << std::endl;
}

int LinkedList::getLength() {
    int length(0);
    LinkedNode * temp = head_;

    while(temp != nullptr) {
        length++;
        temp = temp->getNext();
    }

    return length;
}

bool LinkedList::isEmpty() {
    return getLength() == 0;
}


void LinkedList::printList() {
    LinkedNode * currentNode = head_;

    while(currentNode != nullptr) {
        std::cout << currentNode->getKey();
        if(currentNode->getNext() != nullptr) std::cout << " --> ";
        currentNode = currentNode->getNext();
    }
}

LinkedNode * LinkedList::getHead() { return head_; }
LinkedNode * LinkedList::getTail() { return tail_; }

void LinkedList::setHead(LinkedNode * head) { head_ = head; }
void LinkedList::setTail(LinkedNode * tail) { tail_ = tail; }
