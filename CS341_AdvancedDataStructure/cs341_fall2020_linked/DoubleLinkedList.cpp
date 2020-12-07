// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "DoubleLinkedList.h"

// Call LinkedList constructor to set head_ and tail_ to be nullptr
template <class T>
DoubleLinkedList<T>::DoubleLinkedList() : LinkedList<T>() {}
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {}

// this-> is needed for weird template reasons ¯\_(ツ)_/¯
template <class T>
void DoubleLinkedList<T>::insertNode(T data) {
    LinkedNode<T> * n = new LinkedNode<T>(data, nullptr, nullptr);

    // If the LL is empty, then the head and tail will be set to new node
    // Else, Append node after tail and set tail to be new node.
    if(this->isEmpty()) {
        this->head_ = n;
        this->tail_ = n;
    } else {
        this->tail_->setNext(n);
        n->setPrev(this->tail_);
        this->tail_ = n;
    }
}

template <class T>
void DoubleLinkedList<T>::insertAfter(LinkedNode<T> * node, T data) {
    LinkedNode<T> * n = new LinkedNode<T>(data, nullptr, nullptr);

    // Set new node next and prev
    n->setPrev(node);
    n->setNext(node->getNext());

    // Set adjacent nodes to point to new node
    node->setNext(n);
    // If old node is tail, set tail to be new node, Else
    // Set n->next->prev to be new node
    if(n->getNext() == nullptr) {
        this->tail_ = n;
    } else {
        n->getNext()->setPrev(n);
    }
}

template <class T>
void DoubleLinkedList<T>::insertBefore(LinkedNode<T> * node, T data) {
    LinkedNode<T> * n = new LinkedNode<T>(data, nullptr, nullptr);

    // Set new node next and prev
    n->setNext(node);
    n->setPrev(node->getPrev());

    // Set adjacent nodes to point to new node
    node->setPrev(n);
    // If old node is head, set head to be new node, Else
    // Set n->prev->next to be new node
    if(n->getPrev() == nullptr) {
        this->head_ = n;
    } else {
        n->getPrev()->setNext(n);
    }
}
