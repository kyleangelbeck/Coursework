// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "LinkedList.h"
#include <iostream>

template <class T>
LinkedList<T>::LinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    LinkedNode<T> * next = head_;
    // LinkedNode deconstructor will handle pointer rearrangement
    while(next != nullptr){
        LinkedNode<T> * toDelete = next;
        next = next->getNext();
        delete toDelete;
    }
    delete next;

}

template <class T>
void LinkedList<T>::insert(T element) {
    LinkedNode<T> * n = new LinkedNode<T>(element, nullptr, nullptr);
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

template <class T>
int LinkedList<T>::getLength() {
    int length(0);
    LinkedNode<T> * temp = head_;

    while(temp != nullptr) {
        length++;
        temp = temp->getNext();
    }

    return length;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return getLength() == 0;
}


template <class T>
void LinkedList<T>::printList() {
    LinkedNode<T> * currentNode = head_;

    while(currentNode != nullptr) {
        std::cout << currentNode->getData() << " ";
        currentNode = currentNode->getNext();
    }
}

template <class T>
std::string LinkedList<T>::getString() {
    LinkedNode<T> * currentNode = head_;
    std::string someName = "";

    while(currentNode != nullptr) {
        someName += std::to_string(currentNode->getData());
        someName += " ";
        currentNode = currentNode->getNext();
    }

    return someName;
}

template <class T>
LinkedNode<T> * LinkedList<T>::getHead() { return head_; }
template <class T>
LinkedNode<T> * LinkedList<T>::getTail() { return tail_; }

template <class T>
void LinkedList<T>::setHead(LinkedNode<T> * head) { head_ = head; }
template <class T>
void LinkedList<T>::setTail(LinkedNode<T> * tail) { tail_ = tail; }
